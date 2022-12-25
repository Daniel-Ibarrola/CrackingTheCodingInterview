//
// Created by daniel on 24/12/22.
//

#include "ex_1_1.h"


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
