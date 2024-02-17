/**
 * @file angle_impl.hpp
 * @brief Implements the class for quantity Angle
 *
 */

#pragma once

#include "units.hpp"
#include <cmath>

namespace qt
{
  class Angle
  {
  public:
    /**
     * @brief Construct a new Angle object
     *
     */
    Angle() = default;

    /**
     * @brief Construct a new Angle object from a Radian value
     *
     */
    explicit constexpr Angle(Radian a) : value_{a.get()} {}

    /**
     * @brief Construct a new Angle object from a Radian value
     *
     */
    explicit constexpr Angle(Degree a) : value_{a.get() * DEG_2_RAD} {}

    /**
     * @brief Get pi as an Angle object
     *
     * @return constexpr Angle
     */
    static constexpr Angle pi() noexcept { return Angle{Radian{M_PI}}; }

    /**
     * @brief Get 2*pi as an Angle object
     *
     * @return constexpr Angle
     */
    static constexpr Angle two_pi() noexcept { return Angle{Radian{2.0 * M_PI}}; }

    /**
     * @brief Get pi/2 as an Angle object
     *
     * @return constexpr Angle
     */
    static constexpr Angle half_pi() noexcept { return Angle{Radian{M_PI / 2.}}; }

    /**
     * @brief Get value in radians
     *
     * @return constexpr double
     */
    constexpr double rad() const noexcept { return value_; }

    /**
     * @brief Get value in degrees
     *
     * @return constexpr double
     */
    constexpr double deg() const noexcept { return value_ * RAD_2_DEG; }

    /**
     * @brief Set value in radians
     *
     * @param a angle in radians
     */
    constexpr void rad(double a) noexcept { value_ = a; }

    /**
     * @brief Set value in degrees
     *
     * @param a angle in degrees
     */
    constexpr void deg(double a) noexcept { value_ = a * DEG_2_RAD; }

    // Unary Operators
    Angle operator-()
    {
      return Angle{Radian{-value_}};
    }

    // Compound Assignment
    Angle &operator-=(const Angle &rhs)
    {
      this->value_ -= rhs.rad();
      return *this;
    }

    Angle &operator+=(const Angle &rhs)
    {
      this->value_ += rhs.rad();
      return *this;
    }

    Angle &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Angle &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value stored in radians

    // Conversion between units of quantity Angle
    static constexpr double DEG_2_RAD{M_PI / 180.};
    static constexpr double RAD_2_DEG{180.0 / M_PI};
  };
}