/* Unknown Engine Project */

#include "unk/utils/Point.h"

unk::Point::Point() {
	X = 0;
	Y = 0;
}

unk::Point::Point(int x, int y) : X(x), Y(y) {
}

SDL_Point unk::Point::toSDLPoint() {
    SDL_Point point;
    point.x = this->X;
    point.y = this->Y;

    return point;
}
