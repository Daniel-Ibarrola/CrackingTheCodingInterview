//
// Created by daniel on 16/02/23.
//

#ifndef CRACKING_SORTSTACK_H
#define CRACKING_SORTSTACK_H

#include <stack>

void sort(std::stack<int>& stack)
{
    std::stack<int> sorted;
    while (!stack.empty())
    {
        int temp {stack.top()};
        stack.pop();
        while (!sorted.empty() && sorted.top() > temp)
        {
            stack.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }

    while (!sorted.empty())
    {
        stack.push(sorted.top());
        sorted.pop();
    }
}


#endif //CRACKING_SORTSTACK_H
