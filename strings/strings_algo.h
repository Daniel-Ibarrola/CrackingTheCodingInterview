//
// Created by daniel on 10/05/23.
//

#ifndef CRACKING_STRINGS_ALGO_H
#define CRACKING_STRINGS_ALGO_H

#include <array>
#include <string>
#include <stack>

bool hasUniqueChars(const std::string& string);

bool isPermutation(const std::string& string, const std::string& other);

void URLify(std::string& str, std::size_t length);

bool isPalindromePermutation(const std::string& str);

std::string compress(const std::string& str);

#endif //CRACKING_STRINGS_ALGO_H
