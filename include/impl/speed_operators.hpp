/**
 * @file speed_operators.hpp
 * @brief Operator overloads for speed
 *
 */

#pragma once

#include "speed_impl.hpp"
#include <numeric>
#include "length_impl.hpp"
#include "duration_impl.hpp"

// user defined literals
qt::Speed operator""_mps(long double s) { return qt::Speed{MeterPerSec{static_cast<double>(s)}}; }
qt::Speed operator""_fpm(long double s) { return qt::Speed{FeetPerMin{static_cast<double>(s)}}; }
qt::Speed operator""_kph(long double s) { return qt::Speed{KilometerPerHour{static_cast<double>(s)}}; }
qt::Speed operator""_kts(long double s) { return qt::Speed{Knots{static_cast<double>(s)}}; }
qt::Speed operator""_mps(unsigned long long int s) { return qt::Speed{MeterPerSec{static_cast<double>(s)}}; }
qt::Speed operator""_fpm(unsigned long long int s) { return qt::Speed{FeetPerMin{static_cast<double>(s)}}; }
qt::Speed operator""_kph(unsigned long long int s) { return qt::Speed{KilometerPerHour{static_cast<double>(s)}}; }
qt::Speed operator""_kts(unsigned long long int s) { return qt::Speed{Knots{static_cast<double>(s)}}; }

// comparison operators
inline bool operator<(const qt::Speed &lhs, const qt::Speed &rhs) { return lhs.mps() < rhs.mps(); }
inline bool operator>(const qt::Speed &lhs, const qt::Speed &rhs) { return rhs < lhs; }
inline bool operator<=(const qt::Speed &lhs, const qt::Speed &rhs) { return !(lhs > rhs); }
inline bool operator>=(const qt::Speed &lhs, const qt::Speed &rhs) { return !(lhs < rhs); }
inline bool operator==(const qt::Speed &lhs, const qt::Speed &rhs) { return std::abs(lhs.mps() - rhs.mps()) < std::numeric_limits<double>::epsilon(); }
inline bool operator!=(const qt::Speed &lhs, const qt::Speed &rhs) { return !(lhs == rhs); }

// arithmetic operators
qt::Speed operator+(const qt::Speed &lhs, const qt::Speed &rhs)
{
  return qt::Speed{MeterPerSec{lhs.mps() + rhs.mps()}};
}

qt::Speed operator-(const qt::Speed &lhs, const qt::Speed &rhs)
{
  return qt::Speed{MeterPerSec{lhs.mps() - rhs.mps()}};
}

qt::Speed operator*(const qt::Speed &lhs, double rhs)
{
  return qt::Speed{MeterPerSec{lhs.mps() * rhs}};
}

qt::Speed operator*(double lhs, const qt::Speed &rhs)
{
  return qt::Speed{MeterPerSec{rhs.mps() * lhs}};
}

qt::Speed operator/(const qt::Speed &lhs, double rhs)
{
  return qt::Speed{MeterPerSec{lhs.mps() / rhs}};
}

qt::Speed operator/(const qt::Length &lhs, const qt::Duration &rhs)
{
  return qt::Speed{MeterPerSec{lhs.m() / rhs.sec()}};
}