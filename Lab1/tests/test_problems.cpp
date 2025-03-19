#include "../src/problems.h"
#include <gtest/gtest.h>

class ProblemsTest : public ::testing::Test {
public:
  Guia1Problems guia;
  Guia1Problems::ReturnCashStruc return_cash_struc;
};

// Problem #1:
TEST_F(ProblemsTest, IsVowelOrConsonantTest) {
  EXPECT_STREQ(guia.is_vowel_or_consonant('a'), "is a vowel");
  EXPECT_STREQ(guia.is_vowel_or_consonant('}'), "undefined");
  EXPECT_STREQ(guia.is_vowel_or_consonant('c'), "is a consonant");
}

// Problem #2
TEST_F(ProblemsTest, CalculateReturnCashTest) {
  int return_cash = 47810;
  return_cash_struc = guia.calculate_return_cash(return_cash);
  EXPECT_EQ(return_cash_struc.fiftyThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.twentyThousandCOP, 2);
  EXPECT_EQ(return_cash_struc.tenThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.fiveThousandCOP, 1);
  EXPECT_EQ(return_cash_struc.twoThousandCOP, 1);
  EXPECT_EQ(return_cash_struc.oneThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.fiveHoundredCOP, 1);
  EXPECT_EQ(return_cash_struc.twoHoundredCOP, 1);
  EXPECT_EQ(return_cash_struc.oneHoundredCOP, 1);
  EXPECT_EQ(return_cash_struc.fiftyCOP, 0);
  EXPECT_EQ(return_cash_struc.remainderCOP, 10);

  return_cash = 125270;
  return_cash_struc = guia.calculate_return_cash(return_cash);
  EXPECT_EQ(return_cash_struc.fiftyThousandCOP, 2);
  EXPECT_EQ(return_cash_struc.twentyThousandCOP, 1);
  EXPECT_EQ(return_cash_struc.tenThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.fiveThousandCOP, 1);
  EXPECT_EQ(return_cash_struc.twoThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.oneThousandCOP, 0);
  EXPECT_EQ(return_cash_struc.fiveHoundredCOP, 0);
  EXPECT_EQ(return_cash_struc.twoHoundredCOP, 1);
  EXPECT_EQ(return_cash_struc.oneHoundredCOP, 0);
  EXPECT_EQ(return_cash_struc.fiftyCOP, 1);
  EXPECT_EQ(return_cash_struc.remainderCOP, 20);
}

// Problem #3
TEST_F(ProblemsTest, IsValidDateTest) {
  EXPECT_EQ(guia.isValidDate(31, 4), false);
  EXPECT_EQ(guia.isValidDate(27, 4), true);
  EXPECT_EQ(guia.isValidDate(29, 2), true);
}

// Problem #4
TEST_F(ProblemsTest, CalculateSumTime) {
  EXPECT_EQ(guia.calculate_sum_time(1245, 345), 1630);
  EXPECT_EQ(guia.calculate_sum_time(2300, 120), 20);
  EXPECT_EQ(guia.calculate_sum_time(300, 150), 450);
}

// Problem #5
TEST_F(ProblemsTest, PrintDiamond) { guia.printDiamond(7); }

// Problem #6
TEST_F(ProblemsTest, CALCULATE_APPROXIMATE_EULUER_VALUE) {
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(3), 2.5);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(10), 2.71828175);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(20), 2.71828198);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(30), 2.71828198);
}

// Problem #7
TEST_F(ProblemsTest, CalculateSumEvenNumberInFibonacciTest) {
  EXPECT_EQ(guia.calculate_sum_even_numbers_in_fibonacci(10), 10);
}

// Problem #8
TEST_F(ProblemsTest, SumNCommonsMultiplesTest) {
  EXPECT_EQ(guia.sum_n_commons_multiples(3, 5, 10), 23);
}

// Power
TEST_F(ProblemsTest, PowerTest) { EXPECT_EQ(guia.power(2, 3), 8); }

// Problem #9
TEST_F(ProblemsTest, SumPowersOfDigitsTest) {
  EXPECT_EQ(guia.sum_powers_of_digits(3), 27);
  EXPECT_EQ(guia.sum_powers_of_digits(10), 2);
  EXPECT_EQ(guia.sum_powers_of_digits(1223), 36);
}

TEST_F(ProblemsTest, CalculateNTermPrimeTest) {
  EXPECT_EQ(guia.calculate_n_term_prime(4), 7);
}

TEST_F(ProblemsTest, LeastCommonMultipleTest) {
  EXPECT_EQ(guia.least_common_multiple(2, 3), 6);
  EXPECT_EQ(guia.least_common_multiple(2, 4), 4);
}

TEST_F(ProblemsTest, LeastCommonMultipleUntilNumberTest) {
  EXPECT_EQ(guia.least_common_multiple_until_number(4), 12);
  EXPECT_EQ(guia.least_common_multiple_until_number(10), 2520);
}

TEST_F(ProblemsTest, MaximePrimeFactorTest) {
  EXPECT_EQ(guia.maxime_prime_factor(10), 5);
  EXPECT_EQ(guia.maxime_prime_factor(33), 11);
  EXPECT_EQ(guia.maxime_prime_factor(20), 5);
  EXPECT_EQ(guia.maxime_prime_factor(100), 5);
}

TEST_F(ProblemsTest, SumPrimesUntilNumberTest) {
  EXPECT_EQ(guia.sum_primes_until_number(10), 17);
  EXPECT_EQ(guia.sum_primes_until_number(1000), 76127);
}
