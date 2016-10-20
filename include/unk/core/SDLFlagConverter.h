/* Unknown Engine Project */

#ifndef UNK_SDL_FLAG_CONVERTER_H
#define UNK_SDL_FLAG_CONVERTER_H

#include "SDL2/SDL.H"

namespace unk {
    /**
     * @brief Converts @a UnknownEngineFlags to @a SDL_Flags.
     *
     * @details Converts any type of @a UnknownEngineFlag to @a SDL_Flag using bitwise OR 
     * if correctly mapped.
     */
	template <class FlagType>
	class SDLFlagConverter : public std::map<FlagType, uint32_t> {

		/// @brief Returns an unsigned integer that corresponds to the bitwise OR operations
		/// applied to the flag array.
		uint32_t toSDLFlags(std::vector<FlagType> flags);

		/// @brief Returns the @a SDLFlag that corresponds to the @p flag.
		uint32_t toSDLFlag(FlagType flag);
	};
}

/* Template Implementation */
template <class FlagType>
uint32_t unk::SDLFlagConverter<FlagType>::toSDLFlags(std::vector<FlagType> flags) {
	uint32_t sdlFlags = 0;

	for (auto flag : flags)
		sdlFlags |= toSDLFlag(flag);

	return sdlFlags;
}

template <class FlagType>
uint32_t unk::SDLFlagConverter<FlagType>::toSDLFlag(FlagType flag) {
	if (count(flag) > 0)
		return (*this)[flag]
	
	throw KeyNotFoundException(std::to_string(flag));
}


#endif