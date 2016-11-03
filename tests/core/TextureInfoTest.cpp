#include "gtest/gtest.h"
#include "unk/core/TextureInfo.h"

TEST(CoreTest, BuildTextureInfo) {
    std::string filename = "mytexture.png";
    unk::TextureInfo info(filename);
    ASSERT_EQ(info.getFilename(), filename);
}

TEST(UtilsTest, LessTextureInfo) {
    std::string filenameLess = "thisComesBefore.png";
    std::string filenameGreater = "thisComes_After.png";

    unk::TextureInfo infoLess(filenameLess);
    unk::TextureInfo infoGreater(filenameGreater);

    bool isLess;
    std::less<unk::TextureInfo> lessTI;

    isLess = lessTI(infoLess, infoGreater);
    ASSERT_TRUE(isLess);

    isLess = lessTI(infoGreater, infoLess);
    ASSERT_FALSE(isLess);
}

TEST(UtilsTest, LessEqualTextureInfo) {
    std::string filename = "thisIsAImage.png";

    unk::TextureInfo infoOne(filename);
    unk::TextureInfo infoTwo(filename);

    bool isLess;
    std::less<unk::TextureInfo> lessTI;

    isLess = lessTI(infoOne, infoTwo);
    ASSERT_FALSE(isLess);

    isLess = lessTI(infoTwo, infoOne);
    ASSERT_FALSE(isLess);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
