//
// Created by daniel on 30/12/22.
//

#include "ex_1_6.h"


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
