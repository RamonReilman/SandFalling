cmake_minimum_required(VERSION 3.1...3.30)

project(SandFall VERSION 0)

# Include directories
include_directories(include)

find_package(raylib REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)
