//
// Created by daniel on 28/12/22.
//

#include "ex_1_4.h"

std::array<int, 128> getCharCount(const std::string& str)
{
    // Count the frequency of each character in the string. Spaces are ignored
    // and it's case-insensitive
    std::array<int, 128> frequency {0};
    for (auto ch : str)
    {
        if (ch != ' ')
            frequency[std::tolower(ch)]++;
    }
    return frequency;
}


bool checkMaxOneOdd(const std::array<int ,128>& frequency)
{
    // Check that there is one odd number at most
    bool foundOdd {false};
    for (auto freq : frequency)
    {
        if (freq % 2 == 1)
        {
            if (foundOdd) return false;
            foundOdd = true;
        }
    }
    return true;
}

bool isPalindromePermutation(const std::string& str)
{
    // Check if the given string is a permutation of a palindrome
    std::array<int, 128> charCount {getCharCount(str)};
    return checkMaxOneOdd(charCount);
}
