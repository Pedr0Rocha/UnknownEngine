/* Unknown Engine Project */

#include "unk/core/Window.h"

unk::Window::Window(std::string title, int x, int y, int width, int height, 
	std::vector<WindowFlags> flags) : Title(title), X(x), Y(y), Width(width), Height(height) {
	
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
	std::vector<WindowFlags> flags) {
	
	SDL_Window *sdlWindow;

	uint32_t sdlFlags = unk::Window::toSDLFlags(flags);
	
	sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, sdlFlags);
	SDLWindow = sdlWindow;
}

SDL_Renderer* unk::Window::createRenderer(int index, uint32_t flags) {
	SDL_Renderer *renderer = SDL_CreateRenderer(SDLWindow, index, flags);
	return renderer;
}

uint32_t unk::Window::toSDLFlags(std::vector<WindowFlags> flags) {
	uint32_t sdlFlags = 0;
	for (auto flag : flags) {
		if (flag == WindowFlags::OPENGL) 		  
			sdlFlags |= SDL_WINDOW_OPENGL;
		else if (flag == WindowFlags::BORDERLESS) 
			sdlFlags |= SDL_WINDOW_BORDERLESS;
		else if (flag == WindowFlags::RESIZABLE)  
			sdlFlags |= SDL_WINDOW_RESIZABLE;
	}
	return sdlFlags;
}

void unk::Window::setWindowFullscreen() {
	SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN);
}

void unk::Window::setWindowFakeFullscreen() {
	SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
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
