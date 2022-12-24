//
// Created by daniel on 24/12/22.
//

#include "gtest/gtest.h"
#include "ex_1_1.h"


TEST(StringHasUniqueCharacters, StringWithDifferentCharacters)
{
    std::string str {"abcdef"};
    ASSERT_TRUE(hasUniqueChars(str));
}


TEST(StringHasUniqueCharacters, LongStringWithDifferentCharacters)
{
    std::string str {"gatosinwrz"};
    ASSERT_TRUE(hasUniqueChars(str));
}


TEST(StringHasUniqueCharacters, StringWithRepeatedCharacters)
{
    std::string str {"caca"};
    ASSERT_FALSE(hasUniqueChars(str));
}


TEST(StringHasUniqueCharacters, LongerStringWithRepeatedCharacters)
{
    std::string str {"hola bola"};
    ASSERT_FALSE(hasUniqueChars(str));
}
