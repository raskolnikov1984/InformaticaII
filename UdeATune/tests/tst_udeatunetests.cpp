#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../udeatune.cpp"

using namespace testing;

TEST(UdeATuneTests, UdeATuneTests)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
