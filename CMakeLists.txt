cmake_minimum_required(VERSION 3.16)
project(Test_Demo LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL ${CMAKE_BINARY_DIR}/SDL_build)
# 添加 include 目录（这样 #include "Map.hpp" 就能找到）
include_directories(${CMAKE_SOURCE_DIR}/include)

# 找到所有源文件
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 链接 SDL3

target_link_libraries(Test_Demo PRIVATE SDL3::SDL3)