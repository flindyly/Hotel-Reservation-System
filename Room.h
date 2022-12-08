#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

// abstract base class
class Room {

    protected:
        char roomType;          // single (s), double (d), grand (g)
        int roomNumber;         // single: 1-9 (ground), double: 10-19 (lvl 1), grand: 20-29 (lvl 2) - will be set by Hotel
        std::string status;     // room can be BOOKED or VACANT
        int totalRoomCost;      // total cost of room with/without extras
        std::string duration;

    public:

        Room();
        char getRoomType();                     // returns type of room - s, d, or g
        void setRoomNumber(int roomNo);         // sets room number
        int getRoomNumber();                    // returns room number
        void setStatus(std::string rmStatus);   // sets room status
        std::string getStatus();                // returns room status
        int getTotalCost();                     // returns total cost of rooms
        void setDuration();                     // sets duration of stay

        virtual void setTotalCost() = 0;        // calculates and sets total cost of room - pure virtual - abstract class
        virtual ~Room() = 0;                    // virtual destructor for abstract class
};

class singleRoom : public Room {

    private:
        int singleExtrasCost;       // cost of snack basket
        int singleRoomCost;         // cost of room (without extra)

    public:
        singleRoom();                   // constructor
        virtual void setTotalCost();    // sets total cost according to room cost and extras
        ~singleRoom();                  // destructor
};


class doubleRoom : public Room {

    private:
        int doubleExtrasCost;       // cost of an in-room cocktail station
        int doubleRoomCost;         // cost of a double room

    public:
        doubleRoom();                   // constructor
        virtual void setTotalCost();    // sets total cost according to double room cost and extras
        ~doubleRoom();                  // destructor
};

class grandRoom : public Room {

    private:
        int grandExtrasCost;        // cost of a family game pack
        int grandRoomCost;          // cost of a grand room

    public:
        grandRoom();                    // constructor
        virtual void setTotalCost();    // sets total cost according to cost of grand room and extras
        ~grandRoom();                   // destructor
};

#endif
