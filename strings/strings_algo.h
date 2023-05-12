//
// Created by daniel on 10/05/23.
//

#ifndef CRACKING_STRINGS_ALGO_H
#define CRACKING_STRINGS_ALGO_H

#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <stack>

bool hasUniqueChars(const std::string& string);

bool isPermutation(const std::string& string, const std::string& other);

void URLify(std::string& str, std::size_t length);

bool isPalindromePermutation(const std::string& str);

std::string compress(const std::string& str);

int stringToInt(const std::string& str);

std::string intToString(int number);

std::string convertBase(const std::string& number, int from, int to);

#endif //CRACKING_STRINGS_ALGO_H
