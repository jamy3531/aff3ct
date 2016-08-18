#ifndef INTERLEAVER_LTE_HPP
#define	INTERLEAVER_LTE_HPP

#include <map>

#include "../Tools/bash_tools.h"

#include "Interleaver.hpp"

inline int pi_LTE(const int &i, const int &f_1, const int &f_2, const int &K)
{
	// ((f_1 * i) + (f_2 * i * i)) % K <=> (((f_1 + f_2 * i) % K) * i) % K;
	// the second expression can be calculated on int if i and K are big (6144 for example)
	return (((f_1 + f_2 * i) % K) * i) % K;
}

template <typename T>
class Interleaver_LTE : public Interleaver<T>
{
public:
	Interleaver_LTE(int size, const std::string name = "Interleaver_LTE") 
	: Interleaver<T>(size, 1, name.c_str()) { gen_lookup_tables(); }

protected:
	void gen_lookup_tables()
	{
		std::map<T,T> f_1;
		std::map<T,T> f_2;
		f_1[  40] =   3; f_2[  40] =  10;
		f_1[  48] =   7; f_2[  48] =  12;
		f_1[  56] =  19; f_2[  56] =  42;
		f_1[  64] =   7; f_2[  64] =  16;
		f_1[  72] =   7; f_2[  72] =  18;
		f_1[  80] =  11; f_2[  80] =  20;
		f_1[  88] =   5; f_2[  88] =  22;
		f_1[  96] =  11; f_2[  96] =  24;
		f_1[ 104] =   7; f_2[ 104] =  26;
		f_1[ 112] =  41; f_2[ 112] =  84;
		f_1[ 120] = 103; f_2[ 120] =  90;
		f_1[ 128] =  15; f_2[ 128] =  32;
		f_1[ 136] =   9; f_2[ 136] =  34;
		f_1[ 144] =  17; f_2[ 144] = 108;
		f_1[ 152] =   9; f_2[ 152] =  38;
		f_1[ 160] =  21; f_2[ 160] = 120;
		f_1[ 168] = 101; f_2[ 168] =  84;
		f_1[ 176] =  21; f_2[ 176] =  44;
		f_1[ 184] =  57; f_2[ 184] =  46;
		f_1[ 192] =  23; f_2[ 192] =  48;
		f_1[ 200] =  13; f_2[ 200] =  50;
		f_1[ 208] =  27; f_2[ 208] =  52;
		f_1[ 216] =  11; f_2[ 216] =  36;
		f_1[ 224] =  27; f_2[ 224] =  56;
		f_1[ 232] =  85; f_2[ 232] =  58;
		f_1[ 240] =  29; f_2[ 240] =  60;
		f_1[ 248] =  33; f_2[ 248] =  62;
		f_1[ 256] =  15; f_2[ 256] =  32;
		f_1[ 264] =  17; f_2[ 264] = 198;
		f_1[ 272] =  33; f_2[ 272] =  68;
		f_1[ 280] = 103; f_2[ 280] = 210;
		f_1[ 288] =  19; f_2[ 288] =  36;
		f_1[ 296] =  19; f_2[ 296] =  74;
		f_1[ 304] =  37; f_2[ 304] =  76;
		f_1[ 312] =  19; f_2[ 312] =  78;
		f_1[ 320] =  21; f_2[ 320] = 120;
		f_1[ 328] =  21; f_2[ 328] =  82;
		f_1[ 336] = 115; f_2[ 336] =  84;
		f_1[ 344] = 193; f_2[ 344] =  86;
		f_1[ 352] =  21; f_2[ 352] =  44;
		f_1[ 360] = 133; f_2[ 360] =  90;
		f_1[ 368] =  81; f_2[ 368] =  46;
		f_1[ 376] =  45; f_2[ 376] =  94;
		f_1[ 384] =  23; f_2[ 384] =  48;
		f_1[ 392] = 243; f_2[ 392] =  98;
		f_1[ 400] = 151; f_2[ 400] =  40;
		f_1[ 408] = 155; f_2[ 408] = 102;
		f_1[ 416] =  25; f_2[ 416] =  52;
		f_1[ 424] =  51; f_2[ 424] = 106;
		f_1[ 432] =  47; f_2[ 432] =  72;
		f_1[ 440] =  91; f_2[ 440] = 110;
		f_1[ 448] =  29; f_2[ 448] = 168;
		f_1[ 456] =  29; f_2[ 456] = 114;
		f_1[ 464] = 247; f_2[ 464] =  58;
		f_1[ 472] =  29; f_2[ 472] = 118;
		f_1[ 480] =  89; f_2[ 480] = 180;
		f_1[ 488] =  91; f_2[ 488] = 122;
		f_1[ 496] = 157; f_2[ 496] =  62;
		f_1[ 504] =  55; f_2[ 504] =  84;
		f_1[ 512] =  31; f_2[ 512] =  64;
		f_1[ 528] =  17; f_2[ 528] =  66;
		f_1[ 544] =  35; f_2[ 544] =  68;
		f_1[ 560] = 227; f_2[ 560] = 420;
		f_1[ 576] =  65; f_2[ 576] =  96;
		f_1[ 592] =  19; f_2[ 592] =  74;
		f_1[ 608] =  37; f_2[ 608] =  76;
		f_1[ 624] =  41; f_2[ 624] = 234;
		f_1[ 640] =  39; f_2[ 640] =  80;
		f_1[ 656] = 185; f_2[ 656] =  82;
		f_1[ 672] =  43; f_2[ 672] = 252;
		f_1[ 688] =  21; f_2[ 688] =  86;
		f_1[ 704] = 155; f_2[ 704] =  44;
		f_1[ 720] =  79; f_2[ 720] = 120;
		f_1[ 736] = 139; f_2[ 736] =  92;
		f_1[ 752] =  23; f_2[ 752] =  94;
		f_1[ 768] = 217; f_2[ 768] =  48;
		f_1[ 784] =  25; f_2[ 784] =  98;
		f_1[ 800] =  17; f_2[ 800] =  80;
		f_1[ 816] = 127; f_2[ 816] = 102;
		f_1[ 832] =  25; f_2[ 832] =  52;
		f_1[ 848] = 239; f_2[ 848] = 106;
		f_1[ 864] =  17; f_2[ 864] =  48;
		f_1[ 880] = 137; f_2[ 880] = 110;
		f_1[ 896] = 215; f_2[ 896] = 112;
		f_1[ 912] =  29; f_2[ 912] = 114;
		f_1[ 928] =  15; f_2[ 928] =  58;
		f_1[ 944] = 147; f_2[ 944] = 118;
		f_1[ 960] =  29; f_2[ 960] =  60;
		f_1[ 976] =  59; f_2[ 976] = 122;
		f_1[ 992] =  65; f_2[ 992] = 124;
		f_1[1008] =  55; f_2[1008] =  84;
		f_1[1024] =  31; f_2[1024] =  64;
		f_1[1056] =  17; f_2[1056] =  66;
		f_1[1088] = 171; f_2[1088] = 204;
		f_1[1120] =  67; f_2[1120] = 140;
		f_1[1152] =  35; f_2[1152] =  72;
		f_1[1184] =  19; f_2[1184] =  74;
		f_1[1216] =  39; f_2[1216] =  76;
		f_1[1248] =  19; f_2[1248] =  78;
		f_1[1280] = 199; f_2[1280] = 240;
		f_1[1312] =  21; f_2[1312] =  82;
		f_1[1344] = 211; f_2[1344] = 252;
		f_1[1376] =  21; f_2[1376] =  86;
		f_1[1408] =  43; f_2[1408] =  88;
		f_1[1440] = 149; f_2[1440] =  60;
		f_1[1472] =  45; f_2[1472] =  92;
		f_1[1504] =  49; f_2[1504] = 846;
		f_1[1536] =  71; f_2[1536] =  48;
		f_1[1568] =  13; f_2[1568] =  28;
		f_1[1600] =  17; f_2[1600] =  80;
		f_1[1632] =  25; f_2[1632] = 102;
		f_1[1664] = 183; f_2[1664] = 104;
		f_1[1696] =  55; f_2[1696] = 954;
		f_1[1728] = 127; f_2[1728] =  96;
		f_1[1760] =  27; f_2[1760] = 110;
		f_1[1792] =  29; f_2[1792] = 112;
		f_1[1824] =  29; f_2[1824] = 114;
		f_1[1856] =  57; f_2[1856] = 116;
		f_1[1888] =  45; f_2[1888] = 354;
		f_1[1920] =  31; f_2[1920] = 120;
		f_1[1952] =  59; f_2[1952] = 610;
		f_1[1984] = 185; f_2[1984] = 124;
		f_1[2016] = 113; f_2[2016] = 420;
		f_1[2048] =  31; f_2[2048] =  64;
		f_1[2112] =  17; f_2[2112] =  66;
		f_1[2176] = 171; f_2[2176] = 136;
		f_1[2240] = 209; f_2[2240] = 420;
		f_1[2304] = 253; f_2[2304] = 216;
		f_1[2368] = 367; f_2[2368] = 444;
		f_1[2432] = 265; f_2[2432] = 456;
		f_1[2496] = 181; f_2[2496] = 468;
		f_1[2560] =  39; f_2[2560] =  80;
		f_1[2624] =  27; f_2[2624] = 164;
		f_1[2688] = 127; f_2[2688] = 504;
		f_1[2752] = 143; f_2[2752] = 172;
		f_1[2816] =  43; f_2[2816] =  88;
		f_1[2880] =  29; f_2[2880] = 300;
		f_1[2944] =  45; f_2[2944] =  92;
		f_1[3008] = 157; f_2[3008] = 188;
		f_1[3072] =  47; f_2[3072] =  96;
		f_1[3136] =  13; f_2[3136] =  28;
		f_1[3200] = 111; f_2[3200] = 240;
		f_1[3264] = 443; f_2[3264] = 204;
		f_1[3328] =  51; f_2[3328] = 104;
		f_1[3392] =  51; f_2[3392] = 212;
		f_1[3456] = 451; f_2[3456] = 192;
		f_1[3520] = 257; f_2[3520] = 220;
		f_1[3584] =  57; f_2[3584] = 336;
		f_1[3648] = 313; f_2[3648] = 228;
		f_1[3712] = 271; f_2[3712] = 232;
		f_1[3776] = 179; f_2[3776] = 236;
		f_1[3840] = 331; f_2[3840] = 120;
		f_1[3904] = 363; f_2[3904] = 244;
		f_1[3968] = 375; f_2[3968] = 248;
		f_1[4032] = 127; f_2[4032] = 168;
		f_1[4096] =  31; f_2[4096] =  64;
		f_1[4160] =  33; f_2[4160] = 130;
		f_1[4224] =  43; f_2[4224] = 264;
		f_1[4288] =  33; f_2[4288] = 134;
		f_1[4352] = 477; f_2[4352] = 408;
		f_1[4416] =  35; f_2[4416] = 138;
		f_1[4480] = 233; f_2[4480] = 280;
		f_1[4544] = 357; f_2[4544] = 142;
		f_1[4608] = 337; f_2[4608] = 480;
		f_1[4672] =  37; f_2[4672] = 146;
		f_1[4736] =  71; f_2[4736] = 444;
		f_1[4800] =  71; f_2[4800] = 120;
		f_1[4864] =  37; f_2[4864] = 152;
		f_1[4928] =  39; f_2[4928] = 462;
		f_1[4992] = 127; f_2[4992] = 234;
		f_1[5056] =  39; f_2[5056] = 158;
		f_1[5120] =  39; f_2[5120] =  80;
		f_1[5184] =  31; f_2[5184] =  96;
		f_1[5248] = 113; f_2[5248] = 902;
		f_1[5312] =  41; f_2[5312] = 166;
		f_1[5376] = 251; f_2[5376] = 336;
		f_1[5440] =  43; f_2[5440] = 170;
		f_1[5504] =  21; f_2[5504] =  86;
		f_1[5568] =  43; f_2[5568] = 174;
		f_1[5632] =  45; f_2[5632] = 176;
		f_1[5696] =  45; f_2[5696] = 178;
		f_1[5760] = 161; f_2[5760] = 120;
		f_1[5824] =  89; f_2[5824] = 182;
		f_1[5888] = 323; f_2[5888] = 184;
		f_1[5952] =  47; f_2[5952] = 186;
		f_1[6016] =  23; f_2[6016] =  94;
		f_1[6080] =  47; f_2[6080] = 190;
		f_1[6144] = 263; f_2[6144] = 480;

		int size = this->pi.size();
		if (f_1.find(size) != f_1.end())
		{
			for (auto i = 0; i < size; i++)
			{
				this->pi[i] = (T)pi_LTE(i, f_1[size], f_2[size], size);
				assert(this->pi[i] >= 0 && this->pi[i] < size);
				this->pi_inv[this->pi[i]] = (T)i;
			}
		}
		else
		{
			std::cerr << bold_red("(EE) There is no LTE f_1 and f_2 parameters for size = ")
			          << bold_red(std::to_string(size)) 
			          << bold_red(": exiting simulation.") << std::endl;
			exit(-1);
		}
	}
};

#endif	/* INTERLEAVER_LTE_HPP */