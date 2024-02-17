/**
 * @file length_impl.hpp
 * @brief Implements the class for quantity length
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{

  class Length
  {
  public:
    /**
     * @brief Construct a new Length object
     *
     */
    Length() = default;

    /**
     * @brief Construct a new Length object from a Meter value
     *
     */
    explicit constexpr Length(Meter l) : value_{l.get()} {}

    /**
     * @brief Construct a new Length object from a Feet value
     *
     */
    explicit constexpr Length(Feet l) : value_{l.get() * FEET_2_METER} {}

    /**
     * @brief Construct a new Length object from a Kilometer value
     *
     */
    explicit constexpr Length(Kilometer l) : value_{l.get() * KILOMETER_2_METER} {}

    /**
     * @brief Construct a new Length object from a NauticalMile value
     *
     */
    explicit constexpr Length(NauticalMile l) : value_{l.get() * NAUTICAL_MILE_2_METER} {}

    /**
     * @brief Get value in meters
     *
     * @return constexpr double
     */
    constexpr double m() const noexcept { return value_; }

    /**
     * @brief Get value in feet
     *
     * @return constexpr double
     */
    constexpr double ft() const noexcept { return (value_ * METER_2_FEET); }

    /**
     * @brief Get value in kilometers
     *
     * @return constexpr double
     */
    constexpr double km() const noexcept { return (value_ * METER_2_KILOMETER); }

    /**
     * @brief Get value in nautical miles
     *
     * @return constexpr double
     */
    constexpr double nmi() const noexcept { return (value_ * METER_2_NAUTICAL_MILE); }

    /**
     * @brief Set value in meters
     *
     * @param l length in meters
     */
    constexpr void m(double l) noexcept { value_ = l; }

    /**
     * @brief Set value in feet
     *
     * @param l length in feet
     */
    constexpr void ft(double l) noexcept { value_ = l * FEET_2_METER; }

    /**
     * @brief Set value in kilometers
     *
     * @param l length in kilometers
     */
    constexpr void km(double l) noexcept { value_ = l * KILOMETER_2_METER; }

    /**
     * @brief Set value in nautical miles
     *
     * @param l length in nautical miles
     */
    constexpr void nmi(double l) noexcept { value_ = l * NAUTICAL_MILE_2_METER; }

    // Unary Operators
    Length operator-()
    {
      return Length{Meter{-value_}};
    }

    // Compound Assignment
    Length &operator-=(const Length &rhs)
    {
      this->value_ -= rhs.m();
      return *this;
    }

    Length &operator+=(const Length &rhs)
    {
      this->value_ += rhs.m();
      return *this;
    }

    Length &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Length &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value is stored as meters

    // Conversion between units of quantity Length
    static constexpr double KILOMETER_2_METER{1000.};
    static constexpr double METER_2_KILOMETER{1. / KILOMETER_2_METER};
    static constexpr double METER_2_FEET{3.28084};
    static constexpr double FEET_2_METER{1. / METER_2_FEET};
    static constexpr double NAUTICAL_MILE_2_METER{1852.};
    static constexpr double METER_2_NAUTICAL_MILE{1. / NAUTICAL_MILE_2_METER};
  };
}
