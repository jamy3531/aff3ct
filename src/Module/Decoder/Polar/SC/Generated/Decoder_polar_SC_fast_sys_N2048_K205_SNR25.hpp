#ifndef DECODER_POLAR_SC_FAST_SYS_N2048_K205_SNR25_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N2048_K205_SNR25_HPP_

#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const char Decoder_polar_SC_fast_sys_fb_2048_205_25[2048] = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <typename B, typename R, class API_polar>
class Decoder_polar_SC_fast_sys_N2048_K205_SNR25 : public Decoder_polar_SC_fast_sys<B, R, API_polar>
{
public:
	Decoder_polar_SC_fast_sys_N2048_K205_SNR25(const int& K, const int& N, const mipp::vector<B>& frozen_bits, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys<B, R, API_polar>(K, N, frozen_bits, n_frames)
	{
		assert(N == 2048);
		assert(K == 205);
		
		auto i = 0;
		while (i < 2048 && Decoder_polar_SC_fast_sys_fb_2048_205_25[i] == frozen_bits[i]) i++;
		assert(i == 2048);
	}

	virtual ~Decoder_polar_SC_fast_sys_N2048_K205_SNR25()
	{
	}

	void _hard_decode(const R *Y_N, B *V_K, const int frame_id)
	{
		using namespace tools;

		auto t_load = std::chrono::steady_clock::now();
		this->_load(Y_N);
		auto d_load = std::chrono::steady_clock::now() - t_load;

		auto t_decod = std::chrono::steady_clock::now();
		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <1024>(   l,    0+   0,    0+1024,               0+2048, 1024);
		API_polar::template g0 < 512>(   l, 2048+   0, 2048+ 512,            2048+1024,  512);
		API_polar::template g0 < 256>(   l, 3072+   0, 3072+ 256,            3072+ 512,  256);
		API_polar::template g0 < 128>(   l, 3584+   0, 3584+ 128,            3584+ 256,  128);
		API_polar::template g0 <  64>(   l, 3840+   0, 3840+  64,            3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template rep<  32>(s, l, 4032+   0,                        960+   0,   32);
		API_polar::template gr <  32>(s, l, 3968+   0, 3968+  32,  960+   0, 3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template rep<  16>(s, l, 4064+   0,                        992+   0,   16);
		API_polar::template gr <  16>(s, l, 4032+   0, 4032+  16,  992+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template g0 <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template g0 <   2>(   l, 4088+   0, 4088+   2,            4088+   4,    2);
		API_polar::template h  <   2>(s, l, 4092+   0,                       1014+   0,    2);
		API_polar::template xo0<   2>(s,    1012+   2,                       1012+   0,    2);
		API_polar::template xo0<   4>(s,    1008+   4,                       1008+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1008+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1016+   0,    8);
		API_polar::template xo <   8>(s,    1008+   0, 1008+   8,            1008+   0,    8);
		API_polar::template xo <  16>(s,     992+   0,  992+  16,             992+   0,   16);
		API_polar::template xo <  32>(s,     960+   0,  960+  32,             960+   0,   32);
		API_polar::template xo0<  64>(s,     896+  64,                        896+   0,   64);
		API_polar::template xo0< 128>(s,     768+ 128,                        768+   0,  128);
		API_polar::template xo0< 256>(s,     512+ 256,                        512+   0,  256);
		API_polar::template xo0< 512>(s,       0+ 512,                          0+   0,  512);
		API_polar::template g  <1024>(s, l,    0+   0,    0+1024,    0+   0,    0+2048, 1024);
		API_polar::template f  < 512>(   l, 2048+   0, 2048+ 512,            2048+1024,  512);
		API_polar::template g0 < 256>(   l, 3072+   0, 3072+ 256,            3072+ 512,  256);
		API_polar::template f  < 128>(   l, 3584+   0, 3584+ 128,            3584+ 256,  128);
		API_polar::template rep< 128>(s, l, 3840+   0,                       1280+   0,  128);
		API_polar::template gr < 128>(s, l, 3584+   0, 3584+ 128, 1280+   0, 3584+ 256,  128);
		API_polar::template f  <  64>(   l, 3840+   0, 3840+  64,            3840+ 128,   64);
		API_polar::template rep<  64>(s, l, 3968+   0,                       1408+   0,   64);
		API_polar::template gr <  64>(s, l, 3840+   0, 3840+  64, 1408+   0, 3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template g0 <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template g0 <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template g0 <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1500+   0,    4);
		API_polar::template xo0<   4>(s,    1496+   4,                       1496+   0,    4);
		API_polar::template xo0<   8>(s,    1488+   8,                       1488+   0,    8);
		API_polar::template xo0<  16>(s,    1472+  16,                       1472+   0,   16);
		API_polar::template g  <  32>(s, l, 3968+   0, 3968+  32, 1472+   0, 3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template rep<   8>(s, l, 4080+   0,                       1504+   0,    8);
		API_polar::template gr <   8>(s, l, 4064+   0, 4064+   8, 1504+   0, 4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1512+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1512+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1516+   0,    4);
		API_polar::template xo <   4>(s,    1512+   0, 1512+   4,            1512+   0,    4);
		API_polar::template xo <   8>(s,    1504+   0, 1504+   8,            1504+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1504+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1520+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1520+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1524+   0,    4);
		API_polar::template xo <   4>(s,    1520+   0, 1520+   4,            1520+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1520+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1528+   0,    8);
		API_polar::template xo <   8>(s,    1520+   0, 1520+   8,            1520+   0,    8);
		API_polar::template xo <  16>(s,    1504+   0, 1504+  16,            1504+   0,   16);
		API_polar::template xo <  32>(s,    1472+   0, 1472+  32,            1472+   0,   32);
		API_polar::template xo <  64>(s,    1408+   0, 1408+  64,            1408+   0,   64);
		API_polar::template xo < 128>(s,    1280+   0, 1280+ 128,            1280+   0,  128);
		API_polar::template xo0< 256>(s,    1024+ 256,                       1024+   0,  256);
		API_polar::template g  < 512>(s, l, 2048+   0, 2048+ 512, 1024+   0, 2048+1024,  512);
		API_polar::template f  < 256>(   l, 3072+   0, 3072+ 256,            3072+ 512,  256);
		API_polar::template f  < 128>(   l, 3584+   0, 3584+ 128,            3584+ 256,  128);
		API_polar::template rep< 128>(s, l, 3840+   0,                       1536+   0,  128);
		API_polar::template gr < 128>(s, l, 3584+   0, 3584+ 128, 1536+   0, 3584+ 256,  128);
		API_polar::template f  <  64>(   l, 3840+   0, 3840+  64,            3840+ 128,   64);
		API_polar::template g0 <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template g0 <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template g0 <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1720+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1720+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1724+   0,    4);
		API_polar::template xo <   4>(s,    1720+   0, 1720+   4,            1720+   0,    4);
		API_polar::template xo0<   8>(s,    1712+   8,                       1712+   0,    8);
		API_polar::template xo0<  16>(s,    1696+  16,                       1696+   0,   16);
		API_polar::template xo0<  32>(s,    1664+  32,                       1664+   0,   32);
		API_polar::template g  <  64>(s, l, 3840+   0, 3840+  64, 1664+   0, 3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template rep<  16>(s, l, 4064+   0,                       1728+   0,   16);
		API_polar::template gr <  16>(s, l, 4032+   0, 4032+  16, 1728+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template rep<   8>(s, l, 4080+   0,                       1744+   0,    8);
		API_polar::template gr <   8>(s, l, 4064+   0, 4064+   8, 1744+   0, 4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1752+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1752+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1756+   0,    4);
		API_polar::template xo <   4>(s,    1752+   0, 1752+   4,            1752+   0,    4);
		API_polar::template xo <   8>(s,    1744+   0, 1744+   8,            1744+   0,    8);
		API_polar::template xo <  16>(s,    1728+   0, 1728+  16,            1728+   0,   16);
		API_polar::template g  <  32>(s, l, 3968+   0, 3968+  32, 1728+   0, 3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template rep<   8>(s, l, 4080+   0,                       1760+   0,    8);
		API_polar::template gr <   8>(s, l, 4064+   0, 4064+   8, 1760+   0, 4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1768+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1768+   0, 4080+   8,    4);
		API_polar::template h  <   4>(s, l, 4088+   0,                       1772+   0,    4);
		API_polar::template xo <   4>(s,    1768+   0, 1768+   4,            1768+   0,    4);
		API_polar::template xo <   8>(s,    1760+   0, 1760+   8,            1760+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1760+   0, 4032+  32,   16);
		API_polar::template spc<  16>(s, l, 4064+   0,                       1776+   0,   16);
		API_polar::template xo <  16>(s,    1760+   0, 1760+  16,            1760+   0,   16);
		API_polar::template xo <  32>(s,    1728+   0, 1728+  32,            1728+   0,   32);
		API_polar::template xo <  64>(s,    1664+   0, 1664+  64,            1664+   0,   64);
		API_polar::template xo < 128>(s,    1536+   0, 1536+ 128,            1536+   0,  128);
		API_polar::template g  < 256>(s, l, 3072+   0, 3072+ 256, 1536+   0, 3072+ 512,  256);
		API_polar::template f  < 128>(   l, 3584+   0, 3584+ 128,            3584+ 256,  128);
		API_polar::template f  <  64>(   l, 3840+   0, 3840+  64,            3840+ 128,   64);
		API_polar::template g0 <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template rep<  16>(s, l, 4064+   0,                       1824+   0,   16);
		API_polar::template gr <  16>(s, l, 4032+   0, 4032+  16, 1824+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template rep<   8>(s, l, 4080+   0,                       1840+   0,    8);
		API_polar::template gr <   8>(s, l, 4064+   0, 4064+   8, 1840+   0, 4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1848+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1848+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1852+   0,    4);
		API_polar::template xo <   4>(s,    1848+   0, 1848+   4,            1848+   0,    4);
		API_polar::template xo <   8>(s,    1840+   0, 1840+   8,            1840+   0,    8);
		API_polar::template xo <  16>(s,    1824+   0, 1824+  16,            1824+   0,   16);
		API_polar::template xo0<  32>(s,    1792+  32,                       1792+   0,   32);
		API_polar::template g  <  64>(s, l, 3840+   0, 3840+  64, 1792+   0, 3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template rep<  16>(s, l, 4064+   0,                       1856+   0,   16);
		API_polar::template gr <  16>(s, l, 4032+   0, 4032+  16, 1856+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template g0 <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template g0 <   2>(   l, 4088+   0, 4088+   2,            4088+   4,    2);
		API_polar::template h  <   2>(s, l, 4092+   0,                       1878+   0,    2);
		API_polar::template xo0<   2>(s,    1876+   2,                       1876+   0,    2);
		API_polar::template xo0<   4>(s,    1872+   4,                       1872+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1872+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1880+   0,    8);
		API_polar::template xo <   8>(s,    1872+   0, 1872+   8,            1872+   0,    8);
		API_polar::template xo <  16>(s,    1856+   0, 1856+  16,            1856+   0,   16);
		API_polar::template g  <  32>(s, l, 3968+   0, 3968+  32, 1856+   0, 3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1888+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1888+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1892+   0,    4);
		API_polar::template xo <   4>(s,    1888+   0, 1888+   4,            1888+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1888+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1896+   0,    8);
		API_polar::template xo <   8>(s,    1888+   0, 1888+   8,            1888+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1888+   0, 4032+  32,   16);
		API_polar::template spc<  16>(s, l, 4064+   0,                       1904+   0,   16);
		API_polar::template xo <  16>(s,    1888+   0, 1888+  16,            1888+   0,   16);
		API_polar::template xo <  32>(s,    1856+   0, 1856+  32,            1856+   0,   32);
		API_polar::template xo <  64>(s,    1792+   0, 1792+  64,            1792+   0,   64);
		API_polar::template g  < 128>(s, l, 3584+   0, 3584+ 128, 1792+   0, 3584+ 256,  128);
		API_polar::template f  <  64>(   l, 3840+   0, 3840+  64,            3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template g0 <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template g0 <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1932+   0,    4);
		API_polar::template xo0<   4>(s,    1928+   4,                       1928+   0,    4);
		API_polar::template xo0<   8>(s,    1920+   8,                       1920+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1920+   0, 4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1936+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1936+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1940+   0,    4);
		API_polar::template xo <   4>(s,    1936+   0, 1936+   4,            1936+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1936+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1944+   0,    8);
		API_polar::template xo <   8>(s,    1936+   0, 1936+   8,            1936+   0,    8);
		API_polar::template xo <  16>(s,    1920+   0, 1920+  16,            1920+   0,   16);
		API_polar::template g  <  32>(s, l, 3968+   0, 3968+  32, 1920+   0, 3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1952+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1952+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1956+   0,    4);
		API_polar::template xo <   4>(s,    1952+   0, 1952+   4,            1952+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1952+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1960+   0,    8);
		API_polar::template xo <   8>(s,    1952+   0, 1952+   8,            1952+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1952+   0, 4032+  32,   16);
		API_polar::template spc<  16>(s, l, 4064+   0,                       1968+   0,   16);
		API_polar::template xo <  16>(s,    1952+   0, 1952+  16,            1952+   0,   16);
		API_polar::template xo <  32>(s,    1920+   0, 1920+  32,            1920+   0,   32);
		API_polar::template g  <  64>(s, l, 3840+   0, 3840+  64, 1920+   0, 3840+ 128,   64);
		API_polar::template f  <  32>(   l, 3968+   0, 3968+  32,            3968+  64,   32);
		API_polar::template f  <  16>(   l, 4032+   0, 4032+  16,            4032+  32,   16);
		API_polar::template f  <   8>(   l, 4064+   0, 4064+   8,            4064+  16,    8);
		API_polar::template f  <   4>(   l, 4080+   0, 4080+   4,            4080+   8,    4);
		API_polar::template rep<   4>(s, l, 4088+   0,                       1984+   0,    4);
		API_polar::template gr <   4>(s, l, 4080+   0, 4080+   4, 1984+   0, 4080+   8,    4);
		API_polar::template spc<   4>(s, l, 4088+   0,                       1988+   0,    4);
		API_polar::template xo <   4>(s,    1984+   0, 1984+   4,            1984+   0,    4);
		API_polar::template g  <   8>(s, l, 4064+   0, 4064+   8, 1984+   0, 4064+  16,    8);
		API_polar::template spc<   8>(s, l, 4080+   0,                       1992+   0,    8);
		API_polar::template xo <   8>(s,    1984+   0, 1984+   8,            1984+   0,    8);
		API_polar::template g  <  16>(s, l, 4032+   0, 4032+  16, 1984+   0, 4032+  32,   16);
		API_polar::template h  <  16>(s, l, 4064+   0,                       2000+   0,   16);
		API_polar::template xo <  16>(s,    1984+   0, 1984+  16,            1984+   0,   16);
		API_polar::template g  <  32>(s, l, 3968+   0, 3968+  32, 1984+   0, 3968+  64,   32);
		API_polar::template h  <  32>(s, l, 4032+   0,                       2016+   0,   32);
		API_polar::template xo <  32>(s,    1984+   0, 1984+  32,            1984+   0,   32);
		API_polar::template xo <  64>(s,    1920+   0, 1920+  64,            1920+   0,   64);
		API_polar::template xo < 128>(s,    1792+   0, 1792+ 128,            1792+   0,  128);
		API_polar::template xo < 256>(s,    1536+   0, 1536+ 256,            1536+   0,  256);
		API_polar::template xo < 512>(s,    1024+   0, 1024+ 512,            1024+   0,  512);
		API_polar::template xo <1024>(s,       0+   0,    0+1024,               0+   0, 1024);
		auto d_decod = std::chrono::steady_clock::now() - t_decod;

		auto t_store = std::chrono::steady_clock::now();
		this->_store(V_K);
		auto d_store = std::chrono::steady_clock::now() - t_store;

		this->d_load_total  += d_load;
		this->d_decod_total += d_decod;
		this->d_store_total += d_store;
	}
};
}
}
#endif
