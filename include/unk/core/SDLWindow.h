/* Unknown Engine Project */

#ifndef UNK_SDL_WINDOW_H
#define UNK_SDL_WINDOW_H

#include "SDL2/SDL.h"

#include "unk/core/Window.h"

#include <cstdint>
#include <string>
#include <vector>

namespace unk {

    /**
     * @brief Wraps the SDL @a Kind of @a Window.
     *
     * @details Responsible for every function implemented with the @c SDLWindow.
     */
    class SDLWindow : public Window {
        private:
            SDL_Window *SDLw;
            std::string Title;
            int X;
            int Y;
            int Width;
            int Height;

        public:            

            /**
             * @brief The @c SDL_WindowFlags.
             */
            enum class Flags {
                OPENGL,         ///< Window usable with OPENGL context.
                BORDERLESS,     ///< No window decoration
                RESIZABLE,      ///< Window can be resized
            };

            SDLWindow(Kind kind);
            SDLWindow(std::string title, int x, int y, int width, int height, 
                std::vector<Flags> flags);
            SDLWindow(std::string title);
            SDLWindow(std::string title, int width, int height);

            ~SDLWindow() override;

            /// @brief
            void initWindow(std::string title, int x, int y, int width, int height, 
                std::vector<unk::SDLWindow::Flags> flags);
            /// @brief
            SDL_Renderer* createRenderer(int index, uint32_t flags);
            /// @brief Maximizes the window.
            void maximize() override;
            /// @brief Minimizes the window.
            void minimize() override;
            /// @brief Restores the window.
            void restore() override;

            /// @brief Sets the window into fullscreen mode.
            void setFullscreenMode() override;
            /// @brief Sets the window into windowed mode.
            void setWindowedMode() override;

            /// @brief Sets the title to @p title.
            void setTitle(std::string title) override;
            /// @brief Sets the icon to the icon whose name is @p iconName.
            void setIcon(std::string iconName) override;
            /// @brief Sets the size of the window to @p width x @p height.
            void setSize(uint32_t width, uint32_t height) override;
            /// @brief Sets the maximum size of the window to @p width x @p height.
            void setMaximumSize(uint32_t width, uint32_t height) override;
            /// @brief Sets the minimum size of the window to @p width x @p height.
            void setMinimumSize(uint32_t width, uint32_t height) override;
            /// @brief Sets the position of the window to (@p x, @p y).
            void setPosition(uint32_t x, uint32_t y) override;
            /// @brief Sets the brightness to @p brightness.
            void setBrightness(double brightness) override;

            /// @brief Draws the border of the window if @p on set.
            void drawBorder(bool on) override;

            /// @brief Returns a @c string with the title of the window.
            std::string getTitle() override;
            /// @brief Returns the @c x position of the window.
            uint32_t getX() override;
            /// @brief Returns the @c y position of the window.
            uint32_t getY() override;
            /// @brief Returns the @c width of the window.
            uint32_t getWidth() override;
            /// @brief Returns the @c height of the window.
            uint32_t getHeight() override;
            /// @brief Returns the @c brightness of the window.
            double getBrightness() override;
            
            /// @brief Returns true if @p base has the same kind as this.
            static bool isInstance(SDLWindow *base);

            Kind getKind() const;
    };
}

#endif
