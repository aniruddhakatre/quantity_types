/**
 * @file duration_operators.hpp
 * @brief Operator overloads for duration
 *
 */

#pragma once

#include "duration_impl.hpp"
#include <numeric>

// user defined literals
qt::Duration operator""_sec(long double d) { return qt::Duration{Second{static_cast<double>(d)}}; }
qt::Duration operator""_msec(long double d) { return qt::Duration{Millisecond{static_cast<double>(d)}}; }
qt::Duration operator""_usec(long double d) { return qt::Duration{Microsecond{static_cast<double>(d)}}; }
qt::Duration operator""_min(long double d) { return qt::Duration{Minute{static_cast<double>(d)}}; }
qt::Duration operator""_hr(long double d) { return qt::Duration{Hour{static_cast<double>(d)}}; }
qt::Duration operator""_sec(unsigned long long int d) { return qt::Duration{Second{static_cast<double>(d)}}; }
qt::Duration operator""_msec(unsigned long long int d) { return qt::Duration{Millisecond{static_cast<double>(d)}}; }
qt::Duration operator""_usec(unsigned long long int d) { return qt::Duration{Microsecond{static_cast<double>(d)}}; }
qt::Duration operator""_min(unsigned long long int d) { return qt::Duration{Minute{static_cast<double>(d)}}; }
qt::Duration operator""_hr(unsigned long long int d) { return qt::Duration{Hour{static_cast<double>(d)}}; }

// comparison operators
inline bool operator<(const qt::Duration &lhs, const qt::Duration &rhs) { return lhs.sec() < rhs.sec(); }
inline bool operator>(const qt::Duration &lhs, const qt::Duration &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Duration &lhs, const qt::Duration &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Duration &lhs, const qt::Duration &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Duration &lhs, const qt::Duration &rhs) { return std::abs(lhs.sec() - rhs.sec()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Duration &lhs, const qt::Duration &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Duration operator+(const qt::Duration &lhs, const qt::Duration &rhs)
{
  return qt::Duration{Second{lhs.sec() + rhs.sec()}};
}

qt::Duration operator-(const qt::Duration &lhs, const qt::Duration &rhs)
{
  return qt::Duration{Second{lhs.sec() - rhs.sec()}};
}

qt::Duration operator*(const qt::Duration &lhs, double rhs)
{
  return qt::Duration{Second{lhs.sec() * rhs}};
}

qt::Duration operator*(double lhs, const qt::Duration &rhs)
{
  return qt::Duration{Second{rhs.sec() * lhs}};
}

qt::Duration operator/(const qt::Duration &lhs, double rhs)
{
  return qt::Duration{Second{lhs.sec() / rhs}};
}