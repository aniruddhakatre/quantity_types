/**
 * @file duration_impl.hpp
 * @brief Implements the class for quantity elapsed time
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{
  class Duration
  {
  public:
    /**
     * @brief Construct a new Duration object
     *
     */
    Duration() = default;

    /**
     * @brief Construct a new Duration object from a Second value
     *
     */
    explicit constexpr Duration(Second d) : value_{d.get()} {}

    /**
     * @brief Construct a new Duration object from a Millisecond value
     *
     */
    explicit constexpr Duration(Millisecond d) : value_{d.get() * MILLISECOND_2_SECOND} {}

    /**
     * @brief Construct a new Duration object from a Microsecond value
     *
     */
    explicit constexpr Duration(Microsecond d) : value_{d.get() * MICROSECOND_2_SECOND} {}

    /**
     * @brief Construct a new Duration object from a Minute value
     *
     */
    explicit constexpr Duration(Minute d) : value_{d.get() * MINUTE_2_SECOND} {}

    /**
     * @brief Construct a new Duration object from a Hour value
     *
     */
    explicit constexpr Duration(Hour d) : value_{d.get() * HOUR_2_SECOND} {}

    /**
     * @brief Get value in seconds
     *
     * @return constexpr double
     */
    constexpr double sec() const noexcept { return value_; }

    /**
     * @brief Get value in milliseconds
     *
     * @return constexpr double
     */
    constexpr double msec() const noexcept { return value_ * SECOND_2_MILLISECOND; }

    /**
     * @brief Get value in microseconds
     *
     * @return constexpr double
     */
    constexpr double usec() const noexcept { return value_ * SECOND_2_MICROSECOND; }

    /**
     * @brief Get value in minutes
     *
     * @return constexpr double
     */
    constexpr double min() const noexcept { return value_ * SECOND_2_MINUTE; }

    /**
     * @brief Get value in hours
     *
     * @return constexpr double
     */
    constexpr double hr() const noexcept { return value_ * SECOND_2_HOUR; }

    /**
     * @brief Set value in seconds
     *
     * @param d duration in seconds
     */
    constexpr void sec(double d) noexcept { value_ = d; }

    /**
     * @brief Set value in milliseconds
     *
     * @param d duration in milliseconds
     */
    constexpr void msec(double d) noexcept { value_ = d * MILLISECOND_2_SECOND; }

    /**
     * @brief Set value in microseconds
     *
     * @param d duration in microseconds
     */
    constexpr void usec(double d) noexcept { value_ = d * MICROSECOND_2_SECOND; }

    /**
     * @brief Set value in minutes
     *
     * @param d duration in minutes
     */
    constexpr void min(double d) noexcept { value_ = d * MINUTE_2_SECOND; }

    /**
     * @brief Set value in hours
     *
     * @param d duration in hours
     */
    constexpr void hr(double d) noexcept { value_ = d * HOUR_2_SECOND; }

    // Unary Operators
    Duration operator-()
    {
      return Duration{Second{-value_}};
    }

    // Compound Assignment
    Duration &operator-=(const Duration &rhs)
    {
      this->value_ -= rhs.sec();
      return *this;
    }

    Duration &operator+=(const Duration &rhs)
    {
      this->value_ += rhs.sec();
      return *this;
    }

    Duration &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Duration &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value is stored in seconds

    // Conversion between units of quantity Duration
    static constexpr double SECOND_2_MILLISECOND{1'000.};
    static constexpr double MILLISECOND_2_SECOND{1. / SECOND_2_MILLISECOND};
    static constexpr double SECOND_2_MICROSECOND{1'000'000.0};
    static constexpr double MICROSECOND_2_SECOND{1. / SECOND_2_MICROSECOND};
    static constexpr double MINUTE_2_SECOND{60.};
    static constexpr double SECOND_2_MINUTE{1. / MINUTE_2_SECOND};
    static constexpr double HOUR_2_SECOND{3600.};
    static constexpr double SECOND_2_HOUR{1. / HOUR_2_SECOND};
  };
}