/* Unknown Engine Project */

#ifndef UNK_RESOURCES_H
#define UNK_RESOURCES_H

#include "SDL2/SDL.h"

#include "unk/core/TextureInfo.h"
#include "unk/core/Renderer.h"

#include <map>
#include <string>
#include <memory>

namespace unk {
    class Resources {
        private:
            static std::shared_ptr<Resources> ResourcesPtr;
            std::map<TextureInfo, SDL_Texture*> Map;

            static std::shared_ptr<Resources> getResources();
            bool hasTexture(TextureInfo info);

        public:
            static void loadAllTextures(std::shared_ptr<Renderer> renderer);
            static void loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer);
            static void registerTexture(TextureInfo info);
            static SDL_Texture *getTexture(TextureInfo info);
    };
}

#endif
