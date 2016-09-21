/* Unknown Engine Project */

#ifndef UNK_WINDOW_H
#define UNK_WINDOW_H

#include "SDL2/SDL.h"

#include <string>
#include <vector>

namespace unk {


	enum class WindowFlags { OPENGL, BORDERLESS, RESIZABLE };

	class Window {
		public:
			std::string Title;
			int X;
			int Y;
			int Width;
			int Height;
			SDL_Window* SDLWindow;

			Window(std::string title, int x, int y, int width, int height, std::vector<WindowFlags> flags);
			Window(std::string title);
			Window(std::string title, int width, int height);

			~Window();
			
			void initWindow(std::string title, int x, int y, int width, int height, 
				std::vector<WindowFlags> flags);

			SDL_Renderer* createRenderer(int index, uint32_t flags);
			void setWindowFullscreen();
			void setWindowFakeFullscreen();
			void minimizeWindow();
			void maximizeWindow();
			void restoreWindow();

		private:
			uint32_t toSDLFlags(std::vector<WindowFlags> flags);
	};
}

#endif
