/* Unknown Engine Project */

#include "unk/core/SDLConverter.h"
#include "unk/utils/UnkExceptions.h"

SDL_Point unk::toSDL(Point point) {
    SDL_Point sdlPoint;
    sdlPoint.x = point.X;
    sdlPoint.y = point.Y;
    return sdlPoint;
}

SDL_Rect unk::toSDL(Rect rect) {
    SDL_Rect sdlRect;
    sdlRect.x = rect.X;
    sdlRect.y = rect.Y;
    sdlRect.w = rect.Width;
    sdlRect.h = rect.Height;
    return sdlRect;
}
