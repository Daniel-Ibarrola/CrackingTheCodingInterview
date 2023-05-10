//
// Created by daniel on 10/05/23.
//

#include "gtest/gtest.h"
#include "strings_algo.h"



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


TEST(IsPermutationTest, DifferentLenghts)
{
    ASSERT_FALSE(isPermutation("abc", "abcd"));
}


TEST(IsPermutationTest, Permutation)
{
    ASSERT_TRUE(isPermutation("abcd", "bacd"));
    ASSERT_TRUE(isPermutation("abcd", "dcab"));
}


TEST(IsPermutationTest, NoPermutation)
{
    ASSERT_FALSE(isPermutation("abcd", "abce"));
}


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


TEST(TestIsPalindoromePermutation, CaseAndSpaceInsensitive)
{
    std::string str {"Tact Coa"};
    ASSERT_TRUE(isPalindromePermutation(str));
}

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
