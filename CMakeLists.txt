cmake_minimum_required(VERSION 3.13)

project(Hoopoe VERSION 0.1 LANGUAGES CXX) # ${PROJECT_NAME}

# Compile flags
if(UNIX AND NOT APPLE)
    add_compile_options(
        #-Werror # unused variables 

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        #-Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
    )
endif()

# --------------------- Include paths --------------------- #

include_directories(${PROJECT_SOURCE_DIR}/Engine/vendor/spdlog/include)
include_directories(${PROJECT_SOURCE_DIR}/Engine/Core/include)
include_directories(${PROJECT_SOURCE_DIR}/Engine/Utils/include)
include_directories(${PROJECT_SOURCE_DIR}/Engine)

# --------------------- Sub-projects ---------------------- #

add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/)
add_subdirectory(${PROJECT_SOURCE_DIR}/Sandbox/)

# ------------------------- UTest ------------------------- #

if(UTEST)
    # UTest main
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest)

    # Tests
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/utests)

    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest/test)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/Core/test)
    
endif()