#include "../src/guia1.h"
#include <gtest/gtest.h>

class GuiaLabTest : public ::testing::Test {
protected:
  GuiaLab guia;
};

TEST(GuiaLabTest, RemainderTest) {
  GuiaLab guia;

  // Exercise 1: Calculate remainder A%B
  EXPECT_EQ(guia.get_remainder(8, 3), 2);
  EXPECT_EQ(guia.get_remainder(10, 3), 1);
  EXPECT_EQ(guia.get_remainder(20, 3), 2);
}

TEST(GuiaLabTest, IsEvenOrOdd) {
  GuiaLab guia;
  // Exrcise 2: Is even or odd
  EXPECT_STREQ(guia.is_even_or_odd(2), "par");
  EXPECT_STREQ(guia.is_even_or_odd(15467), "impar");
  EXPECT_STREQ(guia.is_even_or_odd(2323), "impar");
}

TEST(GuiaLabTest, WhoIsBiggerTest) {
  GuiaLab guia;
  EXPECT_EQ(guia.who_is_bigger(7, 3), 7);
}
