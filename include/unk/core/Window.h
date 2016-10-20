/* Unknown Engine Project */

#ifndef UNK_WINDOW_H
#define UNK_WINDOW_H

<<<<<<< HEAD
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
            uint32_t toSDLFlag(Flags flag);
=======
#include <cstdint>
#include <string>

namespace unk {

    /**
     * @brief Abstract class with the basic functions of windows
     * in general.
     *
     * @details This abstract class has no attributes. Even though it
     * resembles an interface, all methods but the constructor are
     * already implmented.
     *
     * As all member functions are implemented, one @c Window class does
     * not have to @em override all of them.
     *
     * Notice that the member functions are implemented by throwing a
     * @c FunctionNotImplementedException.
     */
    class Window {
        public:
            /**
             * @brief Enum with all kinds of @c Window available.
             */
            enum class Kind {
            };

        protected:
            Kind K;

            Window(Kind kind);

        public:
            virtual ~Window();

            /// @brief Maximizes the window.
            virtual void maximize();
            /// @brief Minimizes the window.
            virtual void minimize();
            /// @brief Restores the window.
            virtual void restore();

            /// @brief Sets the window into fullscreen mode.
            virtual void setFullscreenMode();
            /// @brief Sets the window into windowed mode.
            virtual void setWindowedMode();

            /// @brief Sets the title to @p title.
            virtual void setTitle(std::string title);
            /// @brief Sets the icon to the icon whose name is @p iconName.
            virtual void setIcon(std::string iconName);
            /// @brief Sets the size of the window to @p width x @p height.
            virtual void setSize(uint32_t width, uint32_t height);
            /// @brief Sets the maximum size of the window to @p width x @p height.
            virtual void setMaximumSize(uint32_t width, uint32_t height);
            /// @brief Sets the minimum size of the window to @p width x @p height.
            virtual void setMinimumSize(uint32_t width, uint32_t height);
            /// @brief Sets the position of the window to (@p x, @p y).
            virtual void setPosition(uint32_t x, uint32_t y);
            /// @brief Sets the opacity to @p opacity.
            virtual void setOpacity(double opacity);
            /// @brief Sets the brightness to @p brightness.
            virtual void setBrightness(double brightness);

            /// @brief Draws the border of the window if @p on set.
            virtual void drawBorder(bool on);

            /// @brief Returns a @c string with the title of the window.
            virtual std::string getTitle();
            /// @brief Returns the @c x position of the window.
            virtual uint32_t getX();
            /// @brief Returns the @c y position of the window.
            virtual uint32_t getY();
            /// @brief Returns the @c width of the window.
            virtual uint32_t getWidth();
            /// @brief Returns the @c height of the window.
            virtual uint32_t getHeight();
            /// @brief Returns the @c opacity of the window.
            virtual double getOpacity();
            /// @brief Returns the @c brightness of the window.
            virtual double getBrightness();

            Kind getKind() const;

>>>>>>> 5caa98a4224788f8448c147f6edf86ce7a5b5446
    };
}

#endif
