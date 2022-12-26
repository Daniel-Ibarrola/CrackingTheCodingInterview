//
// Created by daniel on 25/12/22.
//

#include "ex_1_2.h"


bool isPermutation(const std::string& string, const std::string& other)
{
    // Given two strings check if one is a permutation of the other
    if (string.size() != other.size())
        return false;

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
