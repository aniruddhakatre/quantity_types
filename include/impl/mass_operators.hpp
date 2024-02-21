/**
 * @file mass_operators.hpp
 * @brief Operator overloads for mass
 *
 */

#pragma once

#include "mass_impl.hpp"
#include <numeric>

// user defined literals
qt::Mass operator""_gram(long double a) { return qt::Mass{Gram{static_cast<double>(a)}}; }
qt::Mass operator""_kg(long double a) { return qt::Mass{Kilogram{static_cast<double>(a)}}; }
qt::Mass operator""_lb(long double a) { return qt::Mass{Pound{static_cast<double>(a)}}; }
qt::Mass operator""_gram(unsigned long long int a) { return qt::Mass{Gram{static_cast<double>(a)}}; }
qt::Mass operator""_kg(unsigned long long int a) { return qt::Mass{Kilogram{static_cast<double>(a)}}; }
qt::Mass operator""_lb(unsigned long long int a) { return qt::Mass{Pound{static_cast<double>(a)}}; }

// comparison operators
inline bool operator<(const qt::Mass &lhs, const qt::Mass &rhs) { return lhs.kg() < rhs.kg(); }
inline bool operator>(const qt::Mass &lhs, const qt::Mass &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Mass &lhs, const qt::Mass &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Mass &lhs, const qt::Mass &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Mass &lhs, const qt::Mass &rhs) { return std::abs(lhs.kg() - rhs.kg()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Mass &lhs, const qt::Mass &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Mass operator+(const qt::Mass &lhs, const qt::Mass &rhs)
{
  return qt::Mass{Kilogram{lhs.kg() + rhs.kg()}};
}

qt::Mass operator-(const qt::Mass &lhs, const qt::Mass &rhs)
{
  return qt::Mass{Kilogram{lhs.kg() - rhs.kg()}};
}

qt::Mass operator*(const qt::Mass &lhs, double rhs)
{
  return qt::Mass{Kilogram{lhs.kg() * rhs}};
}

qt::Mass operator*(double lhs, const qt::Mass &rhs)
{
  return qt::Mass{Kilogram{rhs.kg() * lhs}};
}

qt::Mass operator/(const qt::Mass &lhs, double rhs)
{
  return qt::Mass{Kilogram{lhs.kg() / rhs}};
}