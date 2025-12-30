cmake_minimum_required(VERSION 3.22)

project(raynuk)

include(FetchContent)

FetchContent_Declare(raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)
message(STATUS "Fetching raylib...")
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.hpp")
file(GLOB_RECURSE LIB_SOURCES "lib/*.c" "lib/*.cpp")

add_library(${PROJECT_NAME} ${SOURCES} ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "inc" "lib")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)