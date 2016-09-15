add_executable (RunRectTest
	RectTest.cpp)

add_test (RectTest 
	RunRectTest)

target_link_libraries (RunRectTest
	UNKUtils SDL2 gtest gtest_main pthread)