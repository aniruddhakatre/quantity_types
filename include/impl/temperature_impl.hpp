/**
 * @file temperature_impl.hpp
 * @brief Implements the class for quantity Temperature
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{
  class Temperature
  {
  public:
    /**
     * @brief Construct a new Temperature object
     *
     */
    Temperature() = default;

    /**
     * @brief Construct a new Temperature object from value in Celsius
     *
     */
    explicit constexpr Temperature(Celsius t) : value_{t.get()} {}

    /**
     * @brief Construct a new Temperature object from value in Kelvin
     *
     */
    explicit constexpr Temperature(Kelvin t) : value_{k2c(t.get())} {}

    /**
     * @brief Construct a new Temperature object from value in Fahrenheit
     *
     */
    explicit constexpr Temperature(Fahrenheit t) : value_{f2c(t.get())} {}

    /**
     * @brief Get value in celsius
     *
     * @return constexpr double
     */
    constexpr double celsius() const noexcept { return value_; }

    /**
     * @brief Get value in kelvin
     *
     * @return constexpr double
     */
    constexpr double kelvin() const noexcept { return c2k(value_); }

    /**
     * @brief Get value in fahrenheit
     *
     * @return constexpr double
     */
    constexpr double fahrenheit() const noexcept { return c2f(value_); }

    /**
     * @brief Set value in celsius
     *
     * @param c temperature in celsius
     */
    constexpr void celsius(double c) noexcept { value_ = c; }

    /**
     * @brief Set value in kelvin
     *
     * @param c temperature in kelvin
     */
    constexpr void kelvin(double k) noexcept { value_ = k2c(k); }

    /**
     * @brief Set value in fahrenheit
     *
     * @param c temperature in fahrenheit
     */
    constexpr void fahrenheit(double f) noexcept { value_ = f2c(f); }

    // Unary Operators
    Temperature operator-()
    {
      return Temperature{Celsius{-value_}};
    }

    // Compound Assignment
    Temperature &operator-=(const Temperature &rhs)
    {
      this->value_ -= rhs.celsius();
      return *this;
    }

    Temperature &operator+=(const Temperature &rhs)
    {
      this->value_ += rhs.celsius();
      return *this;
    }

    Temperature &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Temperature &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value stored in degrees celsius

    /**
     * @brief Convert celsius to fahrenheit
     *
     * @param c temperature in celsius
     * @return constexpr double
     */
    static constexpr double c2f(double c) noexcept { return (c * 9.0 / 5.0) + 32.0; }

    /**
     * @brief Convert fahrenheit to celsius
     *
     * @param c temperature in fahrenheit
     * @return constexpr double
     */
    static constexpr double f2c(double f) noexcept { return (f - 32.0) * (5.0 / 9.0); }

    /**
     * @brief Convert kelvin to celsius
     *
     * @param k temperature in kelvin
     * @return constexpr double
     */
    static constexpr double k2c(double k) noexcept { return (k - 273.15); }

    /**
     * @brief Convert celsius to kelvin
     *
     * @param c temperature in celsius
     * @return constexpr double
     */
    static constexpr double c2k(double c) noexcept { return (c + 273.15); }
  };
}