file(GLOB TEST_CORE_SOURCES
    "${PROJECT_SOURCE_DIR}/Engine/Core/test/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Core/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Utils/src/*.cpp"
)

add_executable(TestCore ${TEST_CORE_SOURCES})

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/utests/)

target_link_libraries(TestCore PRIVATE UTest)