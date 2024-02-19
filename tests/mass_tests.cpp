/**
 * @file mass_tests.cpp
 * @brief Implement unit tests for Mass
 *
 */

#include <gtest/gtest.h>
#include "mass.hpp"

TEST(MassTests, ConstructorAndSettersGetters)
{
  qt::Mass s1{Gram{5.0}};
  EXPECT_DOUBLE_EQ(s1.gram(), 5.0);
  s1.gram(10.0);
  EXPECT_DOUBLE_EQ(s1.gram(), 10.0);

  qt::Mass s2{Kilogram{5.0}};
  EXPECT_DOUBLE_EQ(s2.kg(), 5.0);
  s2.kg(10.0);
  EXPECT_DOUBLE_EQ(s2.kg(), 10.0);

  qt::Mass s3{Pound{5.0}};
  EXPECT_DOUBLE_EQ(s3.lb(), 5.0);
  s3.lb(10.0);
  EXPECT_DOUBLE_EQ(s3.lb(), 10.0);
}

TEST(MassTests, UserDefinedLiterals)
{
  qt::Mass s1 = 10_gram;
  qt::Mass s2 = 10.0_gram;
  EXPECT_DOUBLE_EQ(s1.gram(), s2.gram());

  s1 = 10_kg;
  s2 = 10.0_kg;
  EXPECT_DOUBLE_EQ(s1.kg(), s2.kg());

  s1 = 10_lb;
  s2 = 10.0_lb;
  EXPECT_DOUBLE_EQ(s1.lb(), s2.lb());
}

TEST(MassTests, ComparisonOperators)
{
  qt::Mass l1{5_kg};
  qt::Mass l2{10_kg};
  qt::Mass l3{15_kg};
  qt::Mass l4{15_kg};

  EXPECT_TRUE(l3 == l4);
  EXPECT_TRUE(l3 > l2);
  EXPECT_TRUE(l3 >= l2);
  EXPECT_TRUE(l3 >= l4);
  EXPECT_TRUE(l1 < l2);
  EXPECT_TRUE(l2 <= l3);
  EXPECT_TRUE(l3 <= l4);
  EXPECT_TRUE(l1 != l3);
}

TEST(MassTests, ArithmeticOperatorOverloads)
{

  qt::Mass l1{100_kg};
  qt::Mass l2{200_kg};

  auto l3 = l1 + l2;
  EXPECT_DOUBLE_EQ(l3.kg(), 300);

  auto l4 = l2 - l1;
  EXPECT_DOUBLE_EQ(l4.kg(), 100);

  l3 -= 100_kg;
  l4 += 100_kg;
  EXPECT_DOUBLE_EQ(l3.kg(), l4.kg());

  l3 *= 2.0;
  EXPECT_DOUBLE_EQ(l3.kg(), 400);

  l3 /= 4.0;
  EXPECT_DOUBLE_EQ(l3.kg(), 100);

  EXPECT_DOUBLE_EQ((-l3).kg(), -100.0);

  auto l5 = l1 * 2.0;
  EXPECT_DOUBLE_EQ(l5.kg(), 200);

  auto l6 = 2.0 * l1;
  EXPECT_DOUBLE_EQ(l6.kg(), 200);

  auto l7 = l6 / 2.0;
  EXPECT_DOUBLE_EQ(l7.kg(), 100);
}