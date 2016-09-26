/* Unknown Engine Project */

#ifndef UNK_COLOR_H
#define UNK_COLOR_H

#include <cstdint>

namespace unk {
    /**
     * @brief The @em RGBA color representation class.
     */
	class Color {
        public:
            uint8_t R;
            uint8_t G;
            uint8_t B;
            uint8_t A;

            Color();
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	};
}

#endif
