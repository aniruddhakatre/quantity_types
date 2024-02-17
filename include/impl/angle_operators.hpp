/**
 * @file angle_operators.hpp
 * @brief Operator overloads for angle
 *
 */

#pragma once

#include "angle_impl.hpp"
#include <numeric>

// user defined literals
qt::Angle operator""_rad(long double a) { return qt::Angle{Radian{static_cast<double>(a)}}; }
qt::Angle operator""_deg(long double a) { return qt::Angle{Degree{static_cast<double>(a)}}; }
qt::Angle operator""_rad(unsigned long long int a) { return qt::Angle{Radian{static_cast<double>(a)}}; }
qt::Angle operator""_deg(unsigned long long int a) { return qt::Angle{Degree{static_cast<double>(a)}}; }

// comparison operators
inline bool operator<(const qt::Angle &lhs, const qt::Angle &rhs) { return lhs.rad() < rhs.rad(); }
inline bool operator>(const qt::Angle &lhs, const qt::Angle &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Angle &lhs, const qt::Angle &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Angle &lhs, const qt::Angle &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Angle &lhs, const qt::Angle &rhs) { return std::abs(lhs.rad() - rhs.rad()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Angle &lhs, const qt::Angle &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Angle operator+(const qt::Angle &lhs, const qt::Angle &rhs)
{
  return qt::Angle{Radian{lhs.rad() + rhs.rad()}};
}

qt::Angle operator-(const qt::Angle &lhs, const qt::Angle &rhs)
{
  return qt::Angle{Radian{lhs.rad() - rhs.rad()}};
}

qt::Angle operator*(const qt::Angle &lhs, double rhs)
{
  return qt::Angle{Radian{lhs.rad() * rhs}};
}

qt::Angle operator*(double lhs, const qt::Angle &rhs)
{
  return qt::Angle{Radian{rhs.rad() * lhs}};
}

qt::Angle operator/(const qt::Angle &lhs, double rhs)
{
  return qt::Angle{Radian{lhs.rad() / rhs}};
}