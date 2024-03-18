cmake_minimum_required(VERSION 3.11)
project(pong)

# Dependencies

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_found) # If raylib was not found, fetch and build it
	include(FetchContent)
	FetchContent_Declare(
		raylib
		Download_Extract_Timestamp OFF
		URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED) # If raylib has not been download yet
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib)
		set(BULD_EXAMPLES OFF CACHE BOOL "" FORCE) # Do not build examples
		add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
	endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
