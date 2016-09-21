/* Unknown Engine Project */

#include "unk/utils/SDLException.h"

unk::SDLException::SDLException() : std::runtime_error(SDL_GetError()) {

}

unk::SDLException::SDLException(std::string message) : std::runtime_error(message) {

}
