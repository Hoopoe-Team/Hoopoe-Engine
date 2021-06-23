# Executable for run tests
file(GLOB UTEST_SOURCES
    "${PROJECT_SOURCE_DIR}/Engine/UTest/src/UTest.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_executable(HUTest ${UTEST_SOURCES})

# UTest lib
file(GLOB UTEST_LIB_SOURCES
    "../Core/src/LogManager.cpp"
    "src/TestSuite.cpp"
)

add_library(UTest SHARED ${UTEST_LIB_SOURCES})