file(GLOB TEST_CORE_SOURCES
    "${PROJECT_BINARY_DIR}/../Engine/Core/test/src/*.cpp"
)

add_executable(TestCore ${TEST_CORE_SOURCES})

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/../bin/utests/)

target_link_libraries(TestCore PRIVATE UTest)