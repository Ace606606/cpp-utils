#include <cstdlib>
#include <iostream>
#include <string>
#include <type_traits>

#include "type_utils.hpp"

int tests_failed = 0;

template <typename T>
void expect_type_name(const std::string& expected_substr) {
    std::string actual = type_utils::type_name<T>();
    std::cout << "Testing type: " << actual << std::endl;

    if (actual.find(expected_substr) == std::string::npos) {
        std::cerr << "[FAIL] Expected substring \"" << expected_substr
                  << "\" in \"" << actual << "\"" << std::endl;
        ++tests_failed;
    } else {
        std::cout << "[OK]" << std::endl;
    }
}

void test_basic_types() {
    std::cout << "\n=== Testing basic types ===" << std::endl;
    expect_type_name<int>("int");
    expect_type_name<double>("double");
    expect_type_name<char>("char");
    expect_type_name<bool>("bool");
    expect_type_name<void>("void");
}

int main() {
    std::cout << "Starting tests for type_utils...\n";

    test_basic_types();
    // test_custom_types();
    // test_template_types();

    if (tests_failed > 0) {
        std::cerr << tests_failed << " test(s) failed!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "All tests passed.\n";
    return EXIT_SUCCESS;
}