//
// Created by daniel on 28/12/22.
//


#include "gtest/gtest.h"
#include "ex_1_4.h"


TEST(TestLetterCountStruct, Comparison)
{
    letterCount cnt_1 {'a', 2};
    letterCount cnt_2 {'b', 4};

    ASSERT_TRUE(cnt_2 > cnt_1);
}


TEST(TestIsPalindromePermutation, SingleChar)
{
    std::string str {"a"};
    ASSERT_TRUE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, Palindrome1)
{
    std::string str {"aab"};
    ASSERT_TRUE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, Palindrome2)
{
    std::string str {"baabc"};
    ASSERT_TRUE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, Palindrome3)
{
    std::string str {"tactcoa"};
    ASSERT_TRUE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, Palindrome4)
{
    std::string str {"anitalavalatina"};
    ASSERT_TRUE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, NotPalindrome1)
{
    std::string str {"tactcoe"};
    ASSERT_FALSE(isPalindromePermutation(str));
}


TEST(TestIsPalindromePermutation, NotPalindrome2)
{
    std::string str {"abc"};
    ASSERT_FALSE(isPalindromePermutation(str));
}
