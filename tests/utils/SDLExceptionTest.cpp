#include "gtest/gtest.h"

#include "SDL2/SDL_image.h"

#include "unk/utils/SDLException.h"

#include <iostream>

TEST(UtilsTest, WindowError) {
    bool throughCatch = false;
    SDL_Window *window = nullptr;

    try {
        if (window == nullptr)
            throw unk::SDLException("Window creation problem.");
    } catch (unk::SDLException &e) {
        std::cerr << e.what() << std::endl;
        throughCatch = true;
    }

    ASSERT_TRUE(throughCatch);
}

TEST(UtilsTest, RendererError) {
    bool throughCatch = false;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    try {
        renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
            throw unk::SDLException();
    } catch (unk::SDLException &e) {
        std::cerr << e.what() << std::endl;
        throughCatch = true;
    }

    ASSERT_TRUE(throughCatch);
}

TEST(UtilsTest, ImageError) {
    bool throughCatch = false;
    SDL_Surface *surface = nullptr;

    try {
        surface = IMG_Load("SomeNonExistingImage.png");
        if (!surface)
            throw unk::SDLException();
    } catch (unk::SDLException &e) {
        std::cerr << e.what() << std::endl;
        throughCatch = true;
    }

    ASSERT_TRUE(throughCatch);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
