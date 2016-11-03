/* Unknown Engine Project */

#include "unk/core/Window.h"

#include "unk/utils/UnkExceptions.h"

unk::Window::Window(Kind kind) : K(kind) {
}

unk::Window::~Window() {
}

void unk::Window::maximize() {
    throw FunctionNotImplementedException("maximize");
}

void unk::Window::minimize() {
    throw FunctionNotImplementedException("minimize");
}

void unk::Window::restore() {
    throw FunctionNotImplementedException("restore");
}

void unk::Window::setFullscreenMode() {
    throw FunctionNotImplementedException("setFullscreenMode");
}

void unk::Window::setWindowedMode() {
    throw FunctionNotImplementedException("setWindowedMode");
}

void unk::Window::setTitle(std::string title) {
    throw FunctionNotImplementedException("setTitle");
}

void unk::Window::setIcon(std::string iconName) {
    throw FunctionNotImplementedException("setIcon");
}

void unk::Window::setSize(uint32_t width, uint32_t height) {
    throw FunctionNotImplementedException("setSize");
}

void unk::Window::setMaximumSize(uint32_t width, uint32_t height) {
    throw FunctionNotImplementedException("setMaximumSize");
}

void unk::Window::setMinimumSize(uint32_t width, uint32_t height) {
    throw FunctionNotImplementedException("setMinimumSize");
}

void unk::Window::setPosition(uint32_t x, uint32_t y) {
    throw FunctionNotImplementedException("setPosition");
}

void unk::Window::setOpacity(float opacity) {
    throw FunctionNotImplementedException("setOpacity");
}

void unk::Window::setBrightness(float brightness) {
    throw FunctionNotImplementedException("setBrightness");
}

void unk::Window::drawBorder(bool on) {
    throw FunctionNotImplementedException("drawBorder");
}

std::string unk::Window::getTitle() {
    throw FunctionNotImplementedException("getTitle");
    return "";
}

uint32_t unk::Window::getX() {
    throw FunctionNotImplementedException("getX");
    return 0;
}

uint32_t unk::Window::getY() {
    throw FunctionNotImplementedException("getY");
    return 0;
}

uint32_t unk::Window::getWidth() {
    throw FunctionNotImplementedException("getWidth");
    return 0;
}

uint32_t unk::Window::getHeight() {
    throw FunctionNotImplementedException("getHeight");
    return 0;
}

float unk::Window::getOpacity() {
    throw FunctionNotImplementedException("getOpacity");
    return 0.0;
}

float unk::Window::getBrightness() {
    throw FunctionNotImplementedException("getBrightness");
    return 0.0;
}

unk::Window::Kind unk::Window::getKind() const {
    return K;
}
