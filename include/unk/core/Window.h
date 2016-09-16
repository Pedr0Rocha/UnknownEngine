/* Unknown Engine Project */

#ifndef UNK_WINDOW_H
#define UNK_WINDOW_H

#include "SDL2/SDL.h"

namespace unk {
	class Window {
		public:
			char* Title;
			int X;
			int Y;
			int Width;
			int Height;
			Uint32 Flags;
			SDL_Window* SDLWindow;

			Window(char* title, int x, int y, int width, int height, Uint32 flags);
			SDL_Renderer* CreateRenderer(int index, Uint32 flags);
			int SetWindowFullscreen();
			void MinimizeWindow();
			void MaximizeWindow();
			void RestoreWindow();
			void DestroyWindow();
	};
}

#endif
