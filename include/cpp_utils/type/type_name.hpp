// include/type/type_utils.hpp

#ifndef TYPE_NAME_HPP
#define TYPE_NAME_HPP
#include <string>
#include <typeinfo>

#include "cpp_utils/config.hpp"

namespace cpp_utils {
namespace type {
namespace detail {

std::string demangle(const char* name);

}  // namespace detail

template <typename T>
std::string type_name() {
    return detail::demangle(typeid(T).name());
}

}  // namespace type
}  // namespace cpp_utils

#endif  // TYPE_UTILS_HPP