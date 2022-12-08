#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

bool stringHasSpace(std::string str);           // returns true if a string has spaces or is empty
bool matchMenuInput2(std::string choice);       // validates user's menu input for menu with 2 choices only
bool validateYes(std::string y);                // returns false if string does not equal 'y' or has spaces
bool validateYesNo(std::string option);         // returns false if string does not equal 'y' and 'n' or has spaces


#endif
