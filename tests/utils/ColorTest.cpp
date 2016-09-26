#include "gtest/gtest.h"
#include "unk/utils/Color.h"

TEST(UtilsTest, BuildColor) {
	unk::Color color;
	ASSERT_EQ(color.R, 0);
	ASSERT_EQ(color.G, 0);
	ASSERT_EQ(color.B, 0);
	ASSERT_EQ(color.A, 0);
}

TEST(UtilsTest, BuildColorParams) {
	unk::Color color(10, 15, 20, 30);
	ASSERT_EQ(color.R, 10);
	ASSERT_EQ(color.G, 15);
	ASSERT_EQ(color.B, 20);
	ASSERT_EQ(color.A, 30);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
