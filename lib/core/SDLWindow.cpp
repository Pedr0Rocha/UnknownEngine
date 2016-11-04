/* Unknown Engine Project */

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "unk/core/SDLWindow.h"
#include "unk/core/SDLConverter.h"
#include "unk/core/Window.h"
#include "unk/core/Resources.h"
#include "unk/utils/SDLException.h"

#include <vector>
#include <memory>

static unk::SDLFlagConverter<unk::SDLWindow::Flags> flagConverter = {
    { unk::SDLWindow::Flags::OPENGL,        SDL_WINDOW_OPENGL           },
    { unk::SDLWindow::Flags::BORDERLESS,    SDL_WINDOW_BORDERLESS       },
    { unk::SDLWindow::Flags::RESIZABLE,     SDL_WINDOW_RESIZABLE        },
};

unk::SDLWindow::SDLWindow(std::string title, int x, int y, int width, int height, 
    std::vector<unk::SDLWindow::Flags> flags) : Window(Window::Kind::SDL), 
    Title(title), X(x), Y(y), Width(width), Height(height) {
    
    initWindow(title, x, y, width, height, flags);
}

unk::SDLWindow::SDLWindow(std::string title) : Window(Window::Kind::SDL), Title(title) {
    initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, {});
}

unk::SDLWindow::SDLWindow(std::string title, int width, int height) : Window(Window::Kind::SDL), 
    Title(title), Width(width), Height(height) {

    initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, {});
}

unk::SDLWindow::~SDLWindow() {
    SDL_DestroyWindow(SDLw);
}

void unk::SDLWindow::initWindow(std::string title, int x, int y, int width, int height, 
    std::vector<unk::SDLWindow::Flags> flags) {
    
    SDL_Window *sdlWindow;

    uint32_t sdlFlags = flagConverter.toSDLFlags(flags);

    sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, sdlFlags);

    if (sdlWindow == nullptr) 
        throw SDLException();

    SDLw = sdlWindow;
}

SDL_Renderer* unk::SDLWindow::createRenderer(int index, uint32_t flags) {
    SDL_Renderer *renderer = SDL_CreateRenderer(SDLw, index, flags);

    if (renderer == nullptr)
        throw SDLException();

    return renderer;
}

void unk::SDLWindow::setFullscreenMode() {
    int ret = SDL_SetWindowFullscreen(SDLw, SDL_WINDOW_FULLSCREEN);

    if (ret < 0)
        throw SDLException();
}

void unk::SDLWindow::setWindowedMode() {
    int ret = SDL_SetWindowFullscreen(SDLw, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (ret < 0)
        throw SDLException();
}

void unk::SDLWindow::minimize() {
    SDL_MinimizeWindow(SDLw);
}

void unk::SDLWindow::maximize() {
    SDL_MaximizeWindow(SDLw);
}

void unk::SDLWindow::restore() {
    SDL_RestoreWindow(SDLw);
}

void unk::SDLWindow::setTitle(std::string title) {
    SDL_SetWindowTitle(SDLw, title.c_str());
}

void unk::SDLWindow::setIcon(std::string iconName) {
    SDL_Surface *surface = IMG_Load(iconName.c_str());

    SDL_SetWindowIcon(SDLw, surface);
}

void unk::SDLWindow::setSize(uint32_t width, uint32_t height) {
    if (width <= 0 || height <= 0)
        throw SDLException();

    SDL_SetWindowSize(SDLw, width, height);
}

void unk::SDLWindow::setMaximumSize(uint32_t width, uint32_t height) {
    SDL_SetWindowMaximumSize(SDLw, width, height);
}

void unk::SDLWindow::setMinimumSize(uint32_t width, uint32_t height) {
    SDL_SetWindowMinimumSize(SDLw, width, height);
}

void unk::SDLWindow::setPosition(uint32_t x, uint32_t y) {
    SDL_SetWindowPosition(SDLw, x, y);
}

void unk::SDLWindow::setBrightness(double brightness) {
    int ret = SDL_SetWindowBrightness(SDLw, brightness);

    if (ret < 0)
        throw SDLException();
}

void unk::SDLWindow::drawBorder(bool on) {
    if (on)
        SDL_SetWindowBordered(SDLw, SDL_TRUE);
    else
        SDL_SetWindowBordered(SDLw, SDL_FALSE);
}

std::string unk::SDLWindow::getTitle() {
    std::string title(SDL_GetWindowTitle(SDLw));
    return title;
}

uint32_t unk::SDLWindow::getX() {
    int x;
    SDL_GetWindowPosition(SDLw, &x, NULL);
    return x;
}

uint32_t unk::SDLWindow::getY() {
    int y;
    SDL_GetWindowPosition(SDLw, NULL, &y);
    return y;
}

uint32_t unk::SDLWindow::getWidth() {
    int width;
    SDL_GetWindowPosition(SDLw, &width, NULL);
    return width;
}

uint32_t unk::SDLWindow::getHeight() {
    int height;
    SDL_GetWindowPosition(SDLw, NULL, &height);
    return height;
}

double unk::SDLWindow::getBrightness() {
    return SDL_GetWindowBrightness(SDLw);
}

bool unk::SDLWindow::isInstance(SDLWindow *base) {
    return Kind::SDL == base->getKind();
}