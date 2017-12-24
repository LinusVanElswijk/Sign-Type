#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <codes/linus/sign.hpp>

namespace codes {
namespace linus {

// Equality ===================================================================

TEST_CASE(
    "For any T x and T y, x and y test equal if and only if: "
    "x and y are both positive OR "
    "x and y are both negative")
{
  REQUIRE(Sign<int>::positive == Sign<int>::positive);
  REQUIRE(Sign<int>::negative == Sign<int>::negative);
  REQUIRE_FALSE(Sign<int>::positive == Sign<int>::negative);
  REQUIRE_FALSE(Sign<int>::negative == Sign<int>::positive);

  REQUIRE(Sign<float>::positive == Sign<float>::positive);
  REQUIRE(Sign<float>::negative == Sign<float>::negative);
  REQUIRE_FALSE(Sign<float>::positive == Sign<float>::negative);
  REQUIRE_FALSE(Sign<float>::negative == Sign<float>::positive);

  REQUIRE(Sign<double>::positive == Sign<double>::positive);
  REQUIRE(Sign<double>::negative == Sign<double>::negative);
  REQUIRE_FALSE(Sign<double>::positive == Sign<double>::negative);
  REQUIRE_FALSE(Sign<double>::negative == Sign<double>::positive);

  REQUIRE(Sign<long double>::positive == Sign<long double>::positive);
  REQUIRE(Sign<long double>::negative == Sign<long double>::negative);
  REQUIRE_FALSE(Sign<long double>::positive == Sign<long double>::negative);
  REQUIRE_FALSE(Sign<long double>::negative == Sign<long double>::positive);
}

TEST_CASE(
    "For any T x and T y, x and y test unequal if and only if: "
    "x is positive and y is negative OR "
    "x is negative and y is positive")
{
  REQUIRE_FALSE(Sign<int>::positive != Sign<int>::positive);
  REQUIRE_FALSE(Sign<int>::negative != Sign<int>::negative);
  REQUIRE(Sign<int>::positive != Sign<int>::negative);
  REQUIRE(Sign<int>::negative != Sign<int>::positive);

  REQUIRE_FALSE(Sign<float>::positive != Sign<float>::positive);
  REQUIRE_FALSE(Sign<float>::negative != Sign<float>::negative);
  REQUIRE(Sign<float>::positive != Sign<float>::negative);
  REQUIRE(Sign<float>::negative != Sign<float>::positive);

  REQUIRE_FALSE(Sign<double>::positive != Sign<double>::positive);
  REQUIRE_FALSE(Sign<double>::negative != Sign<double>::negative);
  REQUIRE(Sign<double>::positive != Sign<double>::negative);
  REQUIRE(Sign<double>::negative != Sign<double>::positive);

  REQUIRE_FALSE(Sign<long double>::positive != Sign<long double>::positive);
  REQUIRE_FALSE(Sign<long double>::negative != Sign<long double>::negative);
  REQUIRE(Sign<long double>::positive != Sign<long double>::negative);
  REQUIRE(Sign<long double>::negative != Sign<long double>::positive);
}

// Multiplication =============================================================

TEST_CASE("For any T x, Sign<T>::positive * x == x.")
{
  SECTION("Case: T is int")
  {
    constexpr std::array<int, 5> test_values{
        0, 1,-1,
        std::numeric_limits<int>::max(),
        std::numeric_limits<int>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<int>::positive * value == value ); }
  }

  SECTION("Case: T is float")
  {
     constexpr std::array<float, 7> test_values{
        0.0f, 1.0f,-1.0f,
        std::numeric_limits<float>::epsilon(),
        std::numeric_limits<float>::infinity(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<float>::positive * value == value ); }
  }

