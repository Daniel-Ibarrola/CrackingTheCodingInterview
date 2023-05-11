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
    // Arranges the element of the given array so that all elements less than
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


void incrementNumber(std::vector<int>& digits)
{
    // Given an array of digits encoding a decimal number D, modifies it to
    // represent D + 1
    for (int ii {static_cast<int>(digits.size()) - 1}; ii >= 0; --ii)
    {
        if (digits[ii] < 9)
        {
            ++digits[ii];
            break;
        }
        digits[ii] = 0;
    }
    if (digits[0] == 0)
        digits.insert(digits.begin(), 1);
}


int stockMaxProfit(const std::vector<int>& prices)
{
    if (prices.empty())
        return 0;

    int currentMin {prices[0]};
    int maxProfit {std::numeric_limits<int>::min()};
    for (int ii {0}; ii < prices.size() - 1; ++ii)
    {
        currentMin = std::min(prices[ii], currentMin);
        maxProfit = std::max(prices[ii] - currentMin, maxProfit);
    }
    return maxProfit;
}
