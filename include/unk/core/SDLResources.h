/* Unknown Engine Project */

#ifndef UNK_SDL_RESOURCES_H
#define UNK_SDL_RESOURCES_H

#include "SDL2/SDL.h"

#include "unk/core/Resources.h"
#include "unk/core/Renderer.h"
#include "unk/core/TextureInfo.h"

#include <map>
#include <string>
#include <memory>

namespace unk {
    /**
     * @brief Class responsible for managing the resources of the program.
     *
     * @details It loads an @c SDL_Texture for each different file name. As it manages
     * all resources, it should be treated as a singleton class.
     */
    class SDLResources : public TResources<SDL_Texture*> {
        public:
            SDLResources();
            ~SDLResources();

            bool hasTexture(TextureInfo info) override;

            /// @brief Loads a texture if it has not already been loaded.
            void loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer);
            void getTextureMeasures(TextureInfo info, int *width, int *height);
            void destroyAll() override;

            /// @brief Returns the @c SDL_Texture related to @c info.
            SDL_Texture *getTexture(TextureInfo info) override;
    };

}

#endif
