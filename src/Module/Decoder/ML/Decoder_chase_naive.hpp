#ifndef DECODER_CHASE_NAIVE_HPP_
#define DECODER_CHASE_NAIVE_HPP_

#include "Decoder_maximum_likelihood.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float>
class Decoder_chase_naive : public Decoder_maximum_likelihood<B,R>
{
protected:
	const uint32_t max_flips;
	const bool hamming;
	float min_euclidean_dist;
	uint32_t min_hamming_dist;

public:
	Decoder_chase_naive(const int K, const int N, Encoder<B> &encoder, const uint32_t max_flips = 3, 
	                    const bool hamming = false, const int n_frames = 1);
	virtual ~Decoder_chase_naive();

protected:
	void _decode_siho   (const R *Y_N,  B *V_K, const int frame_id);
	void _decode_siho_cw(const R *Y_N,  B *V_N, const int frame_id);
	void _decode_hiho   (const B *Y_N,  B *V_K, const int frame_id);
	void _decode_hiho_cw(const B *Y_N,  B *V_N, const int frame_id);

	inline void _try_sequence_llrs(const R *Y_N, const B *X_N, B *V_N);
	inline void _try_sequence_bits(const B *Y_N, const B *X_N, B *V_N);
};
}
}

#endif /* DECODER_CHASE_NAIVE_HPP_ */