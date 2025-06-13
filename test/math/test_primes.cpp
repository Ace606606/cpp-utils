// test/math/test.primes.cpp

#include <gtest/gtest.h>

#include "cpp_utils/math/primes.hpp"

using namespace cpp_utils::math;

// prime numbers test
TEST(IsPrimeTest, PositivePrimes) {
    EXPECT_TRUE(is_prime(2));
    EXPECT_TRUE(is_prime(3));
    EXPECT_TRUE(is_prime(17));
    EXPECT_TRUE(is_prime(997));
}

// composite numbers test
TEST(IsPrimeTest, CompositePrimes) {
    EXPECT_FALSE(is_prime(0));
    EXPECT_FALSE(is_prime(1));
    EXPECT_FALSE(is_prime(4));
    EXPECT_FALSE(is_prime(100));
}

// negative numbers test
TEST(IsPrimeTest, NegativePrimes) {
    EXPECT_FALSE(is_prime(-1));
    EXPECT_FALSE(is_prime(-3));
    EXPECT_FALSE(is_prime(-17));
    EXPECT_FALSE(is_prime(-997));
}

// large prime numbers test
TEST(IsPrimeTest, LargePrime) { EXPECT_TRUE(is_prime(9223372036854775783)); }

// test for non-integer types
TEST(IsPrimeTest, NonIntegralTypes) {
    EXPECT_FALSE(is_prime(3.14));
    EXPECT_FALSE(is_prime(2.0f));
    EXPECT_FALSE(is_prime("string"));
}
