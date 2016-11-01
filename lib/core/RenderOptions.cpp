/* Unknown Engine Project */

#include "unk/core/RenderOptions.h"
#include "unk/core/SDLFlagConverter.h"
#include "unk/utils/UnkExceptions.h"

unk::RenderOptions::RenderOptions() {
    DestPoint = { 0, 0 };
    RefPoint = { 0, 0 };
    SrcRect = { 0, 0, 0, 0 };
    DestRect = { 0, 0, 0, 0 };
    Angle = 0;
}

unk::RenderOptions& unk::RenderOptions::destPoint(Point dest) {
    DestPoint = dest;
    onPoint = true;
    onRect = false;
    return (*this);
}

unk::RenderOptions& unk::RenderOptions::srcRect(Rect src) {
    SrcRect = src;
    fromRect = true;
    return (*this);
}

unk::RenderOptions& unk::RenderOptions::destRect(Rect dest) {
    DestRect = dest;
    onRect = true;
    onPoint = false;
    return (*this);
}

unk::RenderOptions& unk::RenderOptions::rotate(Point ref, double angle) {
    RefPoint = ref;
    Angle = angle;
    return (*this);
}

unk::RenderOptions& unk::RenderOptions::flip(FlipFlags flag) {
    Flip.push_back(flag);
}

bool unk::RenderOptions::renderOnPoint() {
    return onPoint;
}

bool unk::RenderOptions::renderOnRect() {
    return onRect;
}

bool unk::RenderOptions::renderFromRect() {
    return fromRect;
}
