/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/core/SDLRenderer.h"
#include "unk/core/SDLResources.h"
#include "unk/core/SDLConverter.h"
#include "unk/utils/SDLException.h"

static unk::SDLFlagConverter<unk::SDLRenderer::Flags> flagConverter = {
    { unk::SDLRenderer::Flags::SOFTWARE,     SDL_RENDERER_SOFTWARE       },
    { unk::SDLRenderer::Flags::ACCELERATED,  SDL_RENDERER_ACCELERATED    },
    { unk::SDLRenderer::Flags::VSYNC,        SDL_RENDERER_PRESENTVSYNC   },
    { unk::SDLRenderer::Flags::TEXTURE,      SDL_RENDERER_TARGETTEXTURE  }
};

unk::SDLRenderer::SDLRenderer(std::shared_ptr<SDLResources> res) : Res(res), Renderer(Renderer::Kind::SDL) {
    initSDLRenderer({ Flags::ACCELERATED });
}

unk::SDLRenderer::SDLRenderer(std::shared_ptr<SDLResources> res, std::vector<Flags> flags) : 
    Res(res), Renderer(Renderer::Kind::SDL) {
    initSDLRenderer(flags);
}

unk::SDLRenderer::~SDLRenderer() {
    SDL_DestroyRenderer(SDLr);
}

uint32_t unk::SDLRenderer::getMaxTextureWidth() {
    return Info.max_texture_width;
}

uint32_t unk::SDLRenderer::getMaxTextureHeight() {
    return Info.max_texture_height;
} 

void unk::SDLRenderer::clear() {
    int ret = SDL_RenderClear(SDLr);

    if (ret)
        throw SDLException();
}

void unk::SDLRenderer::drawTexture(TextureInfo info, RenderOptions opt) {
}

void unk::SDLRenderer::setDrawColor(Color color) {
    DrawColor = color;
    setRenderDrawColor(DrawColor);
}

unk::Color unk::SDLRenderer::getDrawColor() {
    return DrawColor;
}

void unk::SDLRenderer::drawPoints(std::vector<Point> points) {
    if (points.empty())
        return;

    SDL_Point sdlPoints[points.size()];

    int idx = 0;
    for (auto point : points)
        sdlPoints[idx++] = toSDL(point);

    int ret = SDL_RenderDrawPoints(SDLr, sdlPoints, idx);

    if (ret)
        throw SDLException();
}

void unk::SDLRenderer::drawLines(std::vector<Point> points) {
    if (points.size() < 2)
        return;

    SDL_Point sdlPoints[points.size()];

    int idx = 0;
    for (auto point : points)
        sdlPoints[idx++] = toSDL(point);

    int ret = SDL_RenderDrawLines(SDLr, sdlPoints, idx);

    if (ret)
        throw SDLException();
}

void unk::SDLRenderer::drawRects(std::vector<Rect> rects, 
        bool fill, bool sameColor, Color color) {
    if (rects.empty())
        return;

    SDL_Rect sdlRects[rects.size()];

    int idx = 0;
    for (auto rect : rects)
        sdlRects[idx++] = toSDL(rect);

    int ret = SDL_RenderDrawRects(SDLr, sdlRects, idx);

    if (ret)
        throw SDLException();

    if (fill) {
        if (!sameColor)
            setRenderDrawColor(color);

        int ret = SDL_RenderFillRects(SDLr, sdlRects, idx);
        if (ret)
            throw SDLException();

        if (!sameColor)
            setRenderDrawColor(DrawColor);
    }
}

void unk::SDLRenderer::render() {
    SDL_RenderPresent(SDLr);
}

SDL_Texture *unk::SDLRenderer::createTextureFromSurface(SDL_Surface *surface) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(SDLr, surface);
    if (texture == nullptr)
        throw SDLException();

    return texture;
}

void unk::SDLRenderer::initSDLRenderer(std::vector<Flags> flags) {
    uint32_t sdlFlags = flagConverter.toSDLFlags(flags);
    // create renderer from window

    int ret = SDL_GetRendererInfo(SDLr, &Info);

    if (ret < 0)
        throw SDLException();
}

void unk::SDLRenderer::setRenderDrawColor(Color color) {
    int ret = SDL_SetRenderDrawColor(SDLr, color.R, color.G, color.B, color.A);

    if (ret)
        throw SDLException();
} 

bool unk::SDLRenderer::isInstance(const Renderer *base) {
    return Kind::SDL == base->getKind();
}

