/**
 * @file temperature_tests.cpp
 * @brief Implement unit tests for temperature
 *
 */

#include <gtest/gtest.h>
#include "temperature.hpp"

TEST(TemperatureTests, ConstructorAndSettersGetters)
{
  qt::Temperature a1{Celsius{1.75}};
  EXPECT_DOUBLE_EQ(a1.celsius(), 1.75);
  a1.celsius(2.15);
  EXPECT_DOUBLE_EQ(a1.celsius(), 2.15);

  qt::Temperature a2{Fahrenheit{82.0}};
  EXPECT_DOUBLE_EQ(a2.fahrenheit(), 82.0);
  a2.fahrenheit(33.25);
  EXPECT_DOUBLE_EQ(a2.fahrenheit(), 33.25);

  qt::Temperature a3{Kelvin{2.0}};
  EXPECT_DOUBLE_EQ(a3.kelvin(), 2.0);
  a3.kelvin(4.0);
  EXPECT_DOUBLE_EQ(a3.kelvin(), 4.0);
}

TEST(TemperatureTests, UserDefinedLiterals)
{
  qt::Temperature a1 = 2_deg_c;
  qt::Temperature a2 = 2.0_deg_c;
  EXPECT_DOUBLE_EQ(a1.celsius(), a2.celsius());

  a1 = 180_deg_f;
  a2 = 180.0_deg_f;
  EXPECT_DOUBLE_EQ(a1.fahrenheit(), a2.fahrenheit());

  a1 = 2_kelvin;
  a2 = 2.0_kelvin;
  EXPECT_DOUBLE_EQ(a1.kelvin(), a2.kelvin());
}

TEST(TemperatureTests, ComparisonOperators)
{
  qt::Temperature a1{10_deg_c};
  qt::Temperature a2{20_deg_c};
  qt::Temperature a3{30_deg_c};
  qt::Temperature a4{30_deg_c};

  EXPECT_TRUE(a3 == a4);
  EXPECT_TRUE(a3 > a2);
  EXPECT_TRUE(a3 >= a2);
  EXPECT_TRUE(a3 >= a4);
  EXPECT_TRUE(a1 < a2);
  EXPECT_TRUE(a2 <= a3);
  EXPECT_TRUE(a3 <= a4);
  EXPECT_TRUE(a1 != a3);
}

TEST(TemperatureTests, ArithmeticOperatorOverloads)
{
  qt::Temperature l1{100_deg_c};
  qt::Temperature l2{200_deg_c};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.celsius(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.celsius(), 100);

  l3 -= 100_deg_c;
  l4 += 100_deg_c;
  EXPECT_DOUBLE_EQ(l3.celsius(), l4.celsius());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.celsius(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.celsius(), 100);

  EXPECT_DOUBLE_EQ((-l3).celsius(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.celsius(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.celsius(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.celsius(), 100);
}