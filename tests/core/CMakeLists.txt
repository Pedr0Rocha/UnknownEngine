add_executable (RunTextureInfoTest
    TextureInfoTest.cpp)

add_test (TextureInfoTest 
    RunTextureInfoTest)

target_link_libraries (RunTextureInfoTest
    UNKCore SDL2 gtest gtest_main pthread)
