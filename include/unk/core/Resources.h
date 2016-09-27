/* Unknown Engine Project */

#ifndef UNK_RESOURCES_H
#define UNK_RESOURCES_H

#include "SDL2/SDL.h"

#include "unk/core/TextureInfo.h"

#include <map>
#include <string>
#include <memory>

namespace unk {
    class Renderer;

    /**
     * @brief Class responsible for managing the resources of the program.
     *
     * @details It loads an @c SDL_Texture for each different file name. As it manages
     * all resources, it should be treated as a singleton class.
     */
    class Resources {
        private:
            std::map<TextureInfo, SDL_Texture*> Map;

        public:
            Resources();
            ~Resources();

            /// @brief Returns true if the texture is loaded.
            bool hasTexture(TextureInfo info);

            /// @brief Loads a texture if it has not already been loaded.
            void loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer);
            /// @brief Yields the @c width and @c height of the texture.
            void getTextureMeasures(TextureInfo info, int *width, int *height);
            /// @brief Destroys all previously loaded textures.
            void clear();

            /// @brief Returns the @c SDL_Texture related to @c info.
            SDL_Texture *getTexture(TextureInfo info);
    };
}

#endif
