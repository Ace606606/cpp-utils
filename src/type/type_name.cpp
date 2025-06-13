// src/type/type_name.cpp

#include "cpp_utils/type/type_name.hpp"

// for GCC/Clang
#ifdef __GNUC__
#include <cxxabi.h>

#include <cstdlib>
#include <memory>

namespace cpp_utils {
namespace type {
namespace detail {

std::string demangle(const char* name) {
    int status = 0;
    std::unique_ptr<char, void (*)(void*)> res{
        abi::__cxa_demangle(name, nullptr, nullptr, &status), std::free};
    return (status == 0) ? res.get() : name;
}

}  // namespace detail
}  // namespace type
}  // namespace cpp_utils

#else
// for not GCC/Clang
namespace cpp_utils::type {
namespace type {
namespace detail {

std::string demangle(const char* name) { return name; }

}  // namespace detail
}  // namespace type
}  // namespace cpp_utils::type

#endif