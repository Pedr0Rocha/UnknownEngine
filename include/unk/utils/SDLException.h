/* Unknown Engine Project */

#ifndef UNK_SDL_EXCEPTION_H
#define UNK_SDL_EXCEPTION_H

#include "SDL2/SDL.h"

#include <exception>
#include <string>

namespace unk {

    /**
     * @brief Exception raised if it occurs any problems while using
     * SDL functions.
     *
     * @details Its main function is to call the SDL error function
     * @c SDL_GetError() as well as its derivatives (comming from other
     * libraries), such as @c IMG_GetError().
     */
    class SDLException : public std::exception {
        private:
            static std::string prefixMessage;
            std::string message;

        public:
            /// @brief Constructs the object with the behaviour specified above.
            SDLException();
            /// @brief Constructs the object with a custom error message.
            SDLException(std::string message);

            ~SDLException() throw();

            /// @brief Returns the exception message given.
            virtual const char *what() const throw();
    };
}

#endif
