#ifndef FACTORY_TERMINAL_HPP
#define FACTORY_TERMINAL_HPP

#include "../../Terminal/Terminal.hpp"
#include "../../Error/Error_analyzer.hpp"

#include "../params.h"

template <typename B, typename R>
struct Factory_terminal
{
	static Terminal* build(const t_simulation_param &simu_params,
	                       const R snr, 
	                       const Error_analyzer<B,R> *analyzer, 
	                       const std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> &t_snr,
	                       const std::chrono::nanoseconds &d_load_total,
	                       const std::chrono::nanoseconds &d_decod_total,
	                       const std::chrono::nanoseconds &d_store_total);
};

#endif /* FACTORY_TERMINAL_HPP */