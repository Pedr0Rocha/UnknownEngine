/* Unknown Engine Project */

#include "SDL2/SDL_image.h"

#include "unk/core/Resources.h"
#include "unk/core/Renderer.h"
#include "unk/utils/SDLException.h"

unk::Resources::Resources() {
}

unk::Resources::~Resources() {
    clear();
}

bool unk::Resources::hasTexture(TextureInfo info) {
    return Map.count(info) > 0;
}

void unk::Resources::loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer) {
    if (!hasTexture(info))
        Map[info] = nullptr;

    if (!Map[info]) {

        SDL_Surface *surface = nullptr;
        SDL_Texture *texture = nullptr;

        try {
            surface = IMG_Load(info.getFilename().c_str());
            if (surface == nullptr)
                throw SDLException();

            texture = renderer->createTextureFromSurface(surface);
            Map[info] = texture;

        } catch (SDLException e) {
            // Handle the error
        }

    }
}

void unk::Resources::getTextureMeasures(TextureInfo info, int *width, int *height) {
    if (hasTexture(info) && Map[info])
        SDL_QueryTexture(Map[info], nullptr, nullptr, width, height);
}

void unk::Resources::clear() {
    for (auto pair : Map) {
        if (pair.second) 
            SDL_DestroyTexture(pair.second);
    }

    Map.clear();
}

SDL_Texture *unk::Resources::getTexture(TextureInfo info) {
    if (hasTexture(info))
        return Map[info];

    return nullptr;
}
