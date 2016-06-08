#include <algorithm>
#include <iostream>
#include <sstream>

#include "../../../Tools/Reorderer/Reorderer.hpp"

#include "../../../Tools/Polar/Pattern_parser_polar.hpp"
#include "../../../Tools/MIPP/mipp.h"
#include "../../../Tools/Transpose/transpose_selector.h"
#include "../../../Tools/bash_tools.h"

#include "Patterns/Pattern_SC_standard.hpp"
#include "Patterns/Pattern_SC_rate0.hpp"
#include "Patterns/Pattern_SC_rate1.hpp"
#include "Patterns/Pattern_SC_rep.hpp"
#include "Patterns/Pattern_SC_spc.hpp"
#include "Patterns/Pattern_SC_rate0_left.hpp"
#include "Patterns/Pattern_SC_rep_left.hpp"

#include "Decoder_polar_SC_fast_sys.hpp"

constexpr int static_level = 6; // 2^6 = 64

template <typename B, typename R, class API_polar, int REV_D>
struct Decoder_polar_SC_fast_sys_static
{
	static void decode(std::vector<char> &pattern_types_per_id, mipp::vector<B> &s, mipp::vector<R> &l, 
	                   const int off_l, const int off_s, int &id)
	{
		constexpr int reverse_depth = REV_D;
		constexpr int n_elmts = 1 << reverse_depth;
		constexpr int n_elm_2 = n_elmts >> 1;

		const int my_id = id;
		const pattern_SC_type my_pattern_type = (pattern_SC_type)pattern_types_per_id[my_id];

		const bool is_terminal_pattern = (my_pattern_type == pattern_SC_type::RATE_0) ||
		                                 (my_pattern_type == pattern_SC_type::RATE_1) ||
		                                 (my_pattern_type == pattern_SC_type::REP)    ||
		                                 (my_pattern_type == pattern_SC_type::SPC);

		if (!is_terminal_pattern && reverse_depth)
		{
			// f
			switch (my_pattern_type)
			{
				case STANDARD: API_polar::template f<n_elm_2>(l, off_l, off_l + n_elm_2, off_l + n_elmts, n_elm_2); break;
				case REP_LEFT: API_polar::template f<n_elm_2>(l, off_l, off_l + n_elm_2, off_l + n_elmts, n_elm_2); break;
				default:
					break;
			}

			Decoder_polar_SC_fast_sys_static<B,R,API_polar,REV_D-1>
			::decode(pattern_types_per_id, s, l, off_l + n_elmts, off_s, ++id); // recursive call left

			// g
			switch (my_pattern_type)
			{
				case STANDARD:    API_polar::template g <n_elm_2>(s, l, off_l, off_l + n_elm_2, off_s, off_l + n_elmts, n_elm_2); break;
				case RATE_0_LEFT: API_polar::template g0<n_elm_2>(   l, off_l, off_l + n_elm_2,        off_l + n_elmts, n_elm_2); break;
				case REP_LEFT:    API_polar::template gr<n_elm_2>(s, l, off_l, off_l + n_elm_2, off_s, off_l + n_elmts, n_elm_2); break;
				default:
					break;
			}

			Decoder_polar_SC_fast_sys_static<B,R,API_polar,REV_D-1>
			::decode(pattern_types_per_id, s, l, off_l + n_elmts, off_s + n_elm_2, ++id); // recursive call right

			// xor
			switch (my_pattern_type)
			{
				case STANDARD:    API_polar::template xo <n_elm_2>(s, off_s, off_s + n_elm_2, off_s, n_elm_2); break;
				case RATE_0_LEFT: API_polar::template xo0<n_elm_2>(s,        off_s + n_elm_2, off_s, n_elm_2); break;
				case REP_LEFT:    API_polar::template xo <n_elm_2>(s, off_s, off_s + n_elm_2, off_s, n_elm_2); break;
				default:
					break;
			}
		}
		else
		{
			// h
			switch (my_pattern_type)
			{
				case RATE_1: API_polar::template h  <n_elmts>(s, l, off_l, off_s, n_elmts); break;
				case REP:    API_polar::template rep<n_elmts>(s, l, off_l, off_s, n_elmts); break;
				case SPC:    API_polar::template spc<n_elmts>(s, l, off_l, off_s, n_elmts); break;
				default:
					break;
			}
		}
	}
};

template <typename B, typename R, class API_polar>
struct Decoder_polar_SC_fast_sys_static<B,R,API_polar,0>
{
	static void decode(std::vector<char> &pattern_types_per_id, mipp::vector<B> &s, mipp::vector<R> &l, 
	                   const int off_l, const int off_s, int &id)
	{
		constexpr int reverse_depth = 0;
		constexpr int n_elmts = 1 << reverse_depth;

		const int my_id = id;
		const pattern_SC_type my_pattern_type = (pattern_SC_type)pattern_types_per_id[my_id];

		switch (my_pattern_type)
		{
			case RATE_1: API_polar::template h<n_elmts>(s, l, off_l, off_s, n_elmts); break;
			default:
				break;
		}
	}
};

