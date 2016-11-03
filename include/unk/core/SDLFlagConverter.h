/* Unknown Engine Project */

#ifndef UNK_SDL_FLAG_CONVERTER_H
#define UNK_SDL_FLAG_CONVERTER_H

#include "SDL2/SDL.h"

#include "unk/core/Renderer.h"
#include "unk/core/RenderOptions.h"
#include "unk/utils/UnkExceptions.h"

#include <map>

namespace unk {
    /**
     * @brief Converts @a UnknownEngineFlags to @a SDL_Flags.
     *
     * @details Converts any type of @a UnknownEngineFlag to @a SDL_Flag using bitwise OR 
     * if correctly mapped.
     */
    template <class FlagType>
        class SDLFlagConverter : public std::map<FlagType, uint32_t> {
            public:
                typedef std::map<FlagType, uint32_t> FlagMap;

                SDLFlagConverter<FlagType>();
                SDLFlagConverter<FlagType>(std::initializer_list<typename FlagMap::value_type> ilist);

                /// @brief Returns an unsigned integer that corresponds to the bitwise OR operations
                /// applied to the flag array.
                uint32_t toSDLFlags(std::vector<FlagType> flags);

                /// @brief Returns the @a SDLFlag that corresponds to the @p flag.
                uint32_t toSDLFlag(FlagType flag);
        };
}

/* Template Implementation */
template <class FlagType>
unk::SDLFlagConverter<FlagType>::SDLFlagConverter() {

}

template <class FlagType>
unk::SDLFlagConverter<FlagType>::SDLFlagConverter(
        std::initializer_list<typename FlagMap::value_type> ilist) : 
    FlagMap(ilist) {

}

template <class FlagType>
uint32_t unk::SDLFlagConverter<FlagType>::toSDLFlags(std::vector<FlagType> flags) {
    uint32_t sdlFlags = 0;

    for (auto flag : flags)
        sdlFlags |= toSDLFlag(flag);

    return sdlFlags;
}

template <class FlagType>
uint32_t unk::SDLFlagConverter<FlagType>::toSDLFlag(FlagType flag) {
    if (this->count(flag) > 0)
        return (*this)[flag];

    throw KeyNotFoundException(std::to_string(static_cast<int>(flag)));
}


#endif
