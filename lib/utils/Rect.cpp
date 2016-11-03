/* Unknown Engine Project */

#include "unk/utils/Rect.h"

unk::Rect::Rect() {
	X = 0;
	Y = 0;
	Width = 0;
	Height = 0;
}

unk::Rect::Rect(int x, int y, int width, int height) : X(x), Y(y), Width(width), Height(height) {

}

