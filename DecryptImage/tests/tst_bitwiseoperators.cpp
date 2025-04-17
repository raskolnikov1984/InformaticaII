#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <bitset>

using namespace testing;
using namespace std;

TEST(BitWiseOperators, BitWiseOperatorsXOR)
{
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

TEST(BitWiseOperators, BitWiseOperatorsShiftLeft)
{
    /*
    N << m = [ N << (m-1) ] * 2
    */

    EXPECT_EQ(212 << 0, 212);
    EXPECT_EQ(212 << 1, 424);
    EXPECT_EQ(212 << 2, 848);
    EXPECT_EQ(212 << 3, 1696);
}

TEST(BitWiseOperators, BitWiseOperatorsShiftRight)
{
    /*
    N >> m = [ N >> (m-1) ] / 2
    */

    EXPECT_EQ(212 >> 0, 212);
    EXPECT_EQ(212 >> 1, 106);
    EXPECT_EQ(212 >> 2, 53);
    EXPECT_EQ(212 >> 3, 26);
}


TEST(BitWiseOperators, BitWiseOperatorsRotateLeft){
    int n = 3;
    unsigned char value = 212;
    EXPECT_EQ(((value << 3 ) | (value >> (8 - n))) & 0xFF, 166);
}

TEST(BitWiseOperators, BitWiseOperatorsRotateRight){
    int n = 3;
    unsigned char value = 212;
    EXPECT_EQ(((value >> 3 ) | (value << (8 - n))) & 0xFF, 154);
}
