#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "./lowercase_to_uppercase.h"


using namespace testing;

TEST(LoweCaseToUpperCase, LoweCaseToUpperCase)
{
    char world[] = "Man-zana";

    EXPECT_STREQ(convert_lowercase_to_uppercase(world), "MAN-ZANA");

}

TEST(CalculateStringLenght, CalculateStringLenghtTest){
    char world[] = "Man-zana";
    EXPECT_EQ(calculate_string_lenght(world), 8);
}

