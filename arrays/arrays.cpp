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


void dutchFlagPartition(std::vector<int>& array, std::size_t pivotInd)
{
    // Arranges the element of the gicen array so taht all elements less than
    // array[pivotInd] appear first, followed by equal elements and then greater elements
    int pivot {array[pivotInd]};
    std::size_t smaller {0};
    for (auto ii {0}; ii < array.size(); ++ii)
    {
        if (array[ii] < pivot)
        {
            std::swap(array[ii], array[smaller]);
            ++smaller;
        }
    }

    std::size_t larger {array.size() - 1};
    for (int ii {static_cast<int>(array.size() - 1)}; ii >= 0 && array[ii] >= pivot; --ii)
    {
        if (array[ii] > pivot)
        {
            std::swap(array[ii], array[larger]);
            --larger;
        }
    }
}
