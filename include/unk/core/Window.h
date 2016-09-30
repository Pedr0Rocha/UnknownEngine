/* Unknown Engine Project */

#ifndef UNK_WINDOW_H
#define UNK_WINDOW_H

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
            Window() = delete;

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

    };
}

#endif
