#ifndef FACTORY_DECODER_HPP_
#define FACTORY_DECODER_HPP_

#include <string>

#include "Module/Decoder/Decoder_SIHO.hpp"
#include "Module/Encoder/Encoder.hpp"

#include "../../Factory.hpp"

namespace aff3ct
{
namespace factory
{
extern const std::string Decoder_name;
extern const std::string Decoder_prefix;
struct Decoder : Factory
{
	class parameters : public Factory::parameters
	{
	public:
		// ------------------------------------------------------------------------------------------------- PARAMETERS
		// required parameters
		int         K           = 0;
		int         N_cw        = 0;

		// optional parameters
		std::string type        = "ML";
		std::string implem      = "STD";
		bool        systematic  = true;
		bool        hamming     = false;
		int         n_frames    = 1;
		int         tail_length = 0;
		int         flips       = 3;

		// deduced parameters
		float       R           = -1.f;

		// ---------------------------------------------------------------------------------------------------- METHODS
		virtual ~parameters();
		virtual Decoder::parameters* clone() const;

		// parameters construction
		virtual void get_description(arg_map &req_args, arg_map &opt_args                              ) const;
		virtual void store          (const arg_val_map &vals                                           );
		virtual void get_headers    (std::map<std::string,header_list>& headers, const bool full = true) const;

	protected:
		parameters(const std::string &n, const std::string &p);

		template <typename B = int, typename Q = float>
		module::Decoder_SIHO<B,Q>* build(module::Encoder<B> *encoder = nullptr) const;
	};
};
}
}

#endif /* FACTORY_DECODER_HPP_ */
