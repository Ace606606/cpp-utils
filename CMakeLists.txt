#${CMAKE_SOURCE_DIR}
cmake_minimum_required(VERSION 3.10)
project(cpp_utils VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(type_utils_lib src/type_utils.cpp)
target_include_directories(type_utils_lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# option for tests
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()