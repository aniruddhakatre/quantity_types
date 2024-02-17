/**
 * @file speed_tests.cpp
 * @brief Implement unit tests for Speed
 *
 */

#include <gtest/gtest.h>
#include "speed.hpp"

TEST(SpeedTests, ConstructorsAndSettersGetters)
{
  qt::Speed s1{MeterPerSec{5.0}};
  EXPECT_DOUBLE_EQ(s1.mps(), 5.0);
  s1.mps(10.0);
  EXPECT_DOUBLE_EQ(s1.mps(), 10.0);

  qt::Speed s2{FeetPerMin{5.0}};
  EXPECT_DOUBLE_EQ(s2.fpm(), 5.0);
  s2.fpm(10.0);
  EXPECT_DOUBLE_EQ(s2.fpm(), 10.0);

  qt::Speed s3{KilometerPerHour{5.0}};
  EXPECT_DOUBLE_EQ(s3.kph(), 5.0);
  s3.kph(10.0);
  EXPECT_DOUBLE_EQ(s3.kph(), 10.0);

  qt::Speed s4{Knots{5.0}};
  EXPECT_DOUBLE_EQ(s4.kts(), 5.0);
  s4.kts(10.0);
  EXPECT_DOUBLE_EQ(s4.kts(), 10.0);
}

TEST(SpeedTests, UserDefinedLiterals)
{
  qt::Speed s1 = 10_mps;
  qt::Speed s2 = 10.0_mps;
  EXPECT_DOUBLE_EQ(s1.mps(), s2.mps());

  s1 = 10_fpm;
  s2 = 10.0_fpm;
  EXPECT_DOUBLE_EQ(s1.fpm(), s2.fpm());

  s1 = 10_kph;
  s2 = 10.0_kph;
  EXPECT_DOUBLE_EQ(s1.kph(), s2.kph());

  s1 = 10_kts;
  s2 = 10.0_kts;
  EXPECT_DOUBLE_EQ(s1.kts(), s2.kts());
}

TEST(SpeedTests, ComparisonOperators)
{
  qt::Speed l1{5_mps};
  qt::Speed l2{10_mps};
  qt::Speed l3{15_mps};
  qt::Speed l4{15_mps};

  EXPECT_TRUE(l3 == l4);
  EXPECT_TRUE(l3 > l2);
  EXPECT_TRUE(l3 >= l2);
  EXPECT_TRUE(l3 >= l4);
  EXPECT_TRUE(l1 < l2);
  EXPECT_TRUE(l2 <= l3);
  EXPECT_TRUE(l3 <= l4);
  EXPECT_TRUE(l1 != l3);
}

TEST(SpeedTests, ArithmeticOperatorOverloads)
{

  qt::Speed l1{100_mps};
  qt::Speed l2{200_mps};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.mps(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.mps(), 100);

  l3 -= 100_mps;
  l4 += 100_mps;
  EXPECT_DOUBLE_EQ(l3.mps(), l4.mps());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.mps(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.mps(), 100);

  EXPECT_DOUBLE_EQ((-l3).mps(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.mps(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.mps(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.mps(), 100);

  qt::Duration d{Second{5.}};
  qt::Length l8{Meter{50.}};
  qt::Speed s1 = l8 / d;
  EXPECT_DOUBLE_EQ(s1.mps(), 10.0);
}