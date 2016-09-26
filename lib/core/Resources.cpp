/* Unknown Engine Project */

#include "SDL2/SDL_image.h"

#include "unk/core/Resources.h"
#include "unk/utils/SDLException.h"

unk::Resources::Resources() {
}

unk::Resources& unk::Resources::getResources() {
    static Resources resources;
    return resources;
}

bool unk::Resources::hasTexture(TextureInfo info) {
    return Map.count(info) > 0;
}

void unk::Resources::loadAllTextures(std::shared_ptr<Renderer> renderer) {
    for (auto mapPair : Map) {
        if (!mapPair.second) {
            loadTexture(mapPair.first, renderer);
        }
    }
}

void unk::Resources::loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer) {
    registerTexture(info);

    if (!Map[info]) {

        SDL_Surface *surface = nullptr;
        SDL_Texture *texture = nullptr;

        try {
            surface = IMG_Load(info.getName().c_str());
            if (surface == nullptr)
                throw SDLException();

            texture = renderer->createTextureFromSurface(surface);
            Map[info] = texture;

        } catch (SDLException e) {
            // Handle the error
        }

    }
}

void unk::Resources::registerTexture(TextureInfo info) {
    if (!hasTexture(info))
        Map[info] = nullptr;
}

void unk::Resources::getTextureMeasures(TextureInfo info, int *width, int *height) {
    if (hasTexture(info) && Map[info])
        SDL_QueryTexture(Map[info], nullptr, nullptr, width, height);
}

SDL_Texture *unk::Resources::getTexture(TextureInfo info) {
    if (hasTexture(info))
        return Map[info];

    return nullptr;
}
