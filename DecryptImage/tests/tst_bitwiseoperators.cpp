#include <bitset>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace std;

TEST(BitWiseOperators, BitWiseOperatorsXOR) {
  /*
  12 = 00001100 (In Binary)
  25 = 00011001 (In Binary)

       Bitwise XOR Operation of 12 and 25
       00001100
   ^   00011001
       _________
      00010101  = 21 (In decimal)
  */
  EXPECT_EQ(12 ^ 25, 21);
  EXPECT_EQ(bitset<8>(12) ^ bitset<8>(25), bitset<8>(21));
  EXPECT_EQ(0b00001100 ^ 0b00011001, 0b00010101);
}

TEST(BitWiseOperators, BitWiseOperatorsShiftLeft) {
  /*
  N << m = [ N << (m-1) ] * 2
  */

  EXPECT_EQ(212 << 0, 212);
  EXPECT_EQ(212 << 1, 424);
  EXPECT_EQ(212 << 2, 848);
  EXPECT_EQ(212 << 3, 1696);
}

TEST(BitWiseOperators, BitWiseOperatorsShiftRight) {
  /*
  N >> m = [ N >> (m-1) ] / 2
  */

  EXPECT_EQ(212 >> 0, 212);
  EXPECT_EQ(212 >> 1, 106);
  EXPECT_EQ(212 >> 2, 53);
  EXPECT_EQ(212 >> 3, 26);
}

TEST(BitWiseOperators, BitWiseOperatorsRotateLeft) {
  /* 212 -> 11010100
   * 212 <- 3 = 10100000
   * 212 -> 5 = 00000110
   * Expected: 10100110
   *
   * 10100000
   *    or
   * 00000110
   * _________
   * 10100110
   * */
  int n = 3;
  unsigned char value = 212;
  EXPECT_EQ(((value << 3) | (value >> (8 - n))) & 0xFF, 166);
}

TEST(BitWiseOperators, BitWiseOperatorsRotateRight) {
  /*
   * 212 -> 11010100
   * 212 -> 3 = 00011010
   * 212 <- 5 = 10000000
   * Expected: 10011010
   *
   * b00011010
   *    or
   * b10000000
   * _________
   * b10011010
   *
   * */
  int n = 3;
  unsigned char value = 212;
  EXPECT_EQ(((value >> 3) | (value << (8 - n))) & 0xFF, 154);
}
