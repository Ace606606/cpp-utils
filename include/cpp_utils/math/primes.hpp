// innclude/cpp_utils/math/primes.hpp
#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <type_traits>

#include "cpp_utils/config.hpp"

namespace cpp_utils {
namespace math {
namespace detail {

template <typename T>
constexpr bool is_prime_impl(T value) {
    if (value <= 1) return false;
    for (uint64_t i = 2; i <= value / i; ++i) {
        if (!(value % i)) return false;
    }
    return true;
}

}  // namespace detail

#if __cplusplus >= CPP20_STANDARD
#include <concepts>

template <typename T>
    requires std::integral<T>
constexpr bool is_prime(T value) {
    return detail::is_prime_impl(value);
}

template <typename T>
    requires(!std::integral<T>)
constexpr bool is_prime(T) {
    return false;
}

#elif __cplusplus >= CPP17_STANDARD

template <typename T>
constexpr bool is_prime(T value) {
    if constexpr (!std::is_integral_v<T>) {
        return false;
    } else {
        return detail::is_prime_impl(value);
    }
}

#elif __cplusplus >= CPP14_STANDARD

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, bool>::type
is_prime(T value) {
    return detail::is_prime_impl(value);
}

template <typename T>
constexpr typename std::enable_if<!std::is_integral<T>::value, bool>::type
is_prime(T) {
    return false;
}

#else

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_prime(
    T value) {
    return detail::is_prime_impl(value);
}

template <typename T>
typename std::enable_if<!std::is_integral<T>::value, bool>::type is_prime(T) {
    return false;
}

#endif

}  // namespace math
}  // namespace cpp_utils

#endif