/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/core/Renderer.h"
#include "unk/util/SDLException.h"

unk::Renderer::Renderer() {
    // create renderer from window
}

SDL_Texture *unk::Renderer::createTextureFromSurface(SDL_Surface *surface) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
    if (texture == nullptr)
        throw SDLException();

    return texture;
}
