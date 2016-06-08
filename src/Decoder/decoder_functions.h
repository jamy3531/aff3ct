#ifndef DECODER_FUNCTIONS_H
#define DECODER_FUNCTIONS_H

#include <algorithm>
#include <limits>

// ------------------------------------------------------------------------------------------------------ tools headers

template <typename R> inline R           div2(R           val) { return val * (R)0.50; }
template <>           inline int         div2(int         val) { return val >> 1;      }
template <>           inline short       div2(short       val) { return val >> 1;      }
template <>           inline signed char div2(signed char val) { return val >> 1;      }

template <typename R> inline R           div4(R           val) { return val * (R)0.25; }
template <>           inline int         div4(int         val) { return val >> 2;      }
template <>           inline short       div4(short       val) { return val >> 2;      }
template <>           inline signed char div4(signed char val) { return val >> 2;      }

// init value depending on the domain
template <typename R>
constexpr R init_LR () { return (R)1; }

template <typename R>
constexpr R init_LLR() { return (R)0; }

// saturate values in function of the domain
template <typename R>
constexpr std::pair<R,R> sat_vals() { return std::make_pair(-std::numeric_limits<R>::infinity(), 
                                                             std::numeric_limits<R>::infinity()); }

template <>
constexpr std::pair<short, short> sat_vals() { return std::make_pair(-16382, 16382); }

template <>
constexpr std::pair<signed char, signed char> sat_vals() { return std::make_pair(-63, 63); }

// return the initial value for a bit
template <typename B>
constexpr B bit_init() { return (((B)1) << (sizeof(B) * 8 -1)); }

// make a saturation on a the value "val"
template <typename T>
inline T saturate(const T val, const T min, const T max) { return std::min(std::max(val, min), max); }

template <typename B, typename R>
B sgn(R val) { return (B)((R(0) < val) - (val < R(0))); }

#endif /* DECODER_FUNCTIONS_H */