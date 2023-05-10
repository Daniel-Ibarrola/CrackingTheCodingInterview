//
// Created by daniel on 10/05/23.
//

#include "arrays.h"


void evenOdd(std::vector<int>& array)
{
    std::size_t next_even {0};
    std::size_t next_odd {array.size() - 1};
    while (next_even < next_odd)
    {
        if (array[next_even] % 2 == 0)
            ++next_even;
        else
        {
            std::swap(array[next_even], array[next_odd]);
            --next_odd;
        }
    }
}
