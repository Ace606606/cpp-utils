#${CMAKE_SOURCE_DIR}/test
add_executable(test_type_utils test_type_utils.cpp)
target_link_libraries(test_type_utils PRIVATE type_utils_lib)
add_test(NAME TypeUtilsTests COMMAND test_type_utils)