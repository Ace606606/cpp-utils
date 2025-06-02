#include "type_utils.hpp"

#ifdef __GNUC__
#include <cxxabi.h>

#include <cstdlib>
#include <memory>

namespace type_utils {
namespace detail {

std::string demangle(const char* name) {
    int status = 0;
    std::unique_ptr<char, void (*)(void*)> res{
        abi::__cxa_demangle(name, nullptr, nullptr, &status), std::free};
    return (status == 0) ? res.get() : name;
}

}  // namespace detail
}  // namespace type_utils

#else

namespace type_utils {
namespace detail {

std::string demangle(const char* name) { return name; }

}  // namespace detail
}  // namespace type_utils

#endif