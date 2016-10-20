/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/SDLInit.h"


uint32_t unk::toSDLFlag(SDLInitFlags flag) {
    switch (flag) {
        case Flags::TIMER:
            return SDL_INIT_TIMER;
        case Flags::AUDIO:
            return SDL_INIT_AUDIO;
        case Flags::VIDEO:
            return SDL_INIT_VIDEO;
        case Flags::JOYSTICK:
            return SDL_INIT_JOYSTICK;
        case Flags::HAPTIC:
            return SDL_INIT_HAPTIC;
        case Flags::GAMECONTROLLER:
            return SDL_INIT_GAMECONTROLLER;
        case Flags::EVENTS:
            return SDL_INIT_EVENTS;
        case Flags::EVERYTHING:
            return SDL_INIT_EVERYTHING;
        case Flags::NOPARACHUTE:
            return SDL_INIT_NOPARACHUTE;
        default:
            throw SDLException("Invalid SDL Init Flag.");
    }
}

uint32_t unk::toSDLFlags(std::vector<SDLInitFlags> flags) {
    uint32_t sdlFlags = 0;

    for (auto flag : flags) 
        sdlFlags |= toSDLFlag(flag);

    return sdlFlags;
}

void unk::InitializeSDL(std::vector<SDLInitFlags> flags) {
	uint32_t sdlFlags = unk::toSDLFlags(flags);
	int ret = SDL_Init(sdlFlags);

	if (ret)
		throw SDLException();
}
