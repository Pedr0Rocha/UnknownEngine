/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/core/Renderer.h"
#include "unk/utils/SDLException.h"

unk::Renderer::Renderer(std::shared_ptr<Resources> res) : Res(res) {
    initRenderer({ Flags::ACCELERATED });
}

unk::Renderer::Renderer(std::shared_ptr<Resources> res, std::vector<Flags> flags) : Res(res) {
    initRenderer(flags);
}

unk::Renderer::~Renderer() {
    SDL_DestroyRenderer(SDLRenderer);
}

int unk::Renderer::getMaxTextureWidth() {
    return Info.max_texture_width;
}

int unk::Renderer::getMaxTextureHeight() {
    return Info.max_texture_height;
} 

void unk::Renderer::drawTexture(TextureInfo info, Point dest) {
    Rect srcR(0, 0, info.Width, info.Height);
    Rect dstR(dest.X, dest.Y, info.Width, info.Height);
    drawTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), { Flip::NONE });
}

void unk::Renderer::drawTexture(TextureInfo info, Point dest, double angle, Point ref) {
    Rect srcR(0, 0, info.Width, info.Height);
    Rect dstR(dest.X, dest.Y, info.Width, info.Height);
    drawTextureImpl(info, srcR, dstR, angle, ref, { Flip::NONE });
}

void unk::Renderer::drawTexture(TextureInfo info, Point dest, std::vector<Flip> flip) {
    Rect srcR(0, 0, info.Width, info.Height);
    Rect dstR(dest.X, dest.Y, info.Width, info.Height);
    drawTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), flip);
}

void unk::Renderer::drawTexture(TextureInfo info, Point dest, double angle, Point ref,
        std::vector<Flip> flip) {
    Rect srcR(0, 0, info.Width, info.Height);
    Rect dstR(dest.X, dest.Y, info.Width, info.Height);
    drawTextureImpl(info, srcR, dstR, angle, ref, flip);
}

void unk::Renderer::drawTexture(TextureInfo info, Rect srcR, Rect dstR) {
    drawTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), { Flip::NONE });
}

void unk::Renderer::drawTexture(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref) {
    drawTextureImpl(info, srcR, dstR, angle, ref, { Flip::NONE });
}

void unk::Renderer::drawTexture(TextureInfo info, Rect srcR, Rect dstR,
        std::vector<Flip> flip) {
    drawTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), flip);
}

void unk::Renderer::drawTexture(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref, std::vector<Flip> flip) {
    drawTextureImpl(info, srcR, dstR, angle, ref, flip);
}

void unk::Renderer::setDrawColor(Color color) {
    DrawColor = color;
    setRenderDrawColor();
}

unk::Color unk::Renderer::getDrawColor() {
    return DrawColor;
}

void unk::Renderer::drawPoints(std::vector<Point> points) {
    if (points.empty())
        return;

    SDL_Point sdlPoints[points.size()];

    int idx = 0;
    for (auto point : points)
        sdlPoints[idx++] = point.toSDLPoint();

    int ret = SDL_RenderDrawPoints(SDLRenderer, sdlPoints, idx);

    if (ret)
        throw SDLException();
}

void unk::Renderer::drawLines(std::vector<Point> points) {
    if (points.size() < 2)
        return;

    SDL_Point sdlPoints[points.size()];

    int idx = 0;
    for (auto point : points)
        sdlPoints[idx++] = point.toSDLPoint();

    int ret = SDL_RenderDrawLines(SDLRenderer, sdlPoints, idx);

    if (ret)
        throw SDLException();
}

void unk::Renderer::drawRects(std::vector<Rect> rects, 
        bool fill, bool sameColor, Color color) {
    if (rects.empty())
        return;

    SDL_Rect sdlRects[rects.size()];

    int idx = 0;
    for (auto rect : rects)
        sdlRects[idx++] = rect.toSDLRect();

    int ret = SDL_RenderDrawRects(SDLRenderer, sdlRects, idx);

    if (ret)
        throw SDLException();

    if (fill) {
        Color oldColor;
        if (!sameColor) {
            oldColor = DrawColor;
            DrawColor = color;
            setRenderDrawColor();
        }

        int ret = SDL_RenderFillRects(SDLRenderer, sdlRects, idx);

        if (ret)
            throw SDLException();

        if (!sameColor) {
            DrawColor = oldColor;
            setRenderDrawColor();
        }
    }
}

void unk::Renderer::render() {
    SDL_RenderPresent(SDLRenderer);
}

SDL_Texture *unk::Renderer::createTextureFromSurface(SDL_Surface *surface) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
    if (texture == nullptr)
        throw SDLException();

    return texture;
}

void unk::Renderer::initRenderer(std::vector<Flags> flags) {
    uint32_t sdlFlags = toSDLFlags(flags);
    // create renderer from window

    int ret = SDL_GetRendererInfo(SDLRenderer, &Info);

    if (ret < 0)
        throw SDLException();
}

void unk::Renderer::setRenderDrawColor() {
    int ret = SDL_SetRenderDrawColor(SDLRenderer, DrawColor.R, DrawColor.G,
            DrawColor.B, DrawColor.A);

    if (ret)
        throw SDLException();
} 

void unk::Renderer::drawTextureImpl(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref, std::vector<Flip> flip) {
    SDL_Texture *texture = nullptr;

    // Assert that the texture is loaded.
    texture = Res->getTexture(info);

    SDL_Rect src = srcR.toSDLRect();
    SDL_Rect dest = dstR.toSDLRect();
    SDL_Point rotationRef = ref.toSDLPoint();
    SDL_RendererFlip flipOpt = static_cast<SDL_RendererFlip>(toSDLRendererFlip(flip));

    int ret = SDL_RenderCopyEx(SDLRenderer, texture, &src, &dest, angle, &rotationRef, flipOpt);

    if (ret)
        throw SDLException();
}

uint32_t unk::Renderer::toSDLFlag(Flags flag) {
    switch (flag) {
        case Flags::SOFTWARE:
            return SDL_RENDERER_SOFTWARE;
        case Flags::ACCELERATED:
            return SDL_RENDERER_ACCELERATED;
        case Flags::VSYNC:
            return SDL_RENDERER_PRESENTVSYNC;
        case Flags::TEXTURE:
            return SDL_RENDERER_TARGETTEXTURE;
        default:
            throw SDLException("Invalid Renderer flag.");
    }
}

uint32_t unk::Renderer::toSDLFlags(std::vector<Flags> flags) {
    uint32_t sdlFlags = 0;

    for (auto f : flags)
        sdlFlags |= toSDLFlag(f);

    return sdlFlags;
}

uint32_t unk::Renderer::toSDLRendererFlip(std::vector<Flip> flip) {
    uint32_t sdlFlip = SDL_FLIP_NONE;

    for (auto f : flip) {
        switch (f) {
            case Flip::HORIZONTAL:
                sdlFlip |= SDL_FLIP_HORIZONTAL;
                break;

            case Flip::VERTICAL:
                sdlFlip |= SDL_FLIP_VERTICAL;
                break;

            default:
                break;
        }
    }

    return sdlFlip;
}
