/* Unknown Engine Project */

#include "unk/utils/SDLException.h"

std::string unk::SDLException::prefixMessage = "SDL error: ";

unk::SDLException::SDLException() {
    message = prefixMessage + SDL_GetError();
}

unk::SDLException::SDLException(std::string message) {
    this->message = prefixMessage + message;
}

unk::SDLException::~SDLException() throw() {
}

const char *unk::SDLException::what() const throw() {
    return message.c_str();
}
