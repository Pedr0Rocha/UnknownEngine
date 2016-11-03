#include "gtest/gtest.h"
#include "unk/utils/Point.h"

TEST(UtilsTest, BuildPoint) {
	unk::Point point;
	ASSERT_EQ(point.X, 0);
	ASSERT_EQ(point.Y, 0);
}

TEST(UtilsTest, BuildPointParams) {
	unk::Point point(10, 15);
	ASSERT_EQ(point.X, 10);
	ASSERT_EQ(point.Y, 15);
}

TEST(UtilsTest, SDLPoint) {
	unk::Point point(10, 15);
    SDL_Point sdlPoint = point.toSDLPoint();

	ASSERT_EQ(sdlPoint.x, 10);
	ASSERT_EQ(sdlPoint.y, 15);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
