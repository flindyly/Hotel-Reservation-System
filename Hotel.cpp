#include <iostream>
#include <string>
#include "Hotel.h"
#include "Room.h"
#include "Functions.h"

using namespace std;

// constructor
Hotel::Hotel()
{
    singles = nullptr;
    doubles = nullptr;
    grands = nullptr;

    vacantSingles = 0;
    vacantDoubles = 0;
    vacantGrands = 0;

    numSingles = 0;
    numDoubles = 0;
    numGrands = 0;
}

// constructor with parameters
Hotel::Hotel(int singleCount, int doubleCount, int grandCount)
{
    numSingles = singleCount;
	numDoubles = doubleCount;
	numGrands = grandCount;

	singles = new singleRoom[singleCount];
	doubles = new doubleRoom[doubleCount];
	grands = new grandRoom[grandCount];

	vacantSingles = singleCount;
	vacantDoubles = doubleCount;
	vacantGrands = grandCount;
}

// display room info
void Hotel::displayRoomInfo()
{
	cout << endl;
    cout << "------------------------" << endl;
    cout << "Information about rooms" << endl;
    cout << "------------------------" << endl;

    cout << "SINGLE ROOM (s)" << endl;
    cout << "- for 1 person" << endl;
    cout << "- costs $50 a night" << endl;
    cout << "- can add a snack basket for additional $5" << endl;
    cout << endl;

    cout << "DOUBLE ROOM (d)" << endl;
    cout << "- for 2 people" << endl;
    cout << "- costs $100 a night" << endl;
    cout << "- can add an in-room cocktail station for additional $10" << endl;
    cout << endl;

    cout << "GRAND ROOM (g)" << endl;
    cout << "- for 3 to 4 people" << endl;
    cout << "- costs $150 a night" << endl;
    cout << "- can add a family game pack for additional $20" << endl;
    cout << endl;

    cout << "Enter y to continue: ";
}

// return array of single room objects
singleRoom* Hotel::getSingles()
{
    return singles;
}

// return array of double room objects
doubleRoom* Hotel::getDoubles()
{
    return doubles;
}

// return array of grand room objects
grandRoom* Hotel::getGrands()
{
    return grands;
}

// add single rooms
void Hotel::addSingleRooms(singleRoom* sRoom, int sRoomCount)
{
	sRoomCount = numSingles;

	for (int s=0; s<sRoomCount; s++)
	{
		singles[s] = *sRoom;
		sRoom->setStatus("VACANT");
	}
}

// add double rooms
void Hotel::addDoubleRooms(doubleRoom* dRoom, int dRoomCount)
{
	dRoomCount = numDoubles;

	for (int d=0; d<numDoubles; d++)
	{
		doubles[d] = *dRoom;
		dRoom->setStatus("VACANT");
	}
}

// add grand rooms
void Hotel::addGrandRooms(grandRoom* gRoom, int gRoomCount)
{
	gRoomCount = numGrands;

	for (int g=0; g<numDoubles; g++)
	{
		grands[g] = *gRoom;
		gRoom->setStatus("VACANT");
	}
}

// return true if single rooms are available
bool Hotel::hasVacantSingles(singleRoom* sRoom, int numSingles)
{

    for (int i = 0; i < numSingles; i++)
    {
        string status = sRoom[i].getStatus();
        if (status == "VACANT")
        {
            return true;
        }
    }

    return false;
}

// return true if double rooms are available
bool Hotel::hasVacantDoubles(doubleRoom* dRoom, int numDoubles)
{
    for (int d = 0; d < numDoubles; d++)
    {
        string status = dRoom[d].getStatus();
        if (status == "VACANT")
        {
            return true;
        }
    }

    return false;
}

// return true if grand rooms are available
bool Hotel::hasVacantGrands(grandRoom* gRoom, int numGrands)
{
    for (int g = 0; g < numGrands; g++)
    {
        string status = gRoom[g].getStatus();
        if (status == "VACANT")
        {
            return true;
        }
    }

    return false;
}

