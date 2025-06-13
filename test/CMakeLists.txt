#${CMAKE_SOURCE_DIR}/test/CMakeLists.txt

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(test_primes math/test_primes.cpp)

target_link_libraries(test_primes PRIVATE GTest::gtest_main type_utils_lib)

add_test(NAME test_primes COMMAND test_primes)