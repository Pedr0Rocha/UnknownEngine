/* Unknown Engine Project */

#include "unk/core/Renderer.h"
#include "unk/utils/UnkExceptions.h"

unk::Renderer::Renderer(Kind kind) : K(kind) {
}

unk::Renderer::~Renderer() {
}

uint32_t unk::Renderer::getMaxTextureWidth() {
    throw FunctionNotImplementedException("getMaxTextureWidth");
    return 0;
}

uint32_t unk::Renderer::getMaxTextureHeight() {
    throw FunctionNotImplementedException("getMaxTextureHeight");
    return 0;
}

void unk::Renderer::clear() {
    throw FunctionNotImplementedException("clear");
}

void unk::Renderer::drawTexture(TextureInfo info, RenderOptions opt) {
    throw FunctionNotImplementedException("drawTexture");
}

void unk::Renderer::setDrawColor(Color color) {
    throw FunctionNotImplementedException("setDrawColor");
}

unk::Color unk::Renderer::getDrawColor() {
    throw FunctionNotImplementedException("getDrawColor");
    return Color();
}

void unk::Renderer::drawPoints(std::vector<Point> points) {
    throw FunctionNotImplementedException("drawPoints");
}

void unk::Renderer::drawLines(std::vector<Point> points) {
    throw FunctionNotImplementedException("drawLines");
}

void unk::Renderer::drawRects(std::vector<Rect> rects, bool fill, bool sameColor, Color color) {
    throw FunctionNotImplementedException("drawRects");
}

void unk::Renderer::render() {
    throw FunctionNotImplementedException("render");
}

unk::Renderer::Kind unk::Renderer::getKind() const {
    return K;
}
