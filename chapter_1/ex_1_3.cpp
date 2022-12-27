//
// Created by daniel on 26/12/22.
//

#include "ex_1_3.h"


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
