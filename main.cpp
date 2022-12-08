#include <iostream>
#include <string>
#include <fstream> // to read and write from/to files

#include "Login.h"
#include "Functions.h"
#include "Hotel.h"
#include "Room.h"
#include "Payment.h"

using namespace std;

int main()
{
    /*********************** CREATE NEW HOTEL ****************************************/

    // note: must have more than 1 room for each room type
    int singles = 3, doubles = 2, grands = 2;

    Hotel* hotel1 = new Hotel(singles, doubles, grands);

    singleRoom* s1 = hotel1->getSingles();
    doubleRoom* d1 = hotel1->getDoubles();
    grandRoom* g1 = hotel1->getGrands();

    // add rooms to hotel
    for (int s = 0; s < singles; s++)
    {
        hotel1->addSingleRooms(&s1[s], singles);
    }

    for (int d = 0; d < doubles; d++) {
        hotel1->addDoubleRooms(&d1[d], doubles);
    }

    for (int g = 0; g < grands; g++)
    {
        hotel1->addGrandRooms(&g1[g], grands);
    }

    // set single room numbers
    int singleRoomNo = 1;
    for (int s = 0; s < singles; s++)
    {
        s1[s].setRoomNumber(singleRoomNo);
        singleRoomNo++;
    }

    // set double room numbers
    int doubleRoomNo = 10;
    for (int d = 0; d < doubles; d++)
    {
        d1[d].setRoomNumber(doubleRoomNo);
        doubleRoomNo++;
    }

    // set grand room numbers
    int grandRoomNo = 20;
    for (int g = 0; g < grands; g++)
    {
        g1[g].setRoomNumber(grandRoomNo);
        grandRoomNo++;
    }


    /********************** LOGIN PORTAL **************************/

    Login guestLogin;

    // display start menu interface
    startMenu:

    string choice;
    guestLogin.displayMenu();
    getline(cin, choice);

    // exit program
    if (choice == "e")
    {
        delete[] s1;        // delete 3 single room objects
        delete[] d1;        // delete 2 double room objects
        delete[] g1;        // delete 2 grand room objects
        return 0;
    }

    // validate menu input
    if (!matchMenuInput2(choice))
    {
        goto startMenu;
    }


    // register new user
    if (choice == "1")
    {
        guestLogin.alreadyRegistered();
        goto startMenu; // show menu again
    }

    // validate login
    else if (choice == "2")
    {
        bool loginStatus = guestLogin.isLoggedIn();
        while (!loginStatus)        // if login not verified, go back to menu
        {
            goto startMenu;
        }
    }

    /****************** ROOM BOOKING **************************/
    float totalCost;

    //display room info
    roomInfo:

    string confirmInfo;
    hotel1->displayRoomInfo();
    getline(cin, confirmInfo);

    if (!validateYes(confirmInfo))      // validate 'y' input
    {
        goto roomInfo;
    }

    // ask for what type of room user wants to book
    roomInput:

    string bookingOption;
    cout << "What room would you like to book? (s, d, or g) ";
    getline(cin, bookingOption);

    // validate user input
    if (bookingOption != "s" && bookingOption != "d" && bookingOption != "g")
    {
        cout << "*** ERROR: Invalid input. Try again. ***" << endl;
        goto roomInput;
    }
    else if (stringHasSpace(bookingOption))
    {
        goto roomInput;
    }

    /************* SINGLE ROOM BOOKING **************/

    if (bookingOption == "s")
    {
        // display vacant single room numbers and ask user to select
        if(hotel1->hasVacantSingles(s1, singles))
        {

            freeSingles:

            string roomChoice;
            hotel1->displayVacantSingles(s1, singles);
            getline(cin, roomChoice);

            // check if room choice has already been booked
            for (int i = 0; i<singles; i++)
            {
                if (s1[i].getRoomNumber() == stoi(roomChoice) && s1[i].getStatus() == "BOOKED")
                {
                    cout << "Room number not available. Try again." << endl;
                    goto freeDoubles;
                }
            }

            // validate selection - check for space, if input in range of room numbers given
            if (stringHasSpace(roomChoice) || stoi(roomChoice) < 1 || stoi(roomChoice) > singles)
            {
                cout << "*** ERROR: Invalid room number ***" << endl;
                goto freeSingles;
            }

            // set global variable cost to total room cost
            totalCost = hotel1->singleBookingCost(stoi(roomChoice), s1, singles);
        }

        // alert user if no rooms available
        else if (!hotel1->hasVacantSingles(s1, singles))
        {

            noSingles:

            string noSinglesConfirm;
            cout << "No single rooms available. Would you like to book another room? (y/n) ";
            getline(cin, noSinglesConfirm);

            // test input
            if (!validateYesNo)
            {
                goto noSingles;
            }

            // go to booking menu again
            if (noSinglesConfirm == "y")
            {
                goto roomInput;
            }

            // redirect to start menu
            else if (noSinglesConfirm == "n")
            {
                goto startMenu;
            }

        }
    }

    /************* DOUBLE ROOM BOOKING **************/

    else if (bookingOption == "d")
    {

        // check vacancy
        if(hotel1->hasVacantDoubles(d1, doubles))
        {
            // display vacant single room numbers and ask user to select
            freeDoubles:

            string roomChoice;
            hotel1->displayVacantDoubles(d1, doubles);
            getline(cin, roomChoice);

            // check if room choice has already been booked
            for (int i = 0; i<doubles; i++)
            {
                if (d1[i].getRoomNumber() == stoi(roomChoice) && d1[i].getStatus() == "BOOKED")
                {
                    cout << "Room number not available. Try again." << endl;
                    goto freeDoubles;
                }
            }

            // validate selection - check for space, if input in range of room numbers given
            if (stringHasSpace(roomChoice) || stoi(roomChoice) < 10 || stoi(roomChoice) > (doubles + 10)) {
                cout << "***ERROR: Invalid room number***" << endl;
                goto freeDoubles;
            }

            // set global variable cost to total room cost
            totalCost = hotel1->doubleBookingCost(stoi(roomChoice), d1, doubles);
        }

        // alert user if no rooms available
        else if (!hotel1->hasVacantDoubles(d1, doubles))
        {
            noDoubles:

            string noDoublesConfirm;
            cout << "No double rooms available. Would you like to book another room? (y/n) ";
            getline(cin, noDoublesConfirm);

            // test input
            if (!validateYesNo(noDoublesConfirm))
            {
                goto noDoubles;
            }

            // go to booking menu again
            if (noDoublesConfirm == "y"){
                goto roomInput;
            }

            // redirect to start menu
            else if (noDoublesConfirm == "n") {
                goto startMenu;
            }

        }

    }

    /************* GRAND ROOM BOOKING **************/

    else if (bookingOption == "g") {

        // check vacancy
        if(hotel1->hasVacantGrands(g1, grands))
        {
            // display vacant single room numbers and ask user to select
            freeGrands:

            string roomChoice;
            hotel1->displayVacantGrands(g1, grands);
            getline(cin, roomChoice);

            // check if room choice has already been booked
            for (int i = 0; i<grands; i++)
            {
                if (g1[i].getRoomNumber() == stoi(roomChoice) && g1[i].getStatus() == "BOOKED")
                {
                    cout << "Room number not available. Try again." << endl;
                    goto freeGrands;
                }
            }

            // validate selection - check for space, if input in range of room numbers given
            if (stringHasSpace(roomChoice) || stoi(roomChoice) < 20 || stoi(roomChoice) > (grands + 20))
            {
                cout << "***ERROR: Invalid room number***" << endl;
                goto freeGrands;
            }

            // set global variable cost to total room cost
            totalCost = hotel1->grandBookingCost(stoi(roomChoice), g1, grands);

        }

        // alert user if no rooms available
        else if (!hotel1->hasVacantGrands(g1, grands)) {

            noGrands:

            string noGrandsConfirm;
            cout << "No grand rooms available. Would you like to book another room? (y/n) ";
            getline(cin, noGrandsConfirm);

            // test input
            if (!validateYesNo(noGrandsConfirm))
            {
                goto noDoubles;
            }

            // go to booking menu again
            if (noGrandsConfirm == "y"){
                goto roomInput;
            }

            // redirect to start menu
            else if (noGrandsConfirm == "n") {
                goto startMenu;
            }
        }
    }

    /********** PAYMENT PORTAL ****************/
    Payment* payPortal;

    paymentInput:

    string payChoice;
    payPortal->displayPaymentMenu();
    getline(cin, payChoice);

    if (!matchMenuInput2) {
        goto paymentInput;
    }

    // pay by card
    if (payChoice == "1")
    {
        Card* payCard = new Card();

        // set payment cost to total room cost
        payCard->setAmount(totalCost);

        // validate details
        payCard->validateCardDetails();

        delete payCard;
    }

    // pay by paypal
    else if (payChoice == "2")
    {
        Paypal* pay = new Paypal();

        // set total payment cost (including surcharge)
        pay->setAmount(totalCost);

        // validate paypal login details
        pay->validatePaypalDetails();
        delete pay;
    }

    // redirect to start menu
    logOff:

    string confirmEnd;
    cout << "Enter y to log off: ";
    getline(cin, confirmEnd);

    if (!validateYes(confirmEnd))      // validate 'y' input
    {
        goto logOff;
    }

    if(confirmEnd == "y")
    {
        goto startMenu;
    }

    return 0;
}
