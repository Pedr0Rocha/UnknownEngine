/* Unknown Engine Project */

#ifndef UNK_WINDOW_H
#define UNK_WINDOW_H

#include "SDL2/SDL.h"

#include <string>
#include <vector>

namespace unk {

    
    /**
    * @brief Wraps the SDL equivalent (@c SDL_Window).
    *
    * @details Is responsible for every function implemented
    * with the @c SDL_Window.
    */
    class Window {
        
    public:

            /**
             * @brief The @c SDL_WindowFlags.
            */
             enum class Flags { 
                OPENGL,         ///< Window usable with OpenGL context.
                BORDERLESS,     ///< No window decoration.
                RESIZABLE       ///< Window can be resized.
            };

            std::string Title;
            int X;
            int Y;
            int Width;
            int Height;
            SDL_Window* SDLWindow;


            /// @brief Creates a fully customized @c Window.
            Window(std::string title, int x, int y, int width, int height, std::vector<Flags> flags);
            /// @brief Creates a standard @c Window.
            Window(std::string title);
            /// @brief Creates a customized @c Window with width and height set
            /// and standard flags.  
            Window(std::string title, int width, int height);

            ~Window();

            /// @brief Creates a @c Renderer from a @c Window.
            SDL_Renderer* createRenderer(int index, uint32_t flags);

            /// @brief Use this function to set the current @c Window
            /// to Fullscreen mode.
            void setWindowFullscreen();
            /// @brief Use this function to set the current @c Window
            /// to Fake Fullscreen mode. It takes the size of the desktop.
            void setWindowFakeFullscreen();
            /// @brief Use this function to minimize the current @c Window.
            void minimizeWindow();
            /// @brief Use this function to maximize the current @c Window.
            void maximizeWindow();
            /// @brief Use this function to restore the current @c Window.
            void restoreWindow();

        private:
            /// @brief Resposible for initializing and creating the @c SDL_Window
            /// from the @c Window constructor.
            void initWindow(std::string title, int x, int y, int width, int height, 
                std::vector<Flags> flags);
            
            /// @brief Converts @c Window Flags to @c SDL_WindowFlags
            uint32_t toSDLFlags(std::vector<Flags> flags);
            /// @brief Converts a single @c Window Flag to its correspondent @c SDL_WindowFlag
            uint32_t unk::Window::toSDLFlag(Flags flag);
        };
    }

#endif
