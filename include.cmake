macro(he_add_test SUITE_NAME RESOURCES_BOOL)
    file(GLOB ${SUITE_NAME}_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    )

    add_executable(${SUITE_NAME} ${${SUITE_NAME}_SOURCES})

    if(${RESOURCES_BOOL})
        file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/../bin/utests/)
    endif()

    target_link_libraries(${SUITE_NAME} PRIVATE UTest)
endmacro()