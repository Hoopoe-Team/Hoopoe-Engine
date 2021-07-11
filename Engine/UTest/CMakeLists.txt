# Executable for run tests
file(GLOB UTEST_SOURCES
    "${PROJECT_SOURCE_DIR}/Engine/UTest/src/UTest.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)

add_executable(HUTest ${UTEST_SOURCES})

# UTest lib
if (UNIX AND NOT APPLE)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "../Core/src/platform/linux/*.cpp"
        "../Utils/src/linux/*.cpp"
    )
elseif(WIN32)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "../Core/src/platform/win/*.cpp"
        "../Utils/src/platform/win/*.cpp"
    )
elseif(APPLE)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "../Core/src/platform/mac/*.cpp"
        "../Utils/src/platform/mac/*.cpp"
    )
endif()

file(GLOB UTEST_LIB_SOURCES
    "../Core/src/*.cpp"
    "../Utils/src/*.cpp"
    "src/TestSuite.cpp"
    "src/TestReporter.cpp"
)

add_library(UTest SHARED ${UTEST_LIB_SOURCES} ${UTEST_LIB_PLATFORM_SOURCES})