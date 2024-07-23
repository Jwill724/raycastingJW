cmake_minimum_required(VERSION 3.10)
project(DoomEngineJW)

# Define the C standard
set(CMAKE_C_STANDARD 99)

# Define the source files
set(SOURCES
    src/main.c
    src/raycaster.c
    src/map.c
)

# Include directories
include_directories(src/include)

# Set SDL2 paths manually
set(SDL2_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src/lib/cmake/SDL2")
set(SDL2_LIBRARY_DIRS "${CMAKE_SOURCE_DIR}/src/lib")
set(SDL2_LIBRARIES "${SDL2_LIBRARY_DIRS}/libSDL2.dll.a;${SDL2_LIBRARY_DIRS}/libSDL2main.a")

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the SDL2 library
target_link_libraries(${PROJECT_NAME} "${SDL2_LIBRARY_DIRS}/libSDL2.dll.a" "${SDL2_LIBRARY_DIRS}/libSDL2main.a")