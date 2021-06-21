cmake_minimum_required(VERSION 3.13)

project(Hoopoe VERSION 0.1 LANGUAGES CXX) # ${PROJECT_NAME}

set(BUILD_DIR "build") # default build directory

# Compile flags
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

# --------------------- Include paths --------------------- #

include_directories(${PROJECT_SOURCE_DIR}/Engine/vendor/spdlog/include)
include_directories(${PROJECT_SOURCE_DIR}/Engine)

# --------------------- Sub-projects ---------------------- #

add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/)
add_subdirectory(${PROJECT_SOURCE_DIR}/Sandbox/)

# ------------------------- UTest ------------------------- #

if(UTEST)
    # UTest main
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest)

    # Tests
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${BUILD_DIR}/utests)

    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest/test)
    
endif()