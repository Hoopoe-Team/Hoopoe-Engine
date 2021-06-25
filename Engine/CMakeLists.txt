cmake_minimum_required(VERSION 3.13)

set(ENGINE_PROJECT_NAME HEngine)
#set(BUILD_DIR "build") # default build directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

configure_file(Core/resources/hoopoe.cfg ${PROJECT_BINARY_DIR}/hoopoe.cfg COPYONLY)

# Create a Engine library
file(GLOB ENGINE_SOURCES
    "Core/src/*.cpp"
    "Renderer/src/*.cpp"
)

add_library(${ENGINE_PROJECT_NAME} SHARED ${ENGINE_SOURCES})

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC vendor/spdlog/include)