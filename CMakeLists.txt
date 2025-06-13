#${CMAKE_SOURCE_DIR}/CMakeLists.txt

cmake_minimum_required(VERSION 3.14)
project(cpp_utils VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(type_utils_lib include/cpp_utils/config.hpp 
    include/cpp_utils/math/primes.hpp
    include/cpp_utils/type/type_name.hpp
    src/type/type_name.cpp
)

target_include_directories(type_utils_lib PUBLIC include)

# option for tests
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()