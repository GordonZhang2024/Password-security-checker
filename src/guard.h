#ifndef GUARD_H_
#define GUARD_H_

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>

#define minPasswdLen 6  // The lenth of the password should be at least 6

// Scores of different types of characters
#define scoreOfLetter 5
#define scoreOfUCaseLetter 7.5
#define scoreOfNumber 10
#define scoreOfSpecialChar 20

int getScore(std::string s);
std::string check(std::string s);

bool checkAvailability(std::string s);
bool checkSafety(std::string s);

#endif

