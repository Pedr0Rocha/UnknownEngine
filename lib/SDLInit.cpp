/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/SDLInit.h"

static SDLFlagConverter<SDLInitFlags> flagConverter = { 
	{ SDLInitFlags::TIMER, SDL_INIT_TIMER },
	{ SDLInitFlags::AUDIO, SDL_INIT_AUDIO },
	{ SDLInitFlags::VIDEO, SDL_INIT_VIDEO },
	{ SDLInitFlags::JOYSTICK, SDL_INIT_JOYSTICK },
	{ SDLInitFlags::HAPTIC, SDL_INIT_HAPTIC },
	{ SDLInitFlags::GAMECONTROLLER, SDL_INIT_GAMECONTROLLER },
	{ SDLInitFlags::EVENTS, SDL_INIT_EVENTS },
	{ SDLInitFlags::EVERYTHING, SDL_INIT_EVERYTHING },
	{ SDLInitFlags::NOPARACHUTE, SDL_INIT_NOPARACHUTE },
};

void unk::InitializeSDL(std::vector<SDLInitFlags> flags) {
	uint32_t sdlFlags = flagConverter.toSDLFlags(flags);
	int ret = SDL_Init(sdlFlags);

	if (ret)
		throw SDLException();
}
