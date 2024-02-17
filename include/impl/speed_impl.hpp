/**
 * @file speed_impl.hpp
 * @brief Implements the class for quantity Speed
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{
  class Speed
  {
  public:
    /**
     * @brief Construct a new Speed object
     *
     */
    Speed() = default;

    /**
     * @brief Construct a new Speed object from a m/s value
     *
     */
    explicit constexpr Speed(MeterPerSec s) : value_{s.get()} {}

    /**
     * @brief Construct a new Speed object from a ft/min value
     *
     */
    explicit constexpr Speed(FeetPerMin s) : value_{s.get() * FPM_2_MPS} {}

    /**
     * @brief Construct a new Speed object from a km/hr value
     *
     */
    explicit constexpr Speed(KilometerPerHour s) : value_{s.get() * KPH_2_MPS} {}

    /**
     * @brief Construct a new Speed object from a knots value
     *
     */
    explicit constexpr Speed(Knots s) : value_{s.get() * KTS_2_MPS} {}

    /**
     * @brief Get value in m/s
     *
     * @return constexpr double
     */
    constexpr double mps() const noexcept { return value_; }

    /**
     * @brief Get value in ft/min
     *
     * @return constexpr double
     */
    constexpr double fpm() const noexcept { return value_ * MPS_2_FPM; }

    /**
     * @brief Get value in km/hr
     *
     * @return constexpr double
     */
    constexpr double kph() const noexcept { return value_ * MPS_2_KPH; }

    /**
     * @brief Get value in knots
     *
     * @return constexpr double
     */
    constexpr double kts() const noexcept { return value_ * MPS_2_KTS; }

    /**
     * @brief Set value in m/s
     *
     * @param s speed in m/s
     */
    constexpr void mps(double s) noexcept { value_ = s; }

    /**
     * @brief Set value in ft/min
     *
     * @param s speed in ft/min
     */
    constexpr void fpm(double s) noexcept { value_ = s * FPM_2_MPS; }

    /**
     * @brief Set value in km/hr
     *
     * @param s speed in km/hr
     */
    constexpr void kph(double s) noexcept { value_ = s * KPH_2_MPS; }

    /**
     * @brief Set value in kts
     *
     * @param s speed in kts
     */
    constexpr void kts(double s) noexcept { value_ = s * KTS_2_MPS; }

    // Unary Operators
    Speed operator-()
    {
      return Speed{MeterPerSec{-value_}};
    }

    // Compound Assignment
    Speed &operator-=(const Speed &rhs)
    {
      this->value_ -= rhs.mps();
      return *this;
    }

    Speed &operator+=(const Speed &rhs)
    {
      this->value_ += rhs.mps();
      return *this;
    }

    Speed &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Speed &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value stored in m/s

    // Conversion between units of quantity Speed
    static constexpr double MPS_2_FPM{196.85039370078738};
    static constexpr double FPM_2_MPS{1. / MPS_2_FPM};
    static constexpr double MPS_2_KPH{3.6};
    static constexpr double KPH_2_MPS{1. / MPS_2_KPH};
    static constexpr double MPS_2_KTS{1.94384};
    static constexpr double KTS_2_MPS{1. / MPS_2_KTS};
  };
}