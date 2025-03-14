#include "../src/problems.h"
#include <gtest/gtest.h>

class ProblemsTest : public ::testing::Test {
public:
  Guia1Problems guia;
};

TEST_F(ProblemsTest, IsVowelOrConsonantTest) {
  /*
  EXPECT_STREQPECT_STREQ(ProblemsTest::ProblemsTestguia::is_vowel_or_consonant('c'),
  "is a consonant"); EXPECT_STREQ(ProblemsTest.guia::is_vowel_or_consonant('a'),
  "is a vowel"); EXPECT_STREQ(ProblemsTest.guia::is_vowel_or_consonant('}'),
  "undefined");
  */
  EXPECT_STREQ(guia.is_vowel_or_consonant('c'), "is a consonant");
}
