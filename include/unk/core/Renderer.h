/* Unknown Engine Project */

#ifndef UNK_RENDERER_H
#define UNK_RENDERER_H

#include "unk/core/Resources.h"
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
    class Renderer {
        private:
            SDL_Renderer *SDLRenderer;
            SDL_RendererInfo Info;
            Color DrawColor;

            std::shared_ptr<unk::Resources> Res;

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
            Renderer(std::shared_ptr<Resources> res);
            /// @brief Creates a customized @c Renderer with custom flags.
            Renderer(std::shared_ptr<Resources> res, std::vector<Flags> flags);

            ~Renderer();

            /// @brief Gets the maximum texture width.
            int getMaxTextureWidth();
            /// @brief Gets the maximum texture height.
            int getMaxTextureHeight();

            /// @brief Clears the current rendering target.
            void clear();

            /// @brief Draws the texture at the point @p dest.
            void drawTexture(TextureInfo info, Point dest);
            /// @brief Draws the texture at the point @p dest rotated by
            /// @p angle degrees.
            void drawTexture(TextureInfo info, Point dest, double angle,
                    Point ref);
            /// @brief Draws the texture at the point @p dest flipped as
            /// specified in the vector @p flip.
            void drawTexture(TextureInfo info, Point dest,
                    std::vector<Flip> flip);
            /// @brief Draws the texture at the point @p dest rotated by
            /// @p angle degrees and flipped as specified in @p flip.
            void drawTexture(TextureInfo info, Point dest, double angle,
                    Point ref, std::vector<Flip> flip);

            /// @brief Draws the texture inside the rectangle @p srcR
            /// into @p dstR.
            void drawTexture(TextureInfo info, Rect srcR, Rect dstR);
            /// @brief Draws the texture inside the rectangle @p srcR
            /// into @p dstR rotated by @p angle degrees.
            void drawTexture(TextureInfo info, Rect srcR, Rect dstR,
                    double angle, Point ref);
            /// @brief Draws the texture inside the rectangle @p srcR
            /// into @p dstR flipped as specified in @p flip.
            void drawTexture(TextureInfo info, Rect srcR, Rect dstR,
                    std::vector<Flip> flip);
            /// @brief Draws the texture inside the rectangle @p srcR
            /// into @p dstR rotated by @p angle degrees and flipped as
            /// specified in @p flip.
            void drawTexture(TextureInfo info, Rect srcR, Rect dstR,
                    double angle, Point ref, std::vector<Flip> flip);

            /// @brief Sets the drawing color.
            void setDrawColor(Color color);
            /// @brief Returns the drawing color.
            Color getDrawColor();

            /// @brief Draw the @p Point objects specified.
            void drawPoints(std::vector<Point> points);
            /// @brief Draw the lines specified by each two @p Point objects.
            void drawLines(std::vector<Point> points);
            /// @brief Draw the @p Rect objects specified.
            void drawRects(std::vector<Rect> rects, bool fill = false,
                    bool sameColor = true, Color color = { 0, 0, 0, 0 });

            /// @brief Actually renders the intern buffer into the Window.
            void render();

            /// @brief Creates a texture from a surface.
            SDL_Texture *createTextureFromSurface(SDL_Surface *surface);

        private:
            void initRenderer(std::vector<Flags> flags);
            void setRenderDrawColor();
            void drawTextureImpl(TextureInfo info, Rect srcR, Rect dstR, 
                    double angle, Point ref, std::vector<Flip> flip);

            uint32_t toSDLFlag(Flags flag);
            uint32_t toSDLFlags(std::vector<Flags> flags);
            uint32_t toSDLRendererFlip(std::vector<Flip> flip);
    };
}

#endif