// display available single room numbers
void Hotel::displayVacantSingles(singleRoom* sRoom, int numSingles)
{

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "   Available Single Rooms  " << endl;
    cout << "---------------------------" << endl;
    cout << "Room numbers: ";

    for (int i = 0; i < numSingles; i++)
    {
        string status = sRoom[i].getStatus();
        int roomNum = sRoom[i].getRoomNumber();

        if (status == "VACANT")
        {
            cout << roomNum << " ";
        }
    }
    cout << endl << "Select a room number to book: ";
}

// display available double room numbers
void Hotel::displayVacantDoubles(doubleRoom* dRoom, int numDoubles)
{
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "   Available Double Rooms  " << endl;
    cout << "---------------------------" << endl;
    cout << "Room numbers: ";

    for (int d = 0; d < numDoubles; d++)
    {
        string status = dRoom[d].getStatus();
        int roomNum = dRoom[d].getRoomNumber();

        if (status == "VACANT")
        {
            cout << roomNum << " ";
        }
    }
    cout << endl << "Select a room number to book: ";
}

// display available grand room numbers
void Hotel::displayVacantGrands(grandRoom* gRoom, int numGrands)
{
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "   Available Grand Rooms  " << endl;
    cout << "---------------------------" << endl;
    cout << "Room numbers: ";

    for (int g = 0; g < numGrands; g++)
    {
        string status = gRoom[g].getStatus();
        int roomNum = gRoom[g].getRoomNumber();

        if (status == "VACANT")
        {
            cout << roomNum << " ";
        }
    }
    cout << endl << "Select a room number to book: ";
}

// return number of vacant single rooms
int Hotel::getVacantSingles()
{
    return vacantSingles;
}

// return number of vacant double rooms
int Hotel::getVacantDoubles()
{
    return vacantDoubles;
}

// return number of vacant grand rooms
int Hotel::getVacantGrands()
{
    return vacantGrands;
}

// book single room and return total room cost
int Hotel::singleBookingCost(int roomChoice, singleRoom* sRoom, int numSingles)
{
    int cost;

    // book room and set cost
    for (int s = 0; s < numSingles; s++)
    {
        int roomNum = sRoom[s].getRoomNumber();
        string roomStatus = sRoom[s].getStatus();

        if (roomStatus == "VACANT" && roomNum == roomChoice)
        {
            sRoom[s].setStatus("BOOKED");
            vacantSingles--;
            sRoom[s].setDuration();
            sRoom[s].setTotalCost();
            cout << "Total Room Cost: $" << sRoom[s].getTotalCost() << endl << endl;
            cost = sRoom[s].getTotalCost();
        }
    }

    return cost;
}

// book double room and return total room cost
int Hotel::doubleBookingCost(int roomChoice, doubleRoom* dRoom, int numDoubles)
{
    int cost;

    //book room and set cost
    for (int d = 0; d < numDoubles; d++)
    {
        int roomNum = dRoom[d].getRoomNumber();
        string roomStatus = dRoom[d].getStatus();

        if (roomStatus == "VACANT" && roomNum == roomChoice)
        {
            dRoom[d].setStatus("BOOKED");
            dRoom[d].setDuration();
            dRoom[d].setTotalCost();
            cout << "Total Room Cost: $" << dRoom[d].getTotalCost() << endl;
            cost = dRoom[d].getTotalCost();
        }
    }

    return cost;
}

// book grand room and return total room cost
int Hotel::grandBookingCost(int roomChoice, grandRoom* gRoom, int numGrands)
{
    int cost;

    // book room and set cost
    for (int g = 0; g < numGrands; g++)
    {
        int roomNum = gRoom[g].getRoomNumber();
        string roomStatus = gRoom[g].getStatus();

        if (roomStatus == "VACANT" && roomNum == roomChoice)
        {
            gRoom[g].setStatus("BOOKED");
            gRoom[g].setDuration();
            gRoom[g].setTotalCost();
            cout << "Total Room Cost: $" << gRoom[g].getTotalCost() << endl;
            cost = gRoom[g].getTotalCost();
        }
    }
    return cost;
}

// destructor
Hotel::~Hotel()
{
    cout << "Called Hotel destructor" << endl;
    delete[] singles;
    delete[] doubles;
    delete[] grands;
}
