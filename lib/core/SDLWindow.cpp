/* Unknown Engine Project */

#include "unk/core/Window.h"
#include "unk/utils/SDLException.h"

#include <vector>

static unk::SDLFlagConverter<unk::SDLWindow::Flags> flagConverter = {
    { unk::SDLRenderer::Flags::SOFTWARE,     SDL_RENDERER_SOFTWARE       },
    { unk::SDLRenderer::Flags::ACCELERATED,  SDL_RENDERER_ACCELERATED    },
    { unk::SDLRenderer::Flags::VSYNC,        SDL_RENDERER_PRESENTVSYNC   },
    { unk::SDLRenderer::Flags::TEXTURE,      SDL_RENDERER_TARGETTEXTURE  }
};

unk::Window::Window(std::string title, int x, int y, int width, int height, 
    std::vector<Flags> flags) : Window(Window::Kind::SDL), Title(title), X(x), Y(y), Width(width), Height(height) {
    
    unk::Window::initWindow(title, x, y, width, height, flags);
}

unk::Window::Window(std::string title) : Window(Window::Kind::SDL), Title(title) {
    unk::Window::initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, {});
}

unk::Window::Window(std::string title, int width, int height) : Window(Window::Kind::SDL), Title(title), 
    Width(width), Height(height) {

    unk::Window::initWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, {});
}

unk::Window::~Window() {
    SDL_DestroyWindow(SDLWindow);
}

void unk::Window::initWindow(std::string title, int x, int y, int width, int height, 
    std::vector<Flags> flags) {
    
    SDL_Window *sdlWindow;

    uint32_t sdlFlags = unk::Window::toSDLFlags(flags);

    sdlWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, sdlFlags);

    if (sdlWindow == nullptr) 
        throw SDLException();

    SDLWindow = sdlWindow;
}

SDL_Renderer* unk::Window::createRenderer(int index, uint32_t flags) {
    SDL_Renderer *renderer = SDL_CreateRenderer(SDLWindow, index, flags);

    if (renderer == nullptr)
        throw SDLException();

    return renderer;
}

uint32_t unk::Window::toSDLFlag(Flags flag) {
    switch (flag) {
        case Flags::OPENGL:
            return SDL_WINDOW_OPENGL;
        case Flags::BORDERLESS:
            return SDL_WINDOW_BORDERLESS;
        case Flags::RESIZABLE:
            return SDL_WINDOW_RESIZABLE;
        default:
            throw SDLException("Invalid Window Flag.");
    }
}

uint32_t unk::Window::toSDLFlags(std::vector<Flags> flags) {
    uint32_t sdlFlags = 0;

    for (auto flag : flags) 
        sdlFlags |= toSDLFlag(flag);

    return sdlFlags;
}

void unk::Window::setFullscreenMode() {
    int ret = SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN);

    if (ret < 0)
        throw SDLException();
}

void unk::Window::setWindowedMode() {
    int ret = SDL_SetWindowFullscreen(SDLWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (ret < 0)
        throw SDLException();
}

void unk::Window::minimizeWindow() {
    SDL_MinimizeWindow(SDLWindow);
}

void unk::Window::maximizeWindow() {
    SDL_MaximizeWindow(SDLWindow);
}

void unk::Window::restoreWindow() {
    SDL_RestoreWindow(SDLWindow);
}

void unk::Window::setTitle(std::string title) {
    SDL_SetWindowTitle(SDLWindow, title.c_str());
}

void unk::Window::setIcon(std::string iconName) {
    /* SDL_SetWindowIcon needs a surface to change the icon */
}

void unk::Window::setSize(uint32_t width, uint32_t height) {
    if (width <= 0 || height <= 0)
        throw SDLException();

    SDL_SetWindowSize(SDLWindow, width, height);
}

void unk::Window::setMaximumSize(uint32_t width, uint32_t height) {
    SDL_SetWindowMaximumSize(SDLWindow, width, height);
}

void unk::Window::setMinimumSize(uint32_t width, uint32_t height) {
    SDL_SetWindowMinimumSize(SDLWindow, width, height);
}

void unk::Window::setPosition(uint32_t x, uint32_t y) {
    SDL_SetWindowPosition(SDLWindow, x, y);
}

void unk::Window::setOpacity(float opacity) {
    int ret = SDL_SetWindowOpacity(SDLWindow, opacity);

    if (ret < 0)
        throw SDLException();
}

void unk::Window::setBrightness(float brightness) {
    int ret = SDL_SetWindowBrightness(SDLWindow, brightness);

    if (ret < 0)
        throw SDLException();
}

void unk::Window::drawBorder(bool on) {
    if (on)
        SDL_SetWindowBordered(SDLWindow, SDL_TRUE);
    else
        SDL_SetWindowBordered(SDLWindow, SDL_FALSE);
}

std::string unk::Window::getTitle() {
    std::string title(SDL_GetWindowTitle(SDLWindow));
    return title;
}

uint32_t unk::Window::getX() {
    int *x = malloc(sizeof(int));
    SDL_GetWindowPosition(SDLWindow, x, NULL);
    return *x;
}

uint32_t unk::Window::getY() {
    int *y = malloc(sizeof(int));
    SDL_GetWindowPosition(SDLWindow, NULL, y);
    return *y;
}

uint32_t unk::Window::getWidth() {
    int *width = malloc(sizeof(int));
    SDL_GetWindowPosition(SDLWindow, width, NULL);
    return *width;
}

uint32_t unk::Window::getHeight() {
    int *height = malloc(sizeof(int));
    SDL_GetWindowPosition(SDLWindow, NULL, height);
    return *height;
}

float unk::Window::getOpacity() {
    float *opacity = malloc(sizeof(float));
    int ret = SDL_GetWindowOpacity(SDLWindow, opacity);

    if (ret < 0)
        throw SDLException();

    return *opacity;
}

float unk::Window::getBrightness() {
    return SDL_GetWindowBrightness(SDLWindow);
}
