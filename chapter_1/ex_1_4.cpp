//
// Created by daniel on 28/12/22.
//

#include "ex_1_4.h"


bool operator== (const letterCount& c1, const letterCount& c2)
{
    return c1.count == c2.count;
}


bool operator< (const letterCount& c1, const letterCount& c2)
{
    return c1.count < c2.count;
}


bool operator> (const letterCount& c1, const letterCount& c2)
{
    return c1.count > c2.count;
}


std::priority_queue<letterCount> buildHeap(const std::string& str)
{
    std::array<int, 128> count{0};
    std::priority_queue<letterCount> heap;

    for (auto ch : str)
        count[ch]++;

    for (auto ii {0}; ii < count.size(); ++ii)
    {
        if (count[ii] > 0)
            heap.push({char(ii), count[ii]});
    }

    return heap;
}

bool isPalindromePermutation(const std::string& str)
{
    // Check if the given string is a permutation of a palindrome
    std::priority_queue<letterCount> heap {buildHeap(str)};
    int remaining {static_cast<int>(str.size())};

    while (!heap.empty())
    {
        letterCount ltrCnt {heap.top()};
        heap.pop();
        if (ltrCnt.count >= 2)
        {
            ltrCnt.count -= 2;
            remaining -= 2;
            if (ltrCnt.count > 0) heap.push(ltrCnt);
        }
        else if (ltrCnt.count < 2 && remaining > 1)
            return false;
        else
            return true;
    }
    return true;
}
