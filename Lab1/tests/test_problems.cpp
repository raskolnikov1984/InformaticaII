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

// Problem #6

TEST_F(ProblemsTest, CALCULATE_APPROXIMATE_EULUER_VALUE) {
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(3), 2.5);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(10), 2.71828175);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(20), 2.71828198);
  EXPECT_FLOAT_EQ(guia.calculate_aproximate_euluer_value(30), 2.71828198);
}
