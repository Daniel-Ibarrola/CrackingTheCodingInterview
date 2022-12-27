//
// Created by daniel on 26/12/22.
//


#include "gtest/gtest.h"
#include "ex_1_3.h"


TEST(TestURLify, StringWithNoSpacesIsNotModified)
{
    std::string str {"HelloWorld"};
    URLify(str, 10);
    ASSERT_EQ(str, "HelloWorld");
}


TEST(TestURLify, ReturnsCorrectURL)
{
    std::string str {"Mr John Smith    "};
    URLify(str, 13);
    ASSERT_EQ(str, "Mr%20John%20Smith");
}


TEST(TestUrlify, StringOfOnlySpaces)
{
    std::string str {"      "};
    URLify(str, 0);
    ASSERT_EQ(str, "      ");
}
