file(GLOB TEST_UTEST_SOURCES
    "${PROJECT_BINARY_DIR}/../Engine/UTest/test/src/*.cpp"
)

add_executable(TestUTest ${TEST_UTEST_SOURCES})

target_link_libraries(TestUTest PRIVATE UTest)