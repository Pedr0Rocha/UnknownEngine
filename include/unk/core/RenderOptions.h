/* Unknown Engine Project */

#ifndef UNK_RENDER_OPTIONS_H
#define UNK_RENDER_OPTIONS_H

#include "unk/utils/Point.h"
#include "unk/utils/Rect.h"

#include <vector>

namespace unk {

    /**
     * @brief This is a package with information for rendering.
     *
     * This class is implemented with the flow design pattern.
     */
    class RenderOptions {
        public:
            /**
             * Flags for renderizing the texture flipped.
             */
            enum class FlipFlags {
                NONE,
                HORIZONTAL,
                VERTICAL
            };

        private:
            Point DestPoint;
            Point RefPoint;
            double Angle;
            std::vector<FlipFlags> Flip;
            Rect SrcRect;
            Rect DestRect;

            bool onPoint;
            bool onRect;
            bool fromRect;

        public:
            RenderOptions();

            /// @brief Defines a destination point reference for rendering on.
            RenderOptions& destPoint(Point dest);
            /// @brief Defines a source rectangle reference for rendering from.
            RenderOptions& srcRect(Rect src);
            /// @brief Defines a destination rectangle reference for rendering on.
            RenderOptions& destRect(Rect dest);
            /// @brief Defines an angle of rotation and its reference.
            RenderOptions& rotate(Point ref, double angle);
            /// @brief Defines a @a FlipFlags (can be called more than once).
            RenderOptions& flip(FlipFlags flag);

            /// @brief Gets the destination reference point.
            Point getDestPoint();
            /// @brief Gets the rotation reference point.
            Point getRefPoint();
            /// @brief Gets the angle of rotation.
            double getAngle();
            /// @brief Gets a @a FlipFlags vector.
            std::vector<FlipFlags>& getFlip();
            /// @brief Gets the source reference rectangle.
            Rect getSrcRect();
            /// @brief Gets the destination reference rectangle.
            Rect getDestRect();

            /// @brief Returns true if it should be rendered on @em DestPoint.
            bool renderOnPoint();
            /// @brief Returns true if it should be rendered on @em DestRect.
            bool renderOnRect();
            /// @brief Returns true if it should be rendered from @em SrcRect.
            bool renderFromRect();

    };

}

#endif
