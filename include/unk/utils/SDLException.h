/* Unknown Engine Project */

#ifndef UNK_SDL_EXCEPTION_H
#define UNK_SDL_EXCEPTION_H

#include "SDL2/SDL.h"

#include <stdexcept>

namespace unk {
    class SDLException : public std::runtime_error {
        public:
            SDLException();
            SDLException(std::string message);
    };
}

#endif
