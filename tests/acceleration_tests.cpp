/**
 * @file acceleration_tests.cpp
 * @brief Implement unit tests for acceleration
 *
 */

#include <gtest/gtest.h>
#include "acceleration.hpp"

TEST(AccelerationTests, ConstructorAndSettersGetters)
{
  qt::Acceleration a1{MeterPerSecSq{1.75}};
  EXPECT_DOUBLE_EQ(a1.mps2(), 1.75);
  a1.mps2(2.15);
  EXPECT_DOUBLE_EQ(a1.mps2(), 2.15);

  qt::Acceleration a2{FeetPerSecSq{1.75}};
  EXPECT_DOUBLE_EQ(a2.fps2(), 1.75);
  a2.fps2(2.15);
  EXPECT_DOUBLE_EQ(a2.fps2(), 2.15);

  qt::Acceleration a3{AccelG{2.0}};
  EXPECT_DOUBLE_EQ(a3.g(), 2.0);
  a3.g(4.0);
  EXPECT_DOUBLE_EQ(a3.g(), 4.0);
}

TEST(AccelerationTests, UserDefinedLiterals)
{
  qt::Acceleration a1 = 2_mps2;
  qt::Acceleration a2 = 2.0_mps2;
  EXPECT_DOUBLE_EQ(a1.mps2(), a2.mps2());

  a1 = 180_fps2;
  a2 = 180.0_fps2;
  EXPECT_DOUBLE_EQ(a1.fps2(), a2.fps2());

  a1 = 2_g;
  a2 = 2.0_g;
  EXPECT_DOUBLE_EQ(a1.g(), a2.g());
}

TEST(AccelerationTests, ComparisonOperators)
{
  qt::Acceleration a1{10_mps2};
  qt::Acceleration a2{20_mps2};
  qt::Acceleration a3{30_mps2};
  qt::Acceleration a4{30_mps2};

  EXPECT_TRUE(a3 == a4);
  EXPECT_TRUE(a3 > a2);
  EXPECT_TRUE(a3 >= a2);
  EXPECT_TRUE(a3 >= a4);
  EXPECT_TRUE(a1 < a2);
  EXPECT_TRUE(a2 <= a3);
  EXPECT_TRUE(a3 <= a4);
  EXPECT_TRUE(a1 != a3);
}

TEST(AccelerationTests, ArithmeticOperatorOverloads)
{
  qt::Acceleration l1{100_mps2};
  qt::Acceleration l2{200_mps2};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.mps2(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.mps2(), 100);

  l3 -= 100_mps2;
  l4 += 100_mps2;
  EXPECT_DOUBLE_EQ(l3.mps2(), l4.mps2());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.mps2(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.mps2(), 100);

  EXPECT_DOUBLE_EQ((-l3).mps2(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.mps2(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.mps2(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.mps2(), 100);
}