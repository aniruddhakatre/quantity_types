/**
 * @file acceleration_operators.hpp
 * @brief Operator overloads for acceleration
 *
 */

#pragma once

#include "acceleration_impl.hpp"
#include "speed_impl.hpp"
#include "duration_impl.hpp"
#include <numeric>

// user defined literals
constexpr qt::Acceleration operator""_mps2(long double a) { return qt::Acceleration{MeterPerSecSq{static_cast<double>(a)}}; }
constexpr qt::Acceleration operator""_fps2(long double a) { return qt::Acceleration{FeetPerSecSq{static_cast<double>(a)}}; }
constexpr qt::Acceleration operator""_g(long double a) { return qt::Acceleration{AccelG{static_cast<double>(a)}}; }
constexpr qt::Acceleration operator""_mps2(unsigned long long int a) { return qt::Acceleration{MeterPerSecSq{static_cast<double>(a)}}; }
constexpr qt::Acceleration operator""_fps2(unsigned long long int a) { return qt::Acceleration{FeetPerSecSq{static_cast<double>(a)}}; }
constexpr qt::Acceleration operator""_g(unsigned long long int a) { return qt::Acceleration{AccelG{static_cast<double>(a)}}; }

// comparison operators
constexpr bool operator<(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return lhs.mps2() < rhs.mps2(); }
constexpr bool operator>(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return rhs < lhs; }
constexpr bool operator<=(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return !(lhs > rhs); }
constexpr bool operator>=(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return !(lhs < rhs); }
constexpr bool operator==(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return std::abs(lhs.mps2() - rhs.mps2()) < std::numeric_limits<double>::epsilon(); }
constexpr bool operator!=(const qt::Acceleration &lhs, const qt::Acceleration &rhs) { return !(lhs == rhs); }

// arithmetic operators
constexpr qt::Acceleration operator+(const qt::Acceleration &lhs, const qt::Acceleration &rhs)
{
  return qt::Acceleration{MeterPerSecSq{lhs.mps2() + rhs.mps2()}};
}

constexpr qt::Acceleration operator-(const qt::Acceleration &lhs, const qt::Acceleration &rhs)
{
  return qt::Acceleration{MeterPerSecSq{lhs.mps2() - rhs.mps2()}};
}

constexpr qt::Acceleration operator*(const qt::Acceleration &lhs, double rhs)
{
  return qt::Acceleration{MeterPerSecSq{lhs.mps2() * rhs}};
}

constexpr qt::Acceleration operator*(double lhs, const qt::Acceleration &rhs)
{
  return qt::Acceleration{MeterPerSecSq{rhs.mps2() * lhs}};
}

constexpr qt::Acceleration operator/(const qt::Acceleration &lhs, double rhs)
{
  return qt::Acceleration{MeterPerSecSq{lhs.mps2() / rhs}};
}

constexpr qt::Acceleration operator/(const qt::Speed &lhs, const qt::Duration &rhs)
{
  return qt::Acceleration{MeterPerSecSq{lhs.mps() / rhs.sec()}};
}