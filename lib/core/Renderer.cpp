/* Unknown Engine Project */

#include "SDL2/SDL.h"

#include "unk/core/Renderer.h"
#include "unk/core/Resources.h"
#include "unk/utils/SDLException.h"

unk::Renderer::Renderer() {
    initRenderer({ Flags::ACCELERATED });
}

unk::Renderer::Renderer(std::vector<Flags> flags) {
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

void unk::Renderer::renderTexture(TextureInfo info, Point dest) {
    Rect srcR(0, 0, info.getWidth(), info.getHeight());
    Rect dstR(dest.X, dest.Y, info.getWidth(), info.getHeight());
    renderTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), { Flip::NONE });
}

void unk::Renderer::renderTexture(TextureInfo info, Point dest, double angle, Point ref) {
    Rect srcR(0, 0, info.getWidth(), info.getHeight());
    Rect dstR(dest.X, dest.Y, info.getWidth(), info.getHeight());
    renderTextureImpl(info, srcR, dstR, angle, ref, { Flip::NONE });
}

void unk::Renderer::renderTexture(TextureInfo info, Point dest, std::vector<Flip> flip) {
    Rect srcR(0, 0, info.getWidth(), info.getHeight());
    Rect dstR(dest.X, dest.Y, info.getWidth(), info.getHeight());
    renderTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), flip);
}

void unk::Renderer::renderTexture(TextureInfo info, Point dest, double angle, Point ref,
        std::vector<Flip> flip) {
    Rect srcR(0, 0, info.getWidth(), info.getHeight());
    Rect dstR(dest.X, dest.Y, info.getWidth(), info.getHeight());
    renderTextureImpl(info, srcR, dstR, angle, ref, flip);
}

void unk::Renderer::renderTexture(TextureInfo info, Rect srcR, Rect dstR) {
    renderTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), { Flip::NONE });
}

void unk::Renderer::renderTexture(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref) {
    renderTextureImpl(info, srcR, dstR, angle, ref, { Flip::NONE });
}

void unk::Renderer::renderTexture(TextureInfo info, Rect srcR, Rect dstR,
        std::vector<Flip> flip) {
    renderTextureImpl(info, srcR, dstR, 0.0, Point(0, 0), flip);
}

void unk::Renderer::renderTexture(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref, std::vector<Flip> flip) {
    renderTextureImpl(info, srcR, dstR, angle, ref, flip);
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

void unk::Renderer::renderTextureImpl(TextureInfo info, Rect srcR, Rect dstR,
        double angle, Point ref, std::vector<Flip> flip) {
    SDL_Texture *texture = nullptr;

    texture = Resources::getResources().getTexture(info);
    if (!texture)
        throw SDLException();

    SDL_Rect src = srcR.toSDLRect();
    SDL_Rect dest = dstR.toSDLRect();
    SDL_Point rotationRef = ref.toSDLPoint();
    SDL_RendererFlip flipOpt = static_cast<SDL_RendererFlip>(toSDLRendererFlip(flip));

    int ret = SDL_RenderCopyEx(SDLRenderer, texture, &src, &dest, angle, &rotationRef, flipOpt);

    if (ret < 0)
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
