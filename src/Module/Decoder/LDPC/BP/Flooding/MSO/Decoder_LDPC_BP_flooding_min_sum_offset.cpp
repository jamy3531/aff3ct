#include <limits>

#include "Tools/Display/bash_tools.h"
#include "Tools/Math/utils.h"

#include "Decoder_LDPC_BP_flooding_min_sum_offset.hpp"

template <typename B, typename R>
Decoder_LDPC_BP_flooding_min_sum_offset<B,R>
::Decoder_LDPC_BP_flooding_min_sum_offset(const int &K, const int &N, const int& n_ite,
                                          const AList_reader &alist_data,
                                          const bool enable_syndrome,
                                          const int n_frames,
                                          const std::string name)
: Decoder_LDPC_BP_flooding<B,R>(K, N, n_ite, alist_data, enable_syndrome, n_frames, name)
{
}

template <typename B, typename R>
Decoder_LDPC_BP_flooding_min_sum_offset<B,R>
::~Decoder_LDPC_BP_flooding_min_sum_offset()
{
}

// normalized offest min-sum implementation
template <typename B, typename R>
bool Decoder_LDPC_BP_flooding_min_sum_offset<B,R>
::BP_process()
{
	auto syndrome = 0;	
	auto transpose_ptr = this->transpose.data();

	for (auto i = 0; i < this->n_C_nodes; i++)
	{
		const auto length = this->n_variables_per_parity[i];

		auto sign = 0;
		auto min1 = std::numeric_limits<R>::max();
		auto min2 = std::numeric_limits<R>::max();

		// accumulate the incoming information in CN
		for (auto j = 0; j < length; j++)
		{
			const auto value  = this->V_to_C[transpose_ptr[j]];
			const auto c_sign = std::signbit((float)value) ? -1 : 0;
			const auto v_abs  = (R)std::abs(value);
			const auto v_temp = min1;

			sign ^= c_sign;
			min1  = std::min(min1,          v_abs         ); // 1st min
			min2  = std::min(min2, std::max(v_abs, v_temp)); // 2nd min
		}

		// compute CN inter values
		constexpr float offset    = 0.000f; // 0.00f // 0.15f
		constexpr float normalize = 0.825f; // 1.00f // 1.25f // 0.825f

		auto cste1 = (min2 - offset) * normalize;
		auto cste2 = (min1 - offset) * normalize;
		cste1 = (cste1 < 0) ? 0 : cste1;
		cste2 = (cste2 < 0) ? 0 : cste2;

		// regenerate the CN outcoming values
		for (auto j = 0; j < length; j++)
		{
			const auto value   = this->V_to_C[transpose_ptr[j]];
			const auto v_abs   = (R)std::abs(value);
			const auto v_res   = ((v_abs == min1) ? cste1 : cste2);            // cmov
			const auto v_sig   = sign ^ (std::signbit((float)value) ? -1 : 0); // xor bit
			const auto v_to_st = (R)std::copysign(v_res, v_sig);               // magnitude of v_res, sign of v_sig

			this->C_to_V[transpose_ptr[j]] = v_to_st;
		}

		transpose_ptr += length;
		syndrome = syndrome || sign;
	}

	return (syndrome == 0);
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class Decoder_LDPC_BP_flooding_min_sum_offset<B_8,Q_8>;
template class Decoder_LDPC_BP_flooding_min_sum_offset<B_16,Q_16>;
template class Decoder_LDPC_BP_flooding_min_sum_offset<B_32,Q_32>;
template class Decoder_LDPC_BP_flooding_min_sum_offset<B_64,Q_64>;
#else
template class Decoder_LDPC_BP_flooding_min_sum_offset<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
