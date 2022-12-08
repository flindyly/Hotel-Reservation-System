#include <iostream>
#include <string>

using namespace std;

// checks if inputs with spaces, special characters, empty inputs, etc. are rejected for a menu with 2 options
// function combined in Functions.h called matchMenuInput2()

int main(){

    // ask for choice
    string choice;
    cout << "Enter your option (1 or 2): ";
    getline(cin, choice);

    // checks if choice isn't a 1 or 2
    if ( (choice != "1" && choice != "2") || choice.empty()){
        cout << "INVALID INPUT. Enter a 1 or 2." << endl;
        cout << endl;
        return 0;
    }

    // checks if choice contains any spaces
    else {
        for (int i = 0; i < choice.length(); i++) {
            if (isspace(choice[i])) {
                cout << "INVALID INPUT. Enter a 1 or 2." << endl;
                cout << endl;
                return 0;
            }
        }
    }

    cout << "Successful." << endl;

}
