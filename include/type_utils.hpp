#ifndef TYPE_UTILS_HPP
#define TYPE_UTILS_HPP

#include <string>
#include <typeinfo>

namespace type_utils {
namespace detail {
std::string demangle(const char* name);
}  // namespace detail

template <typename T>
std::string type_name() {
    return detail::demangle(typeid(T).name());
}

}  // namespace type_utils

#endif  // TYPE_UTILS_HPP