#include "gtest/gtest.h"
#include "unk/utils/Rect.h"

TEST(UtilsTest, BuildRect) {
	unk::Rect rect;
	ASSERT_EQ(rect.X, 0);
	ASSERT_EQ(rect.Y, 0);
	ASSERT_EQ(rect.Width, 0);
	ASSERT_EQ(rect.Height, 0);
}

TEST(UtilsTest, BuildRectParams) {
	unk::Rect rect(10, 10, 10, 15);
	ASSERT_EQ(rect.X, 10);
	ASSERT_EQ(rect.Y, 10);
	ASSERT_EQ(rect.Width, 10);
	ASSERT_EQ(rect.Height, 15);
}

TEST(UtilsTest, SDLRect) {
	unk::Rect rect(10, 10, 10, 15);
	SDL_Rect sdlRect = rect.toSDLRect();

	ASSERT_EQ(sdlRect.x, 10);
	ASSERT_EQ(sdlRect.y, 10);
	ASSERT_EQ(sdlRect.w, 10);
	ASSERT_EQ(sdlRect.h, 15);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}