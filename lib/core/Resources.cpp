/* Unknown Engine Project */

#include "SDL2/SDL_image.h"

#include "unk/core/Resources.h"

std::shared_ptr<unk::Resources> unk::Resources::ResourcesPtr = nullptr;

std::shared_ptr<unk::Resources> unk::Resources::getResources() {
    if (!ResourcesPtr.get())
        ResourcesPtr.reset(new Resources());

    return ResourcesPtr;
}

bool unk::Resources::hasTexture(TextureInfo info) {
    std::shared_ptr<Resources> resources = getResources();
    return resources->Map.count(info) > 0;
}

void unk::Resources::loadAllTextures(std::shared_ptr<Renderer> renderer) {
    std::shared_ptr<Resources> resources = getResources();
    for (auto mapPair : resources->Map) {
        if (!mapPair.second) {
            loadTexture(mapPair.first, renderer);
        }
    }
}

void unk::Resources::loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer) {
    std::shared_ptr<Resources> resources = getResources();

    registerTexture(info);

    if (!resources->Map[info]) {
        SDL_Surface *surface = IMG_Load(info.getName().c_str());
        SDL_Texture *texture = renderer->createTextureFromSurface(surface);
        resources->Map[info] = texture;
    }
}

void unk::Resources::registerTexture(TextureInfo info) {
    std::shared_ptr<Resources> resources = getResources();

    if (!resources->hasTexture(info))
        resources->Map[info] = nullptr;
}

SDL_Texture *unk::Resources::getTexture(TextureInfo info) {
    std::shared_ptr<Resources> resources = getResources();

    if (resources->hasTexture(info))
        return resources->Map[info];

    return nullptr;
}
