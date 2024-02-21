/**
 * @file mass_impl.hpp
 * @brief Implements the class for quantity Mass
 *
 */

#pragma once

#include "units.hpp"

namespace qt
{
  class Mass
  {
  public:
    /**
     * @brief Construct a new Mass object
     *
     */
    Mass() = default;

    /**
     * @brief Construct a new Mass object using a value in grams
     *
     */
    explicit constexpr Mass(Gram m) : value_{m.get() * GRAM_2_KG} {}

    /**
     * @brief Construct a new Mass object using a value in kilograms
     *
     */
    explicit constexpr Mass(Kilogram m) : value_{m.get()} {}

    /**
     * @brief Construct a new Mass object using a value in pounds
     *
     */
    explicit constexpr Mass(Pound m) : value_{m.get() * LB_2_KG} {}

    /**
     * @brief Get value in grams
     *
     * @return constexpr double
     */
    constexpr double gram() const noexcept { return value_ * KG_2_GRAM; }

    /**
     * @brief Get value in kilograms
     *
     * @return constexpr double
     */
    constexpr double kg() const noexcept { return value_; }

    /**
     * @brief Get value in pounds
     *
     * @return constexpr double
     */
    constexpr double lb() const noexcept { return value_ * KG_2_LB; }

    /**
     * @brief Set value in grams
     *
     * @return constexpr double
     */
    constexpr void gram(double m) noexcept { value_ = m * GRAM_2_KG; }

    /**
     * @brief Set value in kilograms
     *
     * @return constexpr double
     */
    constexpr void kg(double m) noexcept { value_ = m; }

    /**
     * @brief Set value in pounds
     *
     * @return constexpr double
     */
    constexpr void lb(double m) noexcept { value_ = m * LB_2_KG; }

    // Unary Operators
    Mass operator-()
    {
      return Mass{Kilogram{-value_}};
    }

    // Compound Assignment
    Mass &operator-=(const Mass &rhs)
    {
      this->value_ -= rhs.kg();
      return *this;
    }

    Mass &operator+=(const Mass &rhs)
    {
      this->value_ += rhs.kg();
      return *this;
    }

    Mass &operator*=(double rhs)
    {
      this->value_ *= rhs;
      return *this;
    }

    Mass &operator/=(double rhs)
    {
      this->value_ /= rhs;
      return *this;
    }

  private:
    double value_; // internal value stored in kg

    // Conversion between units of quantity Mass
    static constexpr double GRAM_2_KG{1000.};
    static constexpr double KG_2_GRAM{1. / GRAM_2_KG};
    static constexpr double KG_2_LB{2.204623};
    static constexpr double LB_2_KG{1. / KG_2_LB};
  };
}