  SECTION("Case: T is double")
  {
    constexpr std::array<double, 7> test_values{
        0.0, 1.0,-1.0,
        std::numeric_limits<double>::epsilon(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::max(),
        std::numeric_limits<double>::min()};

    for (auto value : test_values)
    { REQUIRE(Sign<double>::positive * value == value ); }
  }

  SECTION("Case: T is long double")
  {
     constexpr std::array<long double, 7> test_values{
        0.0L, 1.0L,-1.0L,
        std::numeric_limits<long double>::epsilon(),
        std::numeric_limits<long double>::infinity(),
        std::numeric_limits<long double>::max(),
        std::numeric_limits<long double>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<long double>::positive * value == value ); }
  }
}

TEST_CASE("For any T x, Sign<T>::negative * x == -x.")
{
  SECTION("Case: T is int")
  {
    constexpr std::array<int, 5> test_values{
        0, 1,-1,
        std::numeric_limits<int>::max(),
        std::numeric_limits<int>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<int>::negative * value == -value ); }
  }

  SECTION("Case: T is float")
  {
    constexpr std::array<float, 7> test_values{
        0.0f, 1.0f,-1.0f,
        std::numeric_limits<float>::epsilon(),
        std::numeric_limits<float>::infinity(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<float>::negative * value == -value ); }
  }

  SECTION("Case: T is double")
  {
    constexpr std::array<double, 7> test_values{
       0.0, 1.0,-1.0,
       std::numeric_limits<double>::epsilon(),
       std::numeric_limits<double>::infinity(),
       std::numeric_limits<double>::max(),
       std::numeric_limits<double>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<double>::negative * value == -value ); }
  }

  SECTION("Case: T is long double")
  {
    constexpr std::array<long double, 7> test_values{
        0.0L, 1.0L,-1.0L,
        std::numeric_limits<long double>::epsilon(),
        std::numeric_limits<long double>::infinity(),
        std::numeric_limits<long double>::max(),
        std::numeric_limits<long double>::min()};
    for (auto value : test_values)
    { REQUIRE(Sign<long double>::negative * value == -value ); }
  }
}

TEST_CASE(
    "For any T, "
    "Sign<T>::positive * Sign<T>::positive == Sign<T>::positive")
{
  REQUIRE(
      Sign<int>::positive * Sign<int>::positive
      == Sign<int>::positive);
  REQUIRE(
      Sign<float>::positive * Sign<float>::positive
      == Sign<float>::positive);
  REQUIRE(
      Sign<double>::positive * Sign<double>::positive
      == Sign<double>::positive);
  REQUIRE(
      Sign<long double>::positive * Sign<long double>::positive
      == Sign<long double>::positive);
}

TEST_CASE(
    "For any T, "
    "Sign<T>::positive * Sign<T>::negative == Sign<T>::negative")
{
  REQUIRE(
      Sign<int>::positive * Sign<int>::negative
      == Sign<int>::negative);
  REQUIRE(
      Sign<float>::positive * Sign<float>::negative
      == Sign<float>::negative);
  REQUIRE(
      Sign<double>::positive * Sign<double>::negative
      == Sign<double>::negative);
  REQUIRE(
      Sign<long double>::positive * Sign<long double>::negative
      == Sign<long double>::negative);
}

TEST_CASE(
    "For any T, "
    "Sign<T>::negative * Sign<T>::positive == Sign<T>::negative")
{
  REQUIRE(
      Sign<int>::negative * Sign<int>::positive
      == Sign<int>::negative);
  REQUIRE(
      Sign<float>::negative * Sign<float>::positive
      == Sign<float>::negative);
  REQUIRE(
      Sign<double>::negative * Sign<double>::positive
      == Sign<double>::negative);
  REQUIRE(
      Sign<long double>::negative * Sign<long double>::positive
      == Sign<long double>::negative);
}

TEST_CASE(
    "For any T, "
    "Sign<T>::negative * Sign<T>::negative == Sign<T>::positive")
{
  REQUIRE(
      Sign<int>::negative * Sign<int>::negative
      == Sign<int>::positive);
  REQUIRE(
      Sign<float>::negative * Sign<float>::negative
      == Sign<float>::positive);
  REQUIRE(
      Sign<double>::negative * Sign<double>::negative
      == Sign<double>::positive);
  REQUIRE(
      Sign<long double>::negative * Sign<long double>::negative
      == Sign<long double>::positive);
}

// Construction ===============================================================

