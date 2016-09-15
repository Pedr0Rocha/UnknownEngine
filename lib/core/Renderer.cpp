/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/core/Renderer.h"

unk::Renderer::Renderer() {
    // create renderer from window
}

SDL_Texture *unk::Renderer::createTextureFromSurface(SDL_Surface *surface) {
    return SDL_CreateTextureFromSurface(SDLRenderer, surface);
}
