cmake_minimum_required(VERSION 3.13)

set(ENGINE_PROJECT_NAME HEngine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

configure_file(Core/resources/hoopoe.cfg ${PROJECT_SOURCE_DIR}/bin/hoopoe.cfg COPYONLY)

# Create a Engine library
if (UNIX AND NOT APPLE)
    file(GLOB ENGINE_PLATFORM_SOURCES
        "Core/src/platform/linux/*.cpp"
        "Utils/src/platform/linux/*.cpp"
    )
elseif(WIN32)
    file(GLOB ENGINE_PLATFORM_SOURCES
        "Core/src/platform/win/*.cpp"
        "Utils/src/platform/win/*.cpp"
    )
elseif(APPLE)
    file(GLOB ENGINE_PLATFORM_SOURCES
        "Core/src/platform/mac/*.cpp"
        "Utils/src/platform/mac/*.cpp"
    )
endif()

file(GLOB ENGINE_SOURCES
    "Core/src/*.cpp"
    "Utils/src/*.cpp"
)

add_library(${ENGINE_PROJECT_NAME} SHARED ${ENGINE_SOURCES} ${ENGINE_PLATFORM_SOURCES})

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC vendor/spdlog/include)

# ------------------------- UTest ------------------------- #

if(UTEST)
    # UTest main
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest)

    # Tests
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/utests)

    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest/test)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/Core/test)
    
endif()