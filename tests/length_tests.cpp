/**
 * @file length_tests.cpp
 * @brief Implement unit tests for length
 *
 */

#include <gtest/gtest.h>
#include "length.hpp"
#include "distance.hpp"

TEST(LengthTests, ConstructorsAndSettersGetters)
{
  qt::Length l1{Meter{5.0}};
  EXPECT_DOUBLE_EQ(l1.m(), 5.0);
  l1.m(10.0);
  EXPECT_DOUBLE_EQ(l1.m(), 10.0);

  qt::Length l2{Feet{5.0}};
  EXPECT_DOUBLE_EQ(l2.ft(), 5.0);
  l2.ft(10.0);
  EXPECT_DOUBLE_EQ(l2.ft(), 10.0);

  qt::Length l3{Kilometer{5.0}};
  EXPECT_DOUBLE_EQ(l3.km(), 5.0);
  l3.km(10.0);
  EXPECT_DOUBLE_EQ(l3.km(), 10.0);

  qt::Length l4{NauticalMile{5.0}};
  EXPECT_DOUBLE_EQ(l4.nmi(), 5.0);
  l4.nmi(10.0);
  EXPECT_DOUBLE_EQ(l4.nmi(), 10.0);

  // check the distance alias of length
  qt::Distance l5{Kilometer{5.0}};
  EXPECT_TRUE((l5 != l1));
}

TEST(LengthTests, UserDefinedLiterals)
{
  qt::Length l1 = 5_m;
  qt::Length l2 = 5.0_m;
  EXPECT_DOUBLE_EQ(l1.m(), l2.m());

  l1 = 5_ft;
  l2 = 5.0_ft;
  EXPECT_DOUBLE_EQ(l1.ft(), l2.ft());

  l1 = 5_km;
  l2 = 5.0_km;
  EXPECT_DOUBLE_EQ(l1.km(), l2.km());

  l1 = 5_nmi;
  l2 = 5.0_nmi;
  EXPECT_DOUBLE_EQ(l1.nmi(), l2.nmi());
}

TEST(LengthTests, ComparisonOperators)
{
  qt::Length l1{5_m};
  qt::Length l2{10_m};
  qt::Length l3{15_m};
  qt::Length l4{15_m};

  EXPECT_TRUE(l3 == l4);
  EXPECT_TRUE(l3 > l2);
  EXPECT_TRUE(l3 >= l2);
  EXPECT_TRUE(l3 >= l4);
  EXPECT_TRUE(l1 < l2);
  EXPECT_TRUE(l2 <= l3);
  EXPECT_TRUE(l3 <= l4);
  EXPECT_TRUE(l1 != l3);
}

TEST(LengthTests, ArithmeticOperatorOverloads)
{
  qt::Length l1{100_m};
  qt::Length l2{200_m};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.m(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.m(), 100);

  l3 -= 100_m;
  l4 += 100_m;
  EXPECT_DOUBLE_EQ(l3.m(), l4.m());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.m(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.m(), 100);

  EXPECT_DOUBLE_EQ((-l3).m(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.m(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.m(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.m(), 100);
}