#include "../src/guia1.h"
#include <gtest/gtest.h>

class GuiaLabTest : public ::testing::Test {
protected:
  GuiaLab guia;
};

// Exercise 1: Calculate remainder A%B
TEST(GuiaLabTest, RemainderTest) {
  GuiaLab guia;

  EXPECT_EQ(guia.get_remainder(8, 3), 2);
  EXPECT_EQ(guia.get_remainder(10, 3), 1);
  EXPECT_EQ(guia.get_remainder(20, 3), 2);
}

// Exercise 2
TEST(GuiaLabTest, IsEvenOrOdd) {
  GuiaLab guia;
  EXPECT_STREQ(guia.is_even_or_odd(2), "par");
  EXPECT_STREQ(guia.is_even_or_odd(15467), "impar");
  EXPECT_STREQ(guia.is_even_or_odd(2323), "impar");
}

// Exercise 3
TEST(GuiaLabTest, WhoIsBiggerTest) {
  GuiaLab guia;
  EXPECT_EQ(guia.who_is_bigger(7, 3), 7);
}

// Exercise 4
TEST(GuiaLabTest, WhoIsSmallestTest) {
  GuiaLab guia;
  EXPECT_EQ(guia.who_is_smallest(7, 3), 3);
}

// Exercise 5
TEST(GuiaLabTest, CalculateAdividedB) {
  GuiaLab guia;
  EXPECT_EQ(guia.calculate_a_divided_b(8, 3), 3);
  EXPECT_EQ(guia.calculate_a_divided_b(7, 3), 2);
}

// Excercise 6: A power B
TEST(GuiaLabTest, ApowerB) {
  GuiaLab guia;
  EXPECT_EQ(guia.calculate_a_power_b(5, 3), 125);
}
