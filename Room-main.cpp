#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

int main()
{
    // check constructor and destructor messages
    cout << "TEST 1 - Checking constructors and destructors" << endl << endl;
    Room* sRoom = new singleRoom();
    delete sRoom;
    cout << endl;

    Room* dRoom = new doubleRoom();
    delete dRoom;
    cout << endl;

    Room* gRoom = new grandRoom();
    delete gRoom;
    cout << endl;

    Room* s1 = new singleRoom();
    Room* d1 = new doubleRoom();
    Room* g1 = new grandRoom();

    cout << endl << "TEST 2 - Checking pure virtual setTotalCost()" << endl << endl;

    s1->setDuration();      // for testing, set duration to 1 night, with extra
    s1->setTotalCost();
    cout << "Expected cost: $55" << endl;
    cout << "total single room cost: $" << s1->getTotalCost() << endl << endl;

    d1->setDuration();      // for testing, set duration to 1 night, with extra
    d1->setTotalCost();
    cout << "Expected cost: $110" << endl;
    cout << "total single room cost: $" << d1->getTotalCost() << endl << endl;

    g1->setDuration();      // for testing, set duration to 1 night, with extra
    g1->setTotalCost();
    cout << "Expected cost: $170" << endl;
    cout << "total single room cost: $" << g1->getTotalCost() << endl << endl;

    // check single room functions
    cout << endl << "TEST 3 - Checking single room functions" << endl << endl;
    cout << "Expected room type: s" << endl;
    cout << "Room type: " << s1->getRoomType() << endl;

    s1->setRoomNumber(10);
    cout << "Expected room number: 10" << endl;
    cout << "Room number: " << s1->getRoomNumber() << endl;

    s1->setStatus("VACANT");
    cout << "Expected room status: VACANT" << endl;
    cout << "Room status: " << s1->getStatus() << endl;
    
    delete s1;

    // check double room functions
    cout << endl << "TEST 4 - Checking double room functions" << endl << endl;
    cout << "Expected room type: d" << endl;
    cout << "Room type: " << d1->getRoomType() << endl;

    d1->setRoomNumber(30);
    cout << "Expected room number: 30" << endl;
    cout << "Room number: " << d1->getRoomNumber() << endl;

    d1->setStatus("BOOKED");
    cout << "Expected room status: BOOKED" << endl;
    cout << "Room status: " << d1->getStatus() << endl;
    
    delete d1;

    // check grand room functions
    cout << endl << "TEST 5 - Checking grand room functions" << endl << endl;
    cout << "Expected room type: g" << endl;
    cout << "Room type: " << g1->getRoomType() << endl;

    g1->setRoomNumber(45);
    cout << "Expected room number: 45" << endl;
    cout << "Room number: " << g1->getRoomNumber() << endl;

    g1->setStatus("VACANT");
    cout << "Expected room status: VACANT" << endl;
    cout << "Room status: " << g1->getStatus() << endl << endl;
    
    delete g1;

    return 0;
}