template <typename B, typename R, class API_polar>
Decoder_polar_SC_fast_sys<B,R,API_polar>
::Decoder_polar_SC_fast_sys(const int& N, const mipp::vector<B>& frozen_bits)
: N(N),
  m(log2(N)),
  n_frames(API_polar::get_n_frames()),
  l(2 * N * n_frames + mipp::nElmtsPerRegister<R>()),
  s(1 * N * n_frames + mipp::nElmtsPerRegister<B>()),
  frozen_bits(frozen_bits)
{
	static_assert(sizeof(B) == sizeof(R), "");

	Pattern_SC_interface* pattern_SC_r0 = new Pattern_SC<pattern_SC_type::RATE_0>();
	Pattern_SC_interface* pattern_SC_r1 = new Pattern_SC<pattern_SC_type::RATE_1>();

	std::vector<Pattern_SC_interface*> patterns_SC;
	patterns_SC.push_back(new Pattern_SC<pattern_SC_type::STANDARD   >());
	patterns_SC.push_back(new Pattern_SC<pattern_SC_type::RATE_0_LEFT>());
	patterns_SC.push_back(pattern_SC_r0                                 );
	patterns_SC.push_back(pattern_SC_r1                                 );
	patterns_SC.push_back(new Pattern_SC<pattern_SC_type::REP_LEFT   >());
	patterns_SC.push_back(new Pattern_SC<pattern_SC_type::REP        >());
	patterns_SC.push_back(new Pattern_SC<pattern_SC_type::SPC        >());

	mipp::vector<int> fb_int32(N);
	for (unsigned i = 0; i < frozen_bits.size(); i++)
		fb_int32[i] = (int)frozen_bits[i];

	Pattern_parser_polar *parser = new Pattern_parser_polar(N, fb_int32, patterns_SC, *pattern_SC_r0, *pattern_SC_r1);
	pattern_types_per_id = parser->get_pattern_types_per_id();

	delete parser;
	for (unsigned i = 0; i < patterns_SC.size(); i++)
		delete patterns_SC[i];

	std::fill(s.begin(), s.end(), (B)0);
}

template <typename B, typename R, class API_polar>
Decoder_polar_SC_fast_sys<B,R,API_polar>
::~Decoder_polar_SC_fast_sys()
{
}

template <typename B, typename R, class API_polar>
void Decoder_polar_SC_fast_sys<B,R,API_polar>
::load(const mipp::vector<R>& Y_N)
{
	assert(Y_N.size() == (unsigned) (N * n_frames));

	constexpr int n_frames = API_polar::get_n_frames();

	if (n_frames == 1)
		std::copy(Y_N.begin(), Y_N.end(), l.begin());
	else
	{
		bool fast_interleave = false;
		if (typeid(B) == typeid(signed char))
			fast_interleave = char_transpose((signed char*)Y_N.data(), (signed char*)l.data(), (int)N);

		if (!fast_interleave)
		{
			std::vector<const R*> frames(n_frames);
			for (auto f = 0; f < n_frames; f++)
				frames[f] = Y_N.data() + f*N;
			Reorderer_static<R,n_frames>::apply(frames, l.data(), N);
		}
	}
}

template <typename B, typename R, class API_polar>
void Decoder_polar_SC_fast_sys<B,R,API_polar>
::decode()
{
	assert(m >= static_level);

	int first_id = 0, off_l = 0, off_s = 0;
	this->recursive_decode(off_l, off_s, m, first_id);
}

