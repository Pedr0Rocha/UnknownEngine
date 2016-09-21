cmake_minimum_required (VERSION 2.8.8)

project (Unknown0.1)

set(CMAKE_CXX_FLAGS "-std=c++11 -O0 -g")

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_subdirectory (lib)

option (test "Compiles the tests" OFF)

if (test)
	enable_testing()
	add_subdirectory (tests)
endif ()
