/**
 * @file duration_tests.cpp
 * @brief Implement unit tests for duration
 *
 */

#include <gtest/gtest.h>
#include "duration.hpp"

TEST(DurationTests, ConstructorAndSettersGetters)
{
  qt::Duration d1{Second{500.0}};
  EXPECT_DOUBLE_EQ(d1.sec(), 500.0);
  d1.sec(100.);
  EXPECT_DOUBLE_EQ(d1.sec(), 100.0);

  qt::Duration d2{Millisecond{500.0}};
  EXPECT_DOUBLE_EQ(d2.msec(), 500.0);
  d2.msec(100.);
  EXPECT_DOUBLE_EQ(d2.msec(), 100.0);

  qt::Duration d3{Microsecond{500.0}};
  EXPECT_DOUBLE_EQ(d3.usec(), 500.0);
  d3.usec(100.);
  EXPECT_DOUBLE_EQ(d3.usec(), 100.0);

  qt::Duration d4{Minute{500.0}};
  EXPECT_DOUBLE_EQ(d4.min(), 500.0);
  d4.min(100.);
  EXPECT_DOUBLE_EQ(d4.min(), 100.0);

  qt::Duration d5{Hour{500.0}};
  EXPECT_DOUBLE_EQ(d5.hr(), 500.0);
  d5.hr(100.);
  EXPECT_DOUBLE_EQ(d5.hr(), 100.0);
}

TEST(DurationTests, UserDefinedLiterals)
{
  qt::Duration d1 = 100_sec;
  qt::Duration d2 = 100.0_sec;
  EXPECT_DOUBLE_EQ(d1.sec(), d2.sec());

  d1 = 100_msec;
  d2 = 100.0_msec;
  EXPECT_DOUBLE_EQ(d1.msec(), d2.msec());

  d1 = 100_usec;
  d2 = 100.0_usec;
  EXPECT_DOUBLE_EQ(d1.usec(), d2.usec());

  d1 = 100_min;
  d2 = 100.0_min;
  EXPECT_DOUBLE_EQ(d1.min(), d2.min());

  d1 = 100_hr;
  d2 = 100.0_hr;
  EXPECT_DOUBLE_EQ(d1.hr(), d2.hr());
}

TEST(DurationTests, ComparisonOperators)
{
  qt::Duration d1{5_sec};
  qt::Duration d2{10_sec};
  qt::Duration d3{15_sec};
  qt::Duration d4{15_sec};

  EXPECT_TRUE(d3 == d4);
  EXPECT_TRUE(d3 > d2);
  EXPECT_TRUE(d3 >= d2);
  EXPECT_TRUE(d3 >= d4);
  EXPECT_TRUE(d1 < d2);
  EXPECT_TRUE(d2 <= d3);
  EXPECT_TRUE(d3 <= d4);
  EXPECT_TRUE(d1 != d3);
}

TEST(DurationTests, ArithmeticOperatorOverloads)
{
  qt::Duration l1{100_sec};
  qt::Duration l2{200_sec};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.sec(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.sec(), 100);

  l3 -= 100_sec;
  l4 += 100_sec;
  EXPECT_DOUBLE_EQ(l3.sec(), l4.sec());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.sec(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.sec(), 100);

  EXPECT_DOUBLE_EQ((-l3).sec(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.sec(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.sec(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.sec(), 100);
}