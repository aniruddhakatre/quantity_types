/**
 * @file length_operators.hpp
 * @brief Operator overloads for length
 *
 */

#pragma once

#include "length_impl.hpp"
#include <numeric>

// user defined literals
qt::Length operator""_m(long double l) { return qt::Length{Meter{static_cast<double>(l)}}; }
qt::Length operator""_ft(long double l) { return qt::Length{Feet{static_cast<double>(l)}}; }
qt::Length operator""_km(long double l) { return qt::Length{Kilometer{static_cast<double>(l)}}; }
qt::Length operator""_nmi(long double l) { return qt::Length{NauticalMile{static_cast<double>(l)}}; }
qt::Length operator""_m(unsigned long long int l) { return qt::Length{Meter{static_cast<double>(l)}}; }
qt::Length operator""_ft(unsigned long long int l) { return qt::Length{Feet{static_cast<double>(l)}}; }
qt::Length operator""_km(unsigned long long int l) { return qt::Length{Kilometer{static_cast<double>(l)}}; }
qt::Length operator""_nmi(unsigned long long int l) { return qt::Length{NauticalMile{static_cast<double>(l)}}; }

// comparison operators
inline bool operator<(const qt::Length &lhs, const qt::Length &rhs) { return lhs.m() < rhs.m(); }
inline bool operator>(const qt::Length &lhs, const qt::Length &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Length &lhs, const qt::Length &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Length &lhs, const qt::Length &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Length &lhs, const qt::Length &rhs) { return std::abs(lhs.m() - rhs.m()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Length &lhs, const qt::Length &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Length operator+(const qt::Length &lhs, const qt::Length &rhs)
{
  return qt::Length{Meter{lhs.m() + rhs.m()}};
}

qt::Length operator-(const qt::Length &lhs, const qt::Length &rhs)
{
  return qt::Length{Meter{lhs.m() - rhs.m()}};
}

qt::Length operator*(const qt::Length &lhs, double rhs)
{
  return qt::Length{Meter{lhs.m() * rhs}};
}

qt::Length operator*(double lhs, const qt::Length &rhs)
{
  return qt::Length{Meter{rhs.m() * lhs}};
}

qt::Length operator/(const qt::Length &lhs, double rhs)
{
  return qt::Length{Meter{lhs.m() / rhs}};
}
