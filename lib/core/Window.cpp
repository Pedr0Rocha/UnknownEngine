/* Unknown Engine Project */

#include "unk/core/Window.h"

unk::Window::Window(std::string title, int x, int y, int width, int height, 
	std::vector<Flags> flags) : Title(title), X(x), Y(y), Width(width), Height(height) {
	
	unk::Window::initWindow(title, x, y, width, height, flags);
}

unk::Window::Window(std::string title) : Title(title) {
    unk::Window::initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, {});
}

unk::Window::Window(std::string title, int width, int height) : Title(title), 
	Width(width), Height(height) {

    unk::Window::initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    	width, height, {});
}

unk::Window::~Window() {
	SDL_DestroyWindow(SDLWindow);
}

void unk::Window::initWindow(std::string title, int x, int y, int width, int height, 
	std::vector<Flags> flags) {
	
	SDL_Window *sdlWindow;

	uint32_t sdlFlags = unk::Window::toSDLFlags(flags);
	
	sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, sdlFlags);

	if (sdlWindow == nullptr) 
		throw SDLException();
	
	SDLWindow = sdlWindow;
}

SDL_Renderer* unk::Window::createRenderer(int index, uint32_t flags) {
	SDL_Renderer *renderer = SDL_CreateRenderer(SDLWindow, index, flags);

	if (renderer == nullptr)
		throw SDLException();

	return renderer;
}

uint32_t unk::Window::toSDLFlag(Flags flag) {
    switch (flag) {
        case Flags::OPENGL:
            return SDL_WINDOW_OPENGL;
        case Flags::BORDERLESS:
            return SDL_WINDOW_BORDERLESS;
        case Flags::RESIZABLE:
            return SDL_WINDOW_RESIZABLE;
        default:
            throw SDLException("Invalid Window Flag.");
    }
}

uint32_t unk::Window::toSDLFlags(std::vector<Flags> flags) {
	uint32_t sdlFlags = 0;
	
	for (auto flag : flags) 
		sdlFlags |= toSDLFlag(flag);

	return sdlFlags;
}

void unk::Window::setWindowFullscreen() {
	int ret = SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN);

	if (ret < 0)
		throw SDLException();
}

void unk::Window::setWindowFakeFullscreen() {
	int ret = SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

	if (ret < 0)
		throw SDLException();
}

void unk::Window::minimizeWindow() {
	SDL_MinimizeWindow(SDLWindow);
}

void unk::Window::maximizeWindow() {
	SDL_MaximizeWindow(SDLWindow);
}

void unk::Window::restoreWindow() {
	SDL_RestoreWindow(SDLWindow);
}
