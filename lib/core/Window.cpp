/* Unknown Engine Project */

#include "unk/core/Window.h"

unk::Window::Window(char* title, int x, int y, int width, int height, Uint32 flags) : 
					Title(title), X(x), Y(y), Width(width), Height(height), Flags(flags) {

	SDL_Window *sdlWindow;
	SDL_Init(SDL_INIT_VIDEO);

	sdlWindow = SDL_CreateWindow(title, x, y, width, height, flags);
	SDLWindow = sdlWindow;
}

SDL_Renderer* unk::Window::CreateRenderer(int index, Uint32 flags) {
	SDL_Renderer* renderer = SDL_CreateRenderer(SDLWindow, index, flags);
	return renderer;
}

void unk::Window::DestroyWindow() {
	SDL_DestroyWindow(SDLWindow);
}
