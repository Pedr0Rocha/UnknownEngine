/* Unknown Engine Project */

#ifndef UNK_POINT_H
#define UNK_POINT_H

#include "SDL2/SDL_rect.h"

namespace unk {
    /**
     * @brief An abstracted ordered pair.
     */
	class Point {
        public:
            int X;
            int Y;

            Point();
            Point(int x, int y);

            SDL_Point toSDLPoint();
	};

}

#endif
