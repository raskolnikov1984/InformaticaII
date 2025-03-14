#include "../src/problems.h"
#include <gtest/gtest.h>

class ProblemsTest : public ::testing::Test {
public:
  Guia1Problems guia;
  ReturnCashStruc return_cash_struc;
};

TEST_F(ProblemsTest, IsVowelOrConsonantTest) {
  EXPECT_STREQ(guia.is_vowel_or_consonant('a'), "is a vowel");
  EXPECT_STREQ(guia.is_vowel_or_consonant('}'), "undefined");
  EXPECT_STREQ(guia.is_vowel_or_consonant('c'), "is a consonant");
}

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
