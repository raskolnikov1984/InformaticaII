#include "../src/guia1.h"
#include <gtest/gtest.h>

class GuiaLabTest : public ::testing::Test {
protected:
  GuiaLab guia;
};

// Exercise 1: Calculate remainder A%B
TEST_F(GuiaLabTest, RemainderTest) {
  EXPECT_EQ(guia.get_remainder(8, 3), 2);
  EXPECT_EQ(guia.get_remainder(10, 3), 1);
  EXPECT_EQ(guia.get_remainder(20, 3), 2);
}

// Exercise 2
TEST_F(GuiaLabTest, IsEvenOrOdd) {
  EXPECT_STREQ(guia.is_even_or_odd(2), "par");
  EXPECT_STREQ(guia.is_even_or_odd(15467), "impar");
  EXPECT_STREQ(guia.is_even_or_odd(2323), "impar");
}

// Exercise 3
TEST_F(GuiaLabTest, WhoIsBiggerTest) { EXPECT_EQ(guia.who_is_bigger(7, 3), 7); }

// Exercise 4
TEST_F(GuiaLabTest, WhoIsSmallestTest) {
  EXPECT_EQ(guia.who_is_smallest(7, 3), 3);
}

// Exercise 5
TEST_F(GuiaLabTest, CalculateAdividedB) {
  EXPECT_EQ(guia.calculate_a_divided_b(8, 3), 3);
  EXPECT_EQ(guia.calculate_a_divided_b(7, 3), 2);
  EXPECT_EQ(guia.calculate_a_divided_b(6, 4), 2);
}

// Excercise 6: A power B
TEST_F(GuiaLabTest, ApowerBTest) {
  EXPECT_EQ(guia.calculate_a_power_b(5, 3), 125);
}

// Excercise 7:
TEST_F(GuiaLabTest, SumFirstNTermsTest) {
  EXPECT_EQ(guia.sum_first_n_terms(5), 15);
}

// Excercise 8:
TEST_F(GuiaLabTest, CalculateFactorialTest) {
  EXPECT_EQ(guia.calculate_factorial(5), 120);
}

// Excercise 9:
TEST_F(GuiaLabTest, CalculatePerimeterAndAreaTest) {
  EXPECT_EQ(guia.calculate_perimeter_circle(1.0), 6.2831997871398926);
  EXPECT_EQ(guia.calculate_area_circle(1.0), 3.1415998935699463);
}

// Excercise 12:
TEST_F(GuiaLabTest, Power5Test) {
  EXPECT_EQ(guia.calculate_firts_five_powers(2), 32);
}

// Exercise 13:
TEST_F(GuiaLabTest, N_DividersTest) {
  EXPECT_EQ(guia.calculate_dividers(4), 4);
}

// Excercise 14:
TEST_F(GuiaLabTest, PrintParallelColums) {
  // EXPECT_STREQ(guia.print_parallel_colunms(50), "50   1");
}

// Exercise 15:
TEST_F(GuiaLabTest, WhileSumTets) {
  // EXPECT_EQ(guia.while_sum())
}
