#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include "Room.h"

class Hotel {

    private:
        singleRoom* singles;
        doubleRoom* doubles;
        grandRoom* grands;

        int vacantSingles;
        int vacantDoubles;
        int vacantGrands;

        int numSingles;
        int numDoubles;
        int numGrands;

    public:

        Hotel();                                                    // default constructor
        Hotel(int singleCount, int doubleCount, int grandCount);    // constructor with room parameters
        void displayRoomInfo();                                     // display room info

        singleRoom* getSingles();                                   // returns array of single room objects
        doubleRoom* getDoubles();                                   // returns array of double room objects
        grandRoom* getGrands();                                     // returns array of grand room objects

        void addSingleRooms(singleRoom* sRoom, int sRoomCount);     // add rooms
        void addDoubleRooms(doubleRoom* dRoom, int dRoomCount);
        void addGrandRooms(grandRoom* gRoom, int gRoomCount);

        bool hasVacantSingles(singleRoom* sRoom, int numSingles);   // check if there are free rooms
        bool hasVacantDoubles(doubleRoom* dRoom, int numDoubles);
        bool hasVacantGrands(grandRoom* gRoom, int numGrands);


        void displayVacantSingles(singleRoom* sRoom, int numSingles);   // display free room numbers
        void displayVacantDoubles(doubleRoom* dRoom, int numDoubles);
        void displayVacantGrands(grandRoom* gRoom, int numGrands);

        int getVacantSingles();                                     // get number of vacant rooms
        int getVacantDoubles();
        int getVacantGrands();

        int singleBookingCost(int roomChoice, singleRoom* sRoom, int numSingles);   // return total room cost
        int doubleBookingCost(int roomChoice, doubleRoom* dRoom, int numDoubles);
        int grandBookingCost(int roomChoice, grandRoom* gRoom, int numGrands);

        ~Hotel();
};

#endif
