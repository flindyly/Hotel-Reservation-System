#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login {

    // member variables
    private:
        std::string username;
        std::string password;

    // member functions
    public:
        Login();                        // default constructor
        bool isLoggedIn();              // returns true if login details match
        void alreadyRegistered();       // register user and check if user has already been registered
        void displayMenu();             // display login menu

        ~Login();                       // destructor

};

#endif
