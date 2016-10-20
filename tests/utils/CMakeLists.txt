add_executable (RunRectTest
    RectTest.cpp)
add_executable (RunSDLExceptionTest
    SDLExceptionTest.cpp)

add_test (RectTest
    RunRectTest)
add_test (SDLExceptionTest
    RunSDLExceptionTest)

target_link_libraries (RunRectTest
    UNKUtils SDL2 gtest gtest_main pthread)
target_link_libraries (RunSDLExceptionTest
    UNKUtils SDL2_image SDL2 gtest gtest_main pthread)
