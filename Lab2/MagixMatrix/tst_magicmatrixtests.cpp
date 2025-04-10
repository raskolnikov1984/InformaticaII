#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "./magicmatrix.h"

using namespace testing;

TEST(MagicMatrix, MagicMatrixTests)
{
    MagicMatrix matrix(3);

    matrix.Matrix[0][0] = 4;
    matrix.Matrix[0][1] = 9;
    matrix.Matrix[0][2] = 2;

    matrix.Matrix[1][0] = 3;
    matrix.Matrix[1][1] = 5;
    matrix.Matrix[1][2] = 7;

    matrix.Matrix[2][0] = 8;
    matrix.Matrix[2][1] = 1;
    matrix.Matrix[2][2] = 6;

    matrix.print_matrix();

    EXPECT_EQ(matrix.is_magic_matrix(), true);
}
