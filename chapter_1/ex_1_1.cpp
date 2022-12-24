//
// Created by daniel on 24/12/22.
//

#include "ex_1_1.h"


bool hasUniqueChars(const std::string& string)
{
    // Returns true if the given string characters are all different
    std::map<char, int> charCount;
    for (auto c : string)
    {
        if (charCount.find(c) == charCount.end())
            charCount[c] = 1;
        else
            return false;
    }
    return true;
}
