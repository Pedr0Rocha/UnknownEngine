/* Unknown Engine Project */

#include "unk/utils/Color.h"

unk::Color::Color() {
    R = 0;
    G = 0;
    B = 0;
    A = 0;
}

unk::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
R(r), G(g), B(b), A(a) {
}
