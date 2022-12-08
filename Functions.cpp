#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

// return true if string has spaces
bool stringHasSpace(string str) {

    // empty input (enter key pressed without input)
    if (str.empty())
    {
        return true;
    }

    // whitespaces
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
        {
            cout << "*** ERROR: Invalid input. Space(s) detected. ***" << endl;
            return true;
        }
    }
    return false;
}

// validates inputs from menu with 2 choices
bool matchMenuInput2(string choice){

    if (choice != "1" && choice != "2")
    {
        cout << "INVALID INPUT. Enter a 1 or 2." << endl;
        return false;
    }

    else if (stringHasSpace(choice))
    {
        return false;
    }
    return true;
}

// returns false if string != "y"
bool validateYes(string y)
{
    if (y != "y" || stringHasSpace(y))
    {
        cout << "INVALID INPUT. Enter y (without spaces)." << endl;
        return false;
    }
    return true;
}

// returns false if string != "y" and "n"
bool validateYesNo(string option)
{
    if ( (option != "y" && option != "n") || stringHasSpace(option))
    {
        cout << "INVALID INPUT. Enter y or n (without spaces)." << endl;
        return false;
    }
    return true;
}

/*bool matchRoomType(string type){

    if (type != "s" && type != "d" && type != "g"){

        cout << "\nINVALID INPUT. Enter s, d, or g without spaces." << endl;
        cout << endl;

        return false;
    }
    else if (stringHasSpace(type)) {
        return false;
    }

    return true;

}*/
