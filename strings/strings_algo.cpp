//
// Created by daniel on 10/05/23.
//

#include "strings_algo.h"


bool hasUniqueChars(const std::string& string)
{
    // Returns true if the given string characters are all different
    std::array<bool, 128> found {false};
    for (auto c : string)
    {
        if (found[c])
            return false;
        found[c] = true;
    }
    return true;
}

bool isPermutation(const std::string& string, const std::string& other)
{
    // Given two strings check if one is a permutation of the other
    if (string.size() != other.size())
        return false;

    // Assumption: ASCII
    std::array<int, 128> strCount {0};
    std::array<int, 128> otherCount {0};
    for (auto ii {0}; ii < string.size(); ++ii)
    {
        strCount[string[ii]]++;
        otherCount[other[ii]]++;
    }

    for (auto ii {0}; ii < strCount.size(); ++ii)
    {
        if (strCount[ii] != otherCount[ii])
            return false;
    }

    return true;
}

void URLify(std::string& str, std::size_t length)
{
    // Replaces all spaces in the given string with "%20". The string
    // is modified in place. Assumes that the string has sufficient space
    // at the end

    // Find all spaces and store their positions
    std::stack<std::size_t> spaces;
    for (auto ii {0}; ii < length; ++ii)
    {
        if (str[ii] == ' ')
            spaces.push(ii);
    }

    std::size_t end {length};  // current word ends at this position
    while (!spaces.empty())
    {
        std::size_t shift {2 * spaces.size()};
        std::size_t start {spaces.top()};
        spaces.pop();

        // Shift words to the right accordingly
        for (auto ii {end - 1}; ii > start; --ii)
            str[ii + shift] = str[ii];
        // Add the "%20"
        str[start + shift] = '0';
        str[start + shift - 1] = '2';
        str[start + shift - 2] = '%';

        end = start;
    }
}

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


std::string compress(const std::string& str)
{
    // Compresses a string using the counts of repeated characters
    if (str.size() <= 2)
        return str;

    std::string compressed {};
    int count {0};

    for (auto ii {0}; ii < str.size(); ++ii)
    {
        count++;
        if (str[ii] != str[ii + 1] || ii + 1 >= str.size())
        {
            compressed += str[ii] + std::to_string(count);
            count = 0;
        }
    }

    return compressed.size() < str.size() ? compressed : str;
}

int stringToInt(const std::string& str)
{
    // Takes a string and returns an integer
    int result {0};
    std::size_t start {0};
    if (str[0] == '-')
        start = 1;

    for (auto ii {start}; ii < str.size(); ++ii)
        result = result*10 + (str[ii] - '0');

    return start == 0 ? result : -result;
}

std::string intToString(int number)
{
    // Takes an integer and returns a string
    std::string reverse;

    int remaining {abs(number)};
    while (remaining > 0)
    {
        reverse +=  remaining % 10 + '0';
        remaining /= 10;
    }
    if (number < 0)
        reverse += "-";

    std::reverse(reverse.begin(), reverse.end());
    return reverse;
}