template <typename B, typename R, class API_polar>
void Decoder_polar_SC_fast_sys<B,R,API_polar>
::recursive_decode(const int off_l, const int off_s, const int reverse_depth, int &id)
{
	if (reverse_depth == static_level)
	{
		// use the static version of the decoder
		Decoder_polar_SC_fast_sys_static<B,R,API_polar,static_level>
		::decode(pattern_types_per_id, this->s, this->l, off_l, off_s, id);
	}
	else
	{
		const int n_elmts = 1 << reverse_depth;
		const int n_elm_2 = n_elmts >> 1;
		const int my_id = id;
		const pattern_SC_type my_pattern_type = (pattern_SC_type)pattern_types_per_id[my_id];

		const bool is_terminal_pattern = (my_pattern_type == pattern_SC_type::RATE_0) ||
		                                 (my_pattern_type == pattern_SC_type::RATE_1) ||
		                                 (my_pattern_type == pattern_SC_type::REP)    ||
		                                 (my_pattern_type == pattern_SC_type::SPC);

		if (!is_terminal_pattern && reverse_depth)
		{
			// f
			switch (my_pattern_type)
			{
				case STANDARD: API_polar::f(l, off_l, off_l + n_elm_2, off_l + n_elmts, n_elm_2); break;
				case REP_LEFT: API_polar::f(l, off_l, off_l + n_elm_2, off_l + n_elmts, n_elm_2); break;
				default:
					break;
			}

			this->recursive_decode(off_l + n_elmts, off_s, reverse_depth -1, ++id); // recursive call left

			// g
			switch (my_pattern_type)
			{
				case STANDARD:    API_polar::g (s, l, off_l, off_l + n_elm_2, off_s, off_l + n_elmts, n_elm_2); break;
				case RATE_0_LEFT: API_polar::g0(   l, off_l, off_l + n_elm_2,        off_l + n_elmts, n_elm_2); break;
				case REP_LEFT:    API_polar::gr(s, l, off_l, off_l + n_elm_2, off_s, off_l + n_elmts, n_elm_2); break;
				default:
					break;
			}

			this->recursive_decode(off_l + n_elmts, off_s + n_elm_2, reverse_depth -1, ++id); // recursive call right

			// xor
			switch (my_pattern_type)
			{
				case STANDARD:    API_polar::xo (s, off_s, off_s + n_elm_2, off_s, n_elm_2); break;
				case RATE_0_LEFT: API_polar::xo0(s,        off_s + n_elm_2, off_s, n_elm_2); break;
				case REP_LEFT:    API_polar::xo (s, off_s, off_s + n_elm_2, off_s, n_elm_2); break;
				default:
					break;
			}
		}
		else
		{
			// h
			switch (my_pattern_type)
			{
				case RATE_1: API_polar::h  (s, l, off_l, off_s, n_elmts); break;
				case REP:    API_polar::rep(s, l, off_l, off_s, n_elmts); break;
				case SPC:    API_polar::spc(s, l, off_l, off_s, n_elmts); break;
				default:
					break;
			}
		}
	}
}

template <typename B, typename R, class API_polar>
void Decoder_polar_SC_fast_sys<B,R,API_polar>
::store(mipp::vector<B>& V_N) const
{
	assert(V_N.size() == (unsigned) (N * n_frames));

	constexpr int n_frames = API_polar::get_n_frames();

	if (n_frames == 1)
		std::copy(s.begin(), s.end() - mipp::nElmtsPerRegister<B>(), V_N.begin());
	else
	{
		bool fast_deinterleave = false;
#if defined(ENABLE_BIT_PACKING)
		if (typeid(B) == typeid(signed char))
		{
			if (!(fast_deinterleave = char_itranspose((signed char*)s.data(), (signed char*)V_N.data(), (int)N)))
			{
				std::cerr << bold_red("(EE) Unsupported N value for itransposition ")
				          << bold_red("(N have to be greater or equal to 128 for SSE/NEON or to 256 for AVX).")
				          << std::endl;
				exit(-1);
			}
		}
#endif
		if (!fast_deinterleave)
		{
			// transpose without bit packing (vectorized)
			std::vector<B*> frames(n_frames);
			for (auto f = 0; f < n_frames; f++)
				frames[f] = V_N.data() + f*N;
			Reorderer_static<B,n_frames>::apply_rev(s.data(), frames, N);
		}
	}
}

template <typename B, typename R, class API_polar>
void Decoder_polar_SC_fast_sys<B,R,API_polar>
::unpack(mipp::vector<B>& V_N) const
{
	assert(V_N.size() == (unsigned) (N * n_frames));

	constexpr int n_frames = API_polar::get_n_frames();

	bool unpack = false;
#if defined(ENABLE_BIT_PACKING)
	if (typeid(B) == typeid(signed char) && n_frames == mipp::nElReg<R>())
	{
		// bit unpacking
		auto idx = n_frames * N -1;
		for (auto i = n_frames * N -1; i > 0; i -= N)
			for (unsigned j = (unsigned) 0; j < (unsigned) N; j += sizeof(B) * 8)
			{
				unsigned char packed_vals = (unsigned char) V_N[(i -j) / (sizeof(B) * 8)];
				for (auto k = 0; k < 8; k++)
					V_N[idx--] = !frozen_bits[(N -1 -j) -k] && ((packed_vals >> (7-k)) & 0x01);
			}

		unpack = true;
	}
#endif

	if (!unpack)
		for (auto i = 0; i < n_frames; i++)
			for (auto j = 0; j < N; j++)
				V_N[i * N + j] = !frozen_bits[j] && V_N[i * N + j];
}

template <typename B, typename R, class API_polar>
int Decoder_polar_SC_fast_sys<B,R,API_polar>
::get_n_frames() const
{
	return n_frames;
}