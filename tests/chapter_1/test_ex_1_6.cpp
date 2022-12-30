//
// Created by daniel on 30/12/22.
//


#include "gtest/gtest.h"
#include "ex_1_6.h"


TEST(TestStringCompression, String1)
{
    std::string str {"aaa"};
    std::string compressed {"a3"};
    ASSERT_EQ(compress(str), compressed);
}


TEST(TestStringCompression, String2)
{
    std::string str {"aabcccccaaa"};
    std::string compressed {"a2b1c5a3"};
    ASSERT_EQ(compress(str), compressed);
}


TEST(TestStringCompression, UncompressableString1)
{
    std::string str {"abc"};
    ASSERT_EQ(compress(str), str);
}


TEST(TestStringCompression, UncompressableString2)
{
    std::string str {"aa"};
    ASSERT_EQ(compress(str), str);
}
