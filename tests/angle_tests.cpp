/**
 * @file angle_tests.cpp
 * @brief Implement unit tests for angle
 *
 */

#include <gtest/gtest.h>
#include "angle.hpp"

TEST(AngleTests, ConstructorAndSettersGetters)
{
  qt::Angle a1{Radian{1.75}};
  EXPECT_DOUBLE_EQ(a1.rad(), 1.75);
  a1.rad(2.15);
  EXPECT_DOUBLE_EQ(a1.rad(), 2.15);

  qt::Angle a2{Degree{175.0}};
  EXPECT_DOUBLE_EQ(a2.deg(), 175.0);
  a2.deg(215.0);
  EXPECT_DOUBLE_EQ(a2.deg(), 215.0);

  constexpr auto pi = qt::Angle::pi();
  EXPECT_DOUBLE_EQ(pi.rad(), M_PI);

  constexpr auto half_pi = qt::Angle::half_pi();
  EXPECT_DOUBLE_EQ(half_pi.rad(), M_PI_2);

  constexpr auto two_pi = qt::Angle::two_pi();
  EXPECT_DOUBLE_EQ(two_pi.rad(), 2. * M_PI);
}

TEST(AngleTests, UserDefinedLiterals)
{
  qt::Angle a1 = 2_rad;
  qt::Angle a2 = 2.0_rad;
  EXPECT_DOUBLE_EQ(a1.rad(), a2.rad());

  a1 = 180_deg;
  a2 = 180.0_deg;
  EXPECT_DOUBLE_EQ(a1.deg(), a2.deg());
}

TEST(AngleTests, ComparisonOperators)
{
  qt::Angle a1{10_deg};
  qt::Angle a2{20_deg};
  qt::Angle a3{30_deg};
  qt::Angle a4{30_deg};

  EXPECT_TRUE(a3 == a4);
  EXPECT_TRUE(a3 > a2);
  EXPECT_TRUE(a3 >= a2);
  EXPECT_TRUE(a3 >= a4);
  EXPECT_TRUE(a1 < a2);
  EXPECT_TRUE(a2 <= a3);
  EXPECT_TRUE(a3 <= a4);
  EXPECT_TRUE(a1 != a3);
}

TEST(AngleTests, ArithmeticOperatorOverloads)
{
  qt::Angle l1{100_deg};
  qt::Angle l2{200_deg};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.deg(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.deg(), 100);

  l3 -= 100_deg;
  l4 += 100_deg;
  EXPECT_DOUBLE_EQ(l3.deg(), l4.deg());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.deg(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.deg(), 100);

  EXPECT_DOUBLE_EQ((-l3).deg(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.deg(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.deg(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.deg(), 100);
}