TEST_CASE("For any T x, where x is positive, Sign<T>(x) == Sign<T>::positive")
{
  REQUIRE(Sign<int>(100) == Sign<int>::positive);
  REQUIRE(Sign<float>(+0.0) == Sign<float>::positive);
  REQUIRE(
      Sign<double>(std::numeric_limits<double>::infinity())
      == Sign<double>::positive);
  REQUIRE(
      Sign<long double>(std::numeric_limits<long double>::epsilon())
      == Sign<long double>::positive);
}

TEST_CASE("For any T x, where x is negative, Sign<T>(x) == Sign<T>::negative")
{
  REQUIRE(Sign<int>(-100) == Sign<int>::negative);
  REQUIRE(Sign<float>(-0.0f) == Sign<float>::negative);
  REQUIRE(
      Sign<double>(-std::numeric_limits<double>::infinity())
      == Sign<double>::negative);
  REQUIRE(
      Sign<long double>(-std::numeric_limits<long double>::epsilon())
      == Sign<long double>::negative);
}

TEST_CASE("For any T and U, Sign<U>{Sign<T>::positive} == Sign<U>::positive")
{
  REQUIRE(Sign<int>{Sign<int>::positive} == Sign<int>::positive);
  REQUIRE(Sign<int>{Sign<float>::positive} == Sign<int>::positive);
  REQUIRE(Sign<int>{Sign<double>::positive} == Sign<int>::positive);
  REQUIRE(Sign<int>{Sign<long double>::positive} == Sign<int>::positive);

  REQUIRE(Sign<float>{Sign<int>::positive} == Sign<float>::positive);
  REQUIRE(Sign<float>{Sign<float>::positive} == Sign<float>::positive);
  REQUIRE(Sign<float>{Sign<double>::positive} == Sign<float>::positive);
  REQUIRE(Sign<float>{Sign<long double>::positive} == Sign<float>::positive);

  REQUIRE(Sign<double>{Sign<int>::positive} == Sign<double>::positive);
  REQUIRE(Sign<double>{Sign<float>::positive} == Sign<double>::positive);
  REQUIRE(Sign<double>{Sign<double>::positive} == Sign<double>::positive);
  REQUIRE(Sign<double>{Sign<long double>::positive} == Sign<double>::positive);

  REQUIRE(
      Sign<long double>{Sign<int>::positive}
      == Sign<long double>::positive);
  REQUIRE(
      Sign<long double>{Sign<float>::positive}
      == Sign<long double>::positive);
  REQUIRE(
      Sign<long double>{Sign<double>::positive}
      == Sign<long double>::positive);
  REQUIRE(
      Sign<long double>{Sign<long double>::positive}
      == Sign<long double>::positive);
}

TEST_CASE("For any T and U, Sign<U>{Sign<T>::negative} == Sign<U>::negative")
{
  REQUIRE(Sign<int>{Sign<int>::negative} == Sign<int>::negative);
  REQUIRE(Sign<int>{Sign<float>::negative} == Sign<int>::negative);
  REQUIRE(Sign<int>{Sign<double>::negative} == Sign<int>::negative);
  REQUIRE(Sign<int>{Sign<long double>::negative} == Sign<int>::negative);

  REQUIRE(Sign<float>{Sign<int>::negative} == Sign<float>::negative);
  REQUIRE(Sign<float>{Sign<float>::negative} == Sign<float>::negative);
  REQUIRE(Sign<float>{Sign<double>::negative} == Sign<float>::negative);
  REQUIRE(Sign<float>{Sign<long double>::negative} == Sign<float>::negative);

  REQUIRE(Sign<double>{Sign<int>::negative} == Sign<double>::negative);
  REQUIRE(Sign<double>{Sign<float>::negative} == Sign<double>::negative);
  REQUIRE(Sign<double>{Sign<double>::negative} == Sign<double>::negative);
  REQUIRE(Sign<double>{Sign<long double>::negative} == Sign<double>::negative);

  REQUIRE(
      Sign<long double>{Sign<int>::negative}
      == Sign<long double>::negative);
  REQUIRE(
      Sign<long double>{Sign<float>::negative}
      == Sign<long double>::negative);
  REQUIRE(
      Sign<long double>{Sign<double>::negative}
      == Sign<long double>::negative);
  REQUIRE(
      Sign<long double>{Sign<long double>::negative}
      == Sign<long double>::negative);
}

} // namespace linus
} // namespace codes