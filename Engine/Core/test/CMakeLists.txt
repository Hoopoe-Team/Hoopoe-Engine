file(GLOB TEST_CORE_SOURCES
    "${PROJECT_SOURCE_DIR}/Engine/Core/test/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Core/src/Exception.cpp"
)

add_executable(TestCore ${TEST_CORE_SOURCES})

configure_file(resources/TestResourceManager.txt ${PROJECT_BINARY_DIR}/utests/resources/TestResourceManager.txt COPYONLY)

target_link_libraries(TestCore PRIVATE UTest)