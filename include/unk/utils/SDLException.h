/* Unknown Engine Project */

#ifndef UNK_SDL_EXCEPTION_H
#define UNK_SDL_EXCEPTION_H

#include "SDL2/SDL.h"

#include <exception>
#include <string>

namespace unk {
    class SDLException : public std::exception {
        private:
            static std::string prefixMessage;
            std::string message;

        public:
            SDLException();
            SDLException(std::string message);

            virtual const char *what() const throw();
    };
}

#endif
