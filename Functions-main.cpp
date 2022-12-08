#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main(void)
{
    // TEST 1 - checking for spaces in a string
    cout << endl << "TESTING stringHasSpace()" << endl << endl;
    // expected output: ERROR - space detected

    bool hasSpace;
    cout << "input: space" << endl;
    hasSpace = stringHasSpace(" ");
    cout << "input: random word" << endl;
    hasSpace = stringHasSpace(" ");

    // TEST 2 - Checking if user inputs 1 or 2 for menu
    cout << endl << "TESTING two menu options" << endl << endl;
    // expected output: invalid input. enter 1 or 2

    bool menuInput2;
    cout << "input: 4" << endl;
    menuInput2 = matchMenuInput2("4");
    cout << "input: 124954350459" << endl;
    menuInput2 = matchMenuInput2("124954350459");
    cout << "input: ogn 234" << endl;
    menuInput2 = matchMenuInput2("ogn 234");

    // TEST 3 - checking user inputs 'y' only for confirmation
    cout << endl << "TESTING 'y' input" << endl << endl;
    // expected output: invalid input. enter 1 or 2

    bool yes;
    cout << "input: y" << endl;
    yes = validateYes("y");         // expected: no output
    cout << "input: n" << endl;
    yes = validateYes("n");
    cout << "input: yes" << endl;
    yes = validateYes("yes");

    // TEST 4 - checking user enters 'y' or 'n' only
    cout << endl << "TESTING 'y' and 'n' input" << endl << endl;
    // expected output: invalid input. enter 1 or 2

    bool yesNo;
    cout << "input: y" << endl;
    yesNo = validateYesNo("y");           // expected: no output
    cout << "input: n" << endl;
    yesNo = validateYesNo("n");           // expected: no output
    cout << "input: rgner gjporg" << endl;
    yesNo = validateYesNo("rgner gjporg");
}
