#include <iostream>
#include <fstream> // to read and write from/to files
#include <string>

#include "Login.h"
#include "Functions.h"

using namespace std;

// constructor
Login::Login()
{
    username = "no username";
    password = "no password";

}

// alerts user if username already exists; otherwise, create account for user
void Login::alreadyRegistered()
{
    string username, password;

    pickUN:
    cout << "Select a username: ";
    getline(cin, username);

    // check input of username
    if (stringHasSpace(username))
    {
        goto pickUN;
    }

    // add file
    ifstream ifile;
    ifile.open("logins/" + username + ".txt");

    // check if file with username already exists
    if(ifile)
    {
        cout << "Username already exists. Log in again or create a new account." << endl;
    }

    // if not, ask user to create a password
    else
    {
        pickPW:
        cout << "Create a password: ";
        getline(cin, password);

        // check input of password
        if (stringHasSpace(password))
        {
            goto pickPW;
        }

        // store username and password
        ofstream file("logins/" + username + ".txt"); // open file
        file << username << endl; // write to file
        file << password;
        file.close(); //close file
        cout << "Registration successful! Please log in." << endl;
    }

}

//verify if user has logged in successfully or not
bool Login::isLoggedIn()
{
    string username, password, accountUN, accountPW; // to compare between actual u/n and p/w

    // check username for spaces
    enterUN:

    cout << "Enter username: ";
    getline(cin, username);

    if (stringHasSpace(username))
    {
        goto enterUN;
    }

    // check password for spaces
    enterPW:

    cout << "Enter password: ";
    getline(cin, password);

    if (stringHasSpace(password))
    {
        goto enterPW;
    }

    // read file with chosen username
    ifstream read("logins/" + username + ".txt"); // read is the name of the stream
    getline(read, accountUN); // assign first line to account_un to compare
    getline(read, accountPW);

    // if username and password matches file, return true
    if (accountUN == username && accountPW == password)
    {
        cout << "Logged in successfully." << endl;
        return true;
    }

    // else, return false
    else
    {
        cout << "LOGIN FAILED. Incorrect username or password. Login again or register." << endl;
        return false;
    }
}

// display login menu
void Login::displayMenu()
{
    cout << "--------" << endl;
    cout << "  MENU  " << endl;
    cout << "--------" << endl;

    cout << "1: Register As A New Guest" << endl;
    cout << "2: Login As An Existing Guest" << endl;
    cout << "To exit, enter 'e'. " << endl;
    cout << "Your option (enter 1 or 2): ";
}

// destructor
Login::~Login()
{
    //cout << "Called destructor." << endl;
}
