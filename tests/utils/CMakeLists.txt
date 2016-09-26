add_executable (RunRectTest
	RectTest.cpp)
add_executable (RunPointTest
	PointTest.cpp)
add_executable (RunColorTest
    ColorTest.cpp)
add_executable (RunSDLExceptionTest
  SDLExceptionTest.cpp)

add_test (RectTest 
	RunRectTest)
add_test (PointTest 
	RunPointTest)
add_test (ColorTest 
    RunColorTest)
add_test (SDLExceptionTest 
  RunSDLExceptionTest)

target_link_libraries (RunRectTest
	UNKUtils SDL2 gtest gtest_main pthread)
target_link_libraries (RunPointTest
	UNKUtils SDL2 gtest gtest_main pthread)
target_link_libraries (RunColorTest
	UNKUtils SDL2 gtest gtest_main pthread)
target_link_libraries (RunSDLExceptionTest
	UNKUtils SDL2 gtest gtest_main pthread)
