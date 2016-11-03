/* Unknown Engine Project */

#ifndef UNK_SDL_RENDERER_H
#define UNK_SDL_RENDERER_H

#include "unk/core/SDLResources.h"
#include "unk/core/TextureInfo.h"
#include "unk/utils/Point.h"
#include "unk/utils/Rect.h"
#include "unk/utils/Color.h"

#include <vector>
#include <memory>

class SDL_Renderer;

namespace unk {

    /**
     * @brief Wraps the SDL equivalent (@c SDL_Renderer).
     *
     * @details Is responsible for every function implemented
     * with the @c SDL_Renderer.
     */
    class SDLRenderer : public Renderer {
        private:
            SDL_Renderer *SDLr;
            SDL_RendererInfo Info;
            Color DrawColor;

            std::shared_ptr<unk::SDLResources> Res;

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

            /// @brief Creates a @c Renderer with a @c Window and standard 
            /// flags (ACCELERATED).
            SDLRenderer(std::shared_ptr<SDLResources> res);
            /// @brief Creates a customized @c Renderer with custom flags.
            SDLRenderer(std::shared_ptr<SDLResources> res, std::vector<Flags> flags);

            ~SDLRenderer();

            uint32_t getMaxTextureWidth() override;
            uint32_t getMaxTextureHeight() override;

            void clear() override;

            void drawTexture(TextureInfo info, RenderOptions opt = RenderOptions()) override;

            void setDrawColor(Color color) override;
            Color getDrawColor() override;

            void drawPoints(std::vector<Point> points) override;
            void drawLines(std::vector<Point> points) override;
            void drawRects(std::vector<Rect> rects, bool fill = false,
                    bool sameColor = true, Color color = { 0, 0, 0, 0 }) override;

            void render() override;

            /// @brief Creates a texture from a surface.
            SDL_Texture *createTextureFromSurface(SDL_Surface *surface);

            /// @brief Returns true if @p base has the same kind as this.
            static bool isInstance(const Renderer *base);

        private:
            void initSDLRenderer(std::vector<Flags> flags);
            void setRenderDrawColor(Color color);

    };
}

#endif
