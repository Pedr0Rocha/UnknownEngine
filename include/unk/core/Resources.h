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
    /**
     * @brief Class responsible for managing the resources of the program.
     *
     * @details It loads an @c SDL_Texture for each different file name. As it manages
     * all resources, it is treated as a singleton class.
     *
     * The @c TextureInfo class is responsible for calling the @c registerTexture function
     * in order to register the texture, and to be loaded when @c loadAllTextures is called.
     */
    class Resources {
        private:
            std::map<TextureInfo, SDL_Texture*> Map;

            Resources();

        public:
            /// @brief Gets a singleton instance of the @c Resources class.
            static Resources& getResources();

            /// @brief Returns true if a texture with a specific name has already been registred.
            bool hasTexture(TextureInfo info);

            /// @brief Loads all registered textures.
            void loadAllTextures(std::shared_ptr<Renderer> renderer);
            /// @brief Loads a texture if it has not already been loaded.
            void loadTexture(TextureInfo info, std::shared_ptr<Renderer> renderer);
            /// @brief Register a texture if it has not already been.
            void registerTexture(TextureInfo info);
            /// @brief Yields the @c width and @c height of the texture.
            void getTextureMeasures(TextureInfo info, int *width, int *height);
            /// @brief Returns the @c SDL_Texture related to @c info.
            SDL_Texture *getTexture(TextureInfo info);
    };
}

#endif
