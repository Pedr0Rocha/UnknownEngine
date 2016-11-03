/* Unknown Engine Project */

#ifndef UNK_RECT_H
#define UNK_RECT_H

#include "SDL2/SDL_rect.h"

namespace unk {
	class Rect {
		public:
			int X;
			int Y;
			int Width;
			int Height;

			Rect();
			Rect(int x, int y, int width, int height);
	};
}

#endif
