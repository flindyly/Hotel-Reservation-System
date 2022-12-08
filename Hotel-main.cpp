#include <iostream>
#include <string>
#include "Hotel.h"
#include "Room.h"
#include "Functions.h"

using namespace std;

int main(void){

    // create a new hotel with 3 single rooms, 2 double rooms and 2 grand rooms
    // note: must have more than 1 room for each room type

    int singles = 3, doubles = 2, grands = 2;

    Hotel* hotel1 = new Hotel(singles, doubles, grands);

    // check that number of vacant rooms is correct
    cout << endl << "CHECKING NUMBER OF VACANT ROOMS" << endl;
    cout << "Expected: 3 Actual: " << hotel1->getVacantSingles() << endl;
    cout << "Expected: 2 Actual: " << hotel1->getVacantDoubles() << endl;
    cout << "Expected: 2 Actual: " << hotel1->getVacantGrands() << endl;
    cout << endl;

    // get rooms
    singleRoom* s1 = hotel1->getSingles();
    doubleRoom* d1 = hotel1->getDoubles();
    grandRoom* g1 = hotel1->getGrands();

    // add rooms to hotel
    for (int s = 0; s < singles; s++) {
        hotel1->addSingleRooms(&s1[s], singles);
    }

    for (int d = 0; d < doubles; d++) {
        hotel1->addDoubleRooms(&d1[d], doubles);
    }

    for (int g = 0; g < grands; g++) {
        hotel1->addGrandRooms(&g1[g], grands);
    }

    // set single room numbers
    int singleRoomNo = 1;
    for (int s = 0; s < singles; s++) {
        s1[s].setRoomNumber(singleRoomNo);
        singleRoomNo++;
    }

    // set double room numbers
    int doubleRoomNo = 10;
    for (int d = 0; d < doubles; d++) {
        d1[d].setRoomNumber(doubleRoomNo);
        doubleRoomNo++;
    }

    // set grand room numbers
    int grandRoomNo = 20;
    for (int g = 0; g < grands; g++) {
        g1[g].setRoomNumber(grandRoomNo);
        grandRoomNo++;
    }

    //display room info
    roomInfo:

    string confirmInfo;
    hotel1->displayRoomInfo();
    getline(cin, confirmInfo);

    if (!validateYes(confirmInfo))      // validate 'y' input
    {
        goto roomInfo;
    }
    else
    {
        cout << "'y' Input verified." << endl << endl;
    }

    singleRoom:

    if(hotel1->hasVacantSingles(s1, singles))
    {
        // display number of available single rooms
        cout << "There are " << hotel1->getVacantSingles() << " available single rooms." << endl;

        // display vacant room numbers
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
                goto freeSingles;
            }
        }

        // validate selection - check for space, if input in range of room numbers given
        if (stringHasSpace(roomChoice) || stoi(roomChoice) < 1 || stoi(roomChoice) > singles)
        {
            cout << "*** ERROR: Invalid room number ***" << endl;
            goto freeSingles;
        }

        // set cost
        int cost = hotel1->singleBookingCost(stoi(roomChoice), s1, singles);

        // loop back to check if single rooms have been updated
        goto singleRoom;

    }
    else if (!hotel1->hasVacantSingles(s1, singles))
    {
        cout << "No rooms available." << endl;
        delete[] s1;    // NOTE: in main cpp, won't delete immediately as rooms need to be updated for next user
    }

    /*********** DOUBLE ROOM SELECTION ****************/
    doubleRoom:

    // check for vacant rooms
    if(hotel1->hasVacantDoubles(d1, doubles))
    {
        // display number of available single rooms
        cout << "There are " << hotel1->getVacantDoubles() << " available double rooms." << endl;

        // display vacant room numbers
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
        if (stringHasSpace(roomChoice) || stoi(roomChoice) < 10 || stoi(roomChoice) > (10 + doubles))
        {
            cout << "*** ERROR: Invalid room number ***" << endl;
            goto freeDoubles;
        }

        // set cost
        int cost = hotel1->doubleBookingCost(stoi(roomChoice), d1, doubles);

        // loop back to check if single rooms have been updated
        goto doubleRoom;

    }
    else if (!hotel1->hasVacantDoubles(d1, doubles))
    {
        cout << "No rooms available." << endl;
        delete[] d1;    // NOTE: in main cpp, won't delete immediately as rooms need to be updated for next user
    }

    /*********** GRAND ROOM SELECTION ****************/
    grandRoom:

    // check for vacant rooms
    if(hotel1->hasVacantGrands(g1, grands))
    {
        // display number of available single rooms
        cout << endl << "There are " << hotel1->getVacantGrands() << " available grand rooms." << endl;

        // display vacant room numbers
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
            cout << "*** ERROR: Invalid room number ***" << endl;
            goto freeGrands;
        }

        // set cost
        int cost = hotel1->grandBookingCost(stoi(roomChoice), g1, grands);

        // loop back to check if single rooms have been updated
        goto grandRoom;

    }
    else if (!hotel1->hasVacantGrands(g1, grands))
    {
        cout << "No rooms available." << endl;
        delete[] g1;    // NOTE: in main cpp, won't delete immediately as rooms need to be updated for next user
    }

    return 0;
}
