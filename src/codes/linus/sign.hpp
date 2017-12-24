#ifndef CODES_LINUS_SIGN_HPP
#define CODES_LINUS_SIGN_HPP

#include <cmath>
#include <type_traits>

namespace codes {
namespace linus {

/*!
 * Class to represent the sign (positive or negative) of a signed fundamental
 * type T. The values are limited to +1 or -1 of the underlying type T.
 *
 * Directly multiplying by the sign can avoid branching on the sign.
 *
 * It is designed to give compile time guarantees with zero runtime overhead,
 * when compared to using just T.
 */
template<typename T>
class Sign final
{
  static_assert(std::is_fundamental<T>::value,
                  "T must be a fundamental type.");
  static_assert(std::is_signed<T>::value,
                  "T must be a signed type.");

 public:
  constexpr explicit Sign(const T value) noexcept;

  template<typename U>
  constexpr explicit Sign(const Sign<U> sign) noexcept
    : value{static_cast<T>(sign.value)}
  {}

  bool constexpr operator==(const Sign<T> rhs) const noexcept
  { return this->value == rhs.value; }

  bool constexpr operator!=(const Sign<T> rhs) const noexcept
  { return this->value != rhs.value; }

  Sign<T> constexpr operator*(const Sign<T> rhs) const noexcept
  { return Sign<T>(this->value * rhs.value); }

  T constexpr operator*(const T rhs) const noexcept
  { return this->value * rhs; }

  Sign<T> constexpr& operator*=(const Sign<T> rhs) noexcept
  {
    this->value *= rhs.value;
    return *this;
  }

  static Sign<T> constexpr positive{static_cast<T>(+1.0)};
  static Sign<T> constexpr negative{static_cast<T>(-1.0)};

 private:
  T value;

  template <typename U>
  friend class Sign;
};

template <typename T>
constexpr Sign<T>::Sign(const T value) noexcept
  : value{std::copysign(static_cast<T>(1.0), value)}
{ }

template <>
inline constexpr Sign<int>::Sign(const int value) noexcept
  : value{value >= 0 ? +1 : -1}
{ }

template<typename T>
constexpr Sign<T> Sign<T>::positive;

template<typename T>
constexpr Sign<T> Sign<T>::negative;

} // namespace linus
} // namespace codes

#endif //CODES_LINUS_SIGN_HPP
