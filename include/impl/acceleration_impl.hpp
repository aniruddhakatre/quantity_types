/**
 * @file acceleration_impl.hpp
 * @brief Implements the class for quantity Acceleration
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{
  class Acceleration
  {
  public:
    /**
     * @brief Construct a new Acceleration object
     *
     */
    Acceleration() = default;

    /**
     * @brief Construct a new Acceleration object from m/s^2 value
     *
     */
    explicit constexpr Acceleration(MeterPerSecSq a) : value_{a.get()} {}

    /**
     * @brief Construct a new Acceleration object from ft/s^2 value
     *
     */
    explicit constexpr Acceleration(FeetPerSecSq a) : value_{a.get() * FPS2_2_MPS2} {}

    /**
     * @brief Construct a new Acceleration object from acceleration due to gravity value
     *
     */
    explicit constexpr Acceleration(AccelG a) : value_{a.get() * G_2_MPS2} {}

    /**
     * @brief Get value in m/s^2
     *
     * @return constexpr double
     */
    constexpr double mps2() const noexcept { return value_; }

    /**
     * @brief Get value in m/s^2
     *
     * @return constexpr double
     */
    constexpr double fps2() const noexcept { return value_ * MPS2_2_FPS2; }

    /**
     * @brief Get value in acceleration due to gravity
     *
     * @return constexpr double
     */
    constexpr double g() const noexcept { return value_ * MPS2_2_G; }

    /**
     * @brief Set value in m/s^2
     *
     * @param a value to set
     */
    constexpr void mps2(double a) noexcept { value_ = a; }

    /**
     * @brief Set value in ft/s^2
     *
     * @param a value to set
     */
    constexpr void fps2(double a) noexcept { value_ = a * FPS2_2_MPS2; }

    /**
     * @brief Set value in acceleration due to gravity
     *
     * @param a value to set
     */
    constexpr void g(double a) noexcept { value_ = a * G_2_MPS2; }

    // Unary Operators
    Acceleration operator-()
    {
      return Acceleration{MeterPerSecSq{-value_}};
    }

    // Compound Assignment
    Acceleration &operator-=(const Acceleration &rhs)
    {
      this->value_ -= rhs.mps2();
      return *this;
    }

    Acceleration &operator+=(const Acceleration &rhs)
    {
      this->value_ += rhs.mps2();
      return *this;
    }

    Acceleration &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Acceleration &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value stored in m/s^2

    // Conversion between units of quantity Acceleration
    static constexpr double MPS2_2_FPS2{3.28084};
    static constexpr double FPS2_2_MPS2{1. / MPS2_2_FPS2};
    static constexpr double G_2_MPS2{9.80665};
    static constexpr double MPS2_2_G{1. / G_2_MPS2};
  };
}