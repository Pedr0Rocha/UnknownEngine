/* Unknown Engine Project */

#include "SDL2/SDL_image.h"

#include "unk/Unknown.h"
#include "unk/core/SDLResources.h"
#include "unk/core/SDLRenderer.h"
#include "unk/utils/SDLException.h"

#include <cassert>

unk::SDLResources::SDLResources() : TResources<SDL_Texture*>(Resources::Kind::SDL) {
}

unk::SDLResources::~SDLResources() {
    destroyAll();
}

bool unk::SDLResources::hasTexture(TextureInfo info) {
    return Map.count(info) > 0;
}

void unk::SDLResources::loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer) {
    assert(isInstanceOf<SDLRenderer>(renderer.get()) && 
            "Renderer must be a SDLRenderer.");
    SDLRenderer *sdlRenderer = getInstanceOf<SDLRenderer>(renderer.get());

    if (!hasTexture(info))
        Map[info] = nullptr;

    if (!Map[info]) {

        SDL_Surface *surface = nullptr;
        SDL_Texture *texture = nullptr;

        try {
            surface = IMG_Load(info.getFilename().c_str());
            if (surface == nullptr)
                throw SDLException();

            texture = sdlRenderer->createTextureFromSurface(surface);
            Map[info] = texture;

        } catch (SDLException e) {
            // Handle the error
        }

    }
}

void unk::SDLResources::getTextureMeasures(TextureInfo info, int *width, int *height) {
    if (hasTexture(info) && Map[info])
        SDL_QueryTexture(Map[info], nullptr, nullptr, width, height);
}

void unk::SDLResources::destroyAll() {
    for (auto pair : Map) {
        if (pair.second) 
            SDL_DestroyTexture(pair.second);
    }

    Map.clear();
}

SDL_Texture *unk::SDLResources::getTexture(TextureInfo info) {
    if (hasTexture(info))
        return Map[info];

    return nullptr;
}
