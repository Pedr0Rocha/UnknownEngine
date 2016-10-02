/* Unknown Engine Project */

#ifndef UNK_RENDERER_H
#define UNK_RENDERER_H

#include "unk/core/TextureInfo.h"
#include "unk/core/RenderOptions.h"
#include "unk/utils/Color.h"
#include "unk/utils/Point.h"
#include "unk/utils/Rect.h"

#include <vector>

namespace unk {

    /**
     * @brief Abstract renderer class that declares all the basic 
     * functions of a renderer.
     *
     * @details This class should be the base class of every implemented
     * renderer. The child class may choose not to implement every
     * function declared here (as they are already implemented). Their
     * default behaviour is throwing a FunctionNotImplementedException.
     */
    class Renderer {
        public:
            /**
             * @brief Enum with all kinds of @em Renderer available.
             */
            enum class Kind {
            };

        protected:
            Kind K;

            Renderer(Kind kind);

        public:
            virtual ~Renderer();

            /// @brief Gets the maximum width of a texture.
            uint32_t getMaxTextureWidth();
            /// @brief Gets the maximum height of a texture.
            uint32_t getMaxTextureHeight();

            /// @brief Clears the current rendering target.
            void clear();

            /// @brief Draws a texture whose info is @p info, with @p opt options.
            void drawTexture(TextureInfo info, RenderOptions opt = RenderOptions());
            /// @brief Sets the drawing color.
            void setDrawColor(Color color);
            /// @brief Gets the drawing color.
            Color getDrawColor();

            /// @brief Draw the @p Point objects specified.
            void drawPoints(std::vector<Point> points);
            /// @brief Draw the lines specified by each two @p Point objects.
            void drawLines(std::vector<Point> points);

            /** 
             * @brief Draw the @p Rect objects specified.
             *
             * @details if @p fill is set, it will fill the rectangles
             * with the same color.
             *
             * @p sameColor and @p color will only be taken into account
             * if @p fill is set to @c true. 
             *
             * @p sameColor specifies wheather the filling color will 
             * be the same as the drawing color. If @p false, @p color
             * specifies de color.
             */
            void drawRects(std::vector<Rect> rects, bool fill = false,
                    bool sameColor = true, Color color = Color());

            /// @brief Actually renders the intern buffer into the Window.
            void render();

            /// @brief Gets the @c Renderer kind. Is called by isInstanceOf.
            Kind getKind() const;
            
    };
}

#endif
