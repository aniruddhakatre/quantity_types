/**
 * @file temperature_operators.hpp
 * @brief Operator overloads for temperature
 *
 */

#pragma once

#include "temperature_impl.hpp"
#include <numeric>

// user defined literals
qt::Temperature operator""_deg_c(long double t) { return qt::Temperature{Celsius{static_cast<double>(t)}}; }
qt::Temperature operator""_deg_f(long double t) { return qt::Temperature{Fahrenheit{static_cast<double>(t)}}; }
qt::Temperature operator""_kelvin(long double t) { return qt::Temperature{Kelvin{static_cast<double>(t)}}; }
qt::Temperature operator""_deg_c(unsigned long long int t) { return qt::Temperature{Celsius{static_cast<double>(t)}}; }
qt::Temperature operator""_deg_f(unsigned long long int t) { return qt::Temperature{Fahrenheit{static_cast<double>(t)}}; }
qt::Temperature operator""_kelvin(unsigned long long int t) { return qt::Temperature{Kelvin{static_cast<double>(t)}}; }

// comparison operators
inline bool operator<(const qt::Temperature &lhs, const qt::Temperature &rhs) { return lhs.celsius() < rhs.celsius(); }
inline bool operator>(const qt::Temperature &lhs, const qt::Temperature &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Temperature &lhs, const qt::Temperature &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Temperature &lhs, const qt::Temperature &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Temperature &lhs, const qt::Temperature &rhs) { return std::abs(lhs.celsius() - rhs.celsius()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Temperature &lhs, const qt::Temperature &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Temperature operator+(const qt::Temperature &lhs, const qt::Temperature &rhs)
{
  return qt::Temperature{Celsius{lhs.celsius() + rhs.celsius()}};
}

qt::Temperature operator-(const qt::Temperature &lhs, const qt::Temperature &rhs)
{
  return qt::Temperature{Celsius{lhs.celsius() - rhs.celsius()}};
}

qt::Temperature operator*(const qt::Temperature &lhs, double rhs)
{
  return qt::Temperature{Celsius{lhs.celsius() * rhs}};
}

qt::Temperature operator*(double lhs, const qt::Temperature &rhs)
{
  return qt::Temperature{Celsius{rhs.celsius() * lhs}};
}

qt::Temperature operator/(const qt::Temperature &lhs, double rhs)
{
  return qt::Temperature{Celsius{lhs.celsius() / rhs}};
}