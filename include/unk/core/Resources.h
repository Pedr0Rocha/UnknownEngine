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
            std::map<TextureInfo, SDL_Texture*> Map;

            Resources();

        public:
            static Resources& getResources();

            bool hasTexture(TextureInfo info);

            void loadAllTextures(std::shared_ptr<Renderer> renderer);
            void loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer);
            void registerTexture(TextureInfo info);
            void getTextureMeasures(TextureInfo info, int *width, int *height);
            SDL_Texture *getTexture(TextureInfo info);
    };
}

#endif
