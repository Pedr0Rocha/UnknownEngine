/* Unknown Engine Project */

#ifndef UNK_RENDERER_H
#define UNK_RENDERER_H

#include "unk/core/TextureInfo.h"
#include "unk/utils/Point.h"
#include "unk/utils/Rect.h"

#include <vector>

class SDL_Renderer;

namespace unk {

    /**
     * @brief Wraps the SDL equivalent (@c SDL_Renderer).
     *
     * @details Is responsible for every function implemented
     * with the @c SDL_Renderer.
     */
    class Renderer {
        private:
            SDL_Renderer *SDLRenderer;
            SDL_RendererInfo Info;

        public:
            /**
             * @brief The @c SDL_RendererFlags.
             */
            enum class Flags {
                SOFTWARE,       ///< Software fallback.
                ACCELERATED,    ///< Uses hardware acceleration.
                VSYNC,          ///< Synchronizes the refresh rate.
                TEXTURE         ///< Render to texture.
            };

            /**
             * @brief Indicates whether the @c Renderer should flip the
             * image or not.
             */
            enum class Flip {
                NONE,       ///< No flip.
                HORIZONTAL, ///< Flip horizontally.
                VERTICAL    ///< Flip vertically.
            };

            /// @brief Creates a @c Renderer with a @c Window and standard 
            /// flags (ACCELERATED).
            Renderer();
            /// @brief Creates a customized @c Renderer with custom flags.
            Renderer(std::vector<Flags> flags);

            ~Renderer();

            /// @brief Gets the maximum texture width.
            int getMaxTextureWidth();
            /// @brief Gets the maximum texture height.
            int getMaxTextureHeight();

            /// @brief Clears the current rendering target.
            void clear();

            /// @brief Renders the texture at the point @p dest.
            void renderTexture(TextureInfo info, Point dest);
            /// @brief Renders the texture at the point @p dest rotated by
            /// @p angle degrees.
            void renderTexture(TextureInfo info, Point dest, double angle,
                    Point ref);
            /// @brief Renders the texture at the point @p dest flipped as
            /// specified in the vector @p flip.
            void renderTexture(TextureInfo info, Point dest,
                    std::vector<Flip> flip);
            /// @brief Renders the texture at the point @p dest rotated by
            /// @p angle degrees and flipped as specified in @p flip.
            void renderTexture(TextureInfo info, Point dest, double angle,
                    Point ref, std::vector<Flip> flip);

            /// @brief Renders the texture inside the rectangle @p srcR
            /// into @p dstR.
            void renderTexture(TextureInfo info, Rect srcR, Rect dstR);
            /// @brief Renders the texture inside the rectangle @p srcR
            /// into @p dstR rotated by @p angle degrees.
            void renderTexture(TextureInfo info, Rect srcR, Rect dstR,
                    double angle, Point ref);
            /// @brief Renders the texture inside the rectangle @p srcR
            /// into @p dstR flipped as specified in @p flip.
            void renderTexture(TextureInfo info, Rect srcR, Rect dstR,
                    std::vector<Flip> flip);
            /// @brief Renders the texture inside the rectangle @p srcR
            /// into @p dstR rotated by @p angle degrees and flipped as
            /// specified in @p flip.
            void renderTexture(TextureInfo info, Rect srcR, Rect dstR,
                    double angle, Point ref, std::vector<Flip> flip);

            /// @brief Creates a texture from a surface.
            SDL_Texture *createTextureFromSurface(SDL_Surface *surface);

        private:
            void initRenderer(std::vector<Flags> flags);
            void renderTextureImpl(TextureInfo info, Rect srcR, Rect dstR, 
                    double angle, Point ref, std::vector<Flip> flip);

            uint32_t toSDLFlag(Flags flag);
            uint32_t toSDLFlags(std::vector<Flags> flags);
            uint32_t toSDLRendererFlip(std::vector<Flip> flip);
    };
}

#endif
