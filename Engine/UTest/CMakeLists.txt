# Executable for run tests
file(GLOB UTEST_SOURCES
    "${PROJECT_BINARY_DIR}/../Engine/UTest/src/UTest.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin/)

add_executable(HUTest ${UTEST_SOURCES})

# UTest lib
if (UNIX AND NOT APPLE)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "${PROJECT_BINARY_DIR}/../Engine/Core/src/platform/linux/*.cpp"
        "${PROJECT_BINARY_DIR}/../Engine/Utils/src/platform/linux/*.cpp"
    )
elseif(WIN32)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "${PROJECT_BINARY_DIR}/../Engine/Core/src/platform/win/*.cpp"
        "${PROJECT_BINARY_DIR}/../Engine/Utils/src/platform/win/*.cpp"
    )
elseif(APPLE)
    file(GLOB UTEST_LIB_PLATFORM_SOURCES
        "${PROJECT_BINARY_DIR}/../Engine/Core/src/platform/mac/*.cpp"
        "${PROJECT_BINARY_DIR}/../Engine/Utils/src/platform/mac/*.cpp"
    )
endif()

file(GLOB UTEST_LIB_SOURCES
    "src/TestSuite.cpp"
    "src/TestReporter.cpp"

    "${PROJECT_BINARY_DIR}/../Engine/Core/src/*.cpp"
    "${PROJECT_BINARY_DIR}/../Engine/Utils/src/*.cpp"
)

add_library(UTest SHARED ${UTEST_LIB_SOURCES} ${UTEST_LIB_PLATFORM_SOURCES})