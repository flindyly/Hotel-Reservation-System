#include <iostream>
#include <string>
#include "Login.h"
#include "Functions.h"

using namespace std;

int main(){

    // create login portal
    Login guestLogin;

    //display menu
    startMenu:

    string choice;                      // use string to check for spaces
    guestLogin.displayMenu();
    getline(cin, choice);
    
    // if input has space, empty, or doesn't match menu options given, display menu again
    if (!matchMenuInput2(choice))
    {
        goto startMenu;
    }

    // register new user
    if (choice == "1")
    {
        guestLogin.alreadyRegistered(); // check is user is registered; else, register use
        goto startMenu; 
    }

    // validate login
    else if (choice == "2")
    {
        bool loginStatus = guestLogin.isLoggedIn();
        while (!loginStatus)    // keep alerting user until login is correct
        {       
            goto startMenu;
        }
    }




    return 0;
}
