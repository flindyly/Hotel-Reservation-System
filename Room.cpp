#include <iostream>
#include <string>
#include "Room.h"
#include "Functions.h"

using namespace std;

// constructor
Room::Room()
{
    roomType = '-';
    roomNumber = 0;
    status = "VACANT";
    totalRoomCost = 0;
    duration = "0";

    cout << "Room constructor called" << endl;
}

// return room type
char Room::getRoomType()
{
    return roomType;
}

// set room number
void Room::setRoomNumber(int roomNo)
{
    roomNumber = roomNo;
}

// return room number
int Room::getRoomNumber()
{
    return roomNumber;
}

// set room status
void Room::setStatus(std::string rmStatus)
{
    status = rmStatus;
}

// return room status
string Room::getStatus()
{
    return status;
}

// return total cost of room, including extras
int Room::getTotalCost()
{
    return totalRoomCost;
}

// set number of nights guest will be staying at hotel
void Room::setDuration()
{
    durationFlag:

    cout << "How many nights will you be staying? (Maximum is 7 nights) ";
    getline(cin, duration);

    // check if duration input has spaces, or is empty
    if (stringHasSpace(duration))
    {
        goto durationFlag;
    }

    else if (duration.length() > 1)
    {
        cout << "*** ERROR: Invalid input. Try again. ***" << endl;
        goto durationFlag;
    }

    // duration cannot be more than 7 nights
    if (stoi(duration) > 7)
    {
        cout << "Duration exceeds limit of 7 nights. Enter again." << endl;
        goto durationFlag;
    }
}

// room destructor
Room::~Room()
{
    cout << "Room destructor called" << endl;
}

// single room constructor
singleRoom::singleRoom()
{
    roomType = 's';
    roomNumber = 0;
    status = "VACANT";
    totalRoomCost = 0;

    singleExtrasCost = 5;
    singleRoomCost = 50;    // per night'
    cout << "Single constructor called" << endl;
}

// set single room cost
void singleRoom::setTotalCost()
{
    singleExtra:       // flag

    string wantExtra;

    // ask user if they want to get extra
    cout << "Would you like to add a snack basket for an additional price of $" << singleExtrasCost << " ?" << endl;
    cout << "(y/n) ";
    getline(cin, wantExtra);

    // validate user input
    if (!validateYesNo(wantExtra))
    {
        goto singleExtra;
    }

    // calculate total cost of room with/without extras
    if (wantExtra == "y")
    {
        totalRoomCost = singleExtrasCost + (singleRoomCost * stoi(duration));
    }
    else
    {
        totalRoomCost = singleRoomCost*(stoi(duration));
    }
}

// single room destructor
singleRoom::~singleRoom()
{
    cout << "Called single destructor" << endl;
}

// double room constructor
doubleRoom::doubleRoom()
{
    roomType = 'd';
    roomNumber = 0;
    status = "VACANT";
    totalRoomCost = 0;

    doubleExtrasCost = 10;
    doubleRoomCost = 100;    // per night
    cout << "Double constructor called" << endl;
}

// set double room cost
void doubleRoom::setTotalCost()
{
    doubleExtra:

    string wantExtra;

    cout << "Would you like to add an in-room cocktail station for an additional price of $" << doubleExtrasCost << " ?" << endl;
    cout << "(y/n) ";
    getline(cin, wantExtra);

    if (!validateYesNo(wantExtra))
    {
        goto doubleExtra;
    }

    if (wantExtra == "y")
    {
        totalRoomCost = doubleExtrasCost + (doubleRoomCost * stoi(duration));
    }
    else
    {
        totalRoomCost = doubleRoomCost * stoi(duration);
    }
}

// double room destructor
doubleRoom::~doubleRoom()
{
    cout << "Called double destructor" << endl;
}

// grand room constructor
grandRoom::grandRoom()
{
    roomType = 'g';
    roomNumber = 0;
    status = "VACANT";
    totalRoomCost = 0;

    grandExtrasCost = 20;
    grandRoomCost = 150;    // per night
    cout << "Grand contructor called" << endl;
}

// set grand room cost
void grandRoom::setTotalCost()
{
    grandExtra:

    string wantExtra;

    cout << "Would you like to add a family game pack for an additional price of $" << grandExtrasCost << " ?" << endl;
    cout << "(y/n) ";
    getline(cin, wantExtra);

    if (!validateYesNo(wantExtra))
    {
        goto grandExtra;
    }

    if (wantExtra == "y")
    {
        totalRoomCost = grandExtrasCost + (grandRoomCost * stoi(duration));
    }
    else
    {
        totalRoomCost = grandRoomCost * stoi(duration);
    }
}

// grand room destructor
grandRoom::~grandRoom()
{
    cout << "Called grand destructor" << endl;
}
