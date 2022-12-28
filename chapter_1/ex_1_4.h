//
// Created by daniel on 28/12/22.
//

#ifndef CRACKING_EX_1_4_H
#define CRACKING_EX_1_4_H

#include <array>
#include <queue>
#include <string>


struct letterCount
{
    char letter;
    int count;
};


bool operator== (const letterCount& c1, const letterCount& c2);
bool operator> (const letterCount& c1, const letterCount& c2);
bool operator< (const letterCount& c1, const letterCount& c2);

bool isPalindromePermutation(const std::string& str);

#endif //CRACKING_EX_1_4_H
