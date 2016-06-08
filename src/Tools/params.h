#ifndef PARAMS_H_
#define PARAMS_H_

#include <vector>
#include <string>
#include <chrono>

struct t_simulation_param
{
	std::string               type;
	int                       max_fe;
	int                       benchs;
	bool                      disable_display;
	bool                      enable_debug;
	int                       n_threads;
	bool                      enable_leg_term;
	bool                      enable_dec_thr;
	std::chrono::milliseconds display_freq;
	float                     snr_min;
	float                     snr_max;
	float                     snr_step;
	float                     sig_a_min;
	float                     sig_a_max;
	float                     sig_a_step;
	std::chrono::seconds      stop_time;
	std::string               awgn_codes_dir;
	std::string               bin_pb_path;
	std::string               awgn_codes_file;
	std::string               gen_decoder_dir;
};

struct t_code_param
{
	int         K;
	int         N;
	int         tail_length;
	int         m;
	int         M;
	float       sigma; // used to set a fixed snr value for frozen bits contstruction
	std::string type;
	std::string generation_method;
	std::string frozen_bits_path;
	std::string crc;
	std::string puncturer;
	std::string interleaver;
	std::string fb_gen_method;
};

struct t_encoder_param
{
	std::string type;
	bool systematic;
	bool buffered;
};

struct t_channel_param
{
	int         quant_point_pos;
	int         quant_n_bits;
	float       quant_min_max;
	std::string domain;
	std::string type;
	std::string quantizer_type;
};

struct t_decoder_param
{
	std::string algo;
	std::string implem;
	std::string simd_strategy;
	std::string scaling_factor;
	int         max_iter;
	int         L;
};

#endif /* PARAMS_H_ */
