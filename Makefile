# main file for project
project: main.cpp Login.o Functions.o Room.o Hotel.o Payment.o
	g++ -std=c++11 main.cpp Login.o Functions.o Room.o Hotel.o Payment.o -o project

# other functions not included in classes
Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp

FunctionsTest: Functions-main.cpp Functions.o
	g++ Functions-main.cpp Functions.o -o FunctionsTest

# Login unit tests
Login.o: Login.h Login.cpp
	g++ -c Login.cpp

LoginTest: Login-main.cpp Login.o
	g++ Login-main.cpp Login.o Functions.cpp -o LoginTest

# testing login menu inputs and outputs
testMenu: testMenu.cpp
	g++ testMenu.cpp -o testMenu

menuOutputs:
	bash testMenuOutputs


# room unit tests
Room.o: Room.h Room.cpp
	g++ -c Room.cpp

RoomTest: Room-main.cpp Room.o Functions.o
	g++ Room-main.cpp Room.o Functions.o -o RoomTest

# hotel unit tests
Hotel.o: Hotel.h Hotel.cpp
	g++ -c Hotel.cpp

HotelTest: Hotel-main.cpp Hotel.o Room.o Functions.o
	g++ Hotel-main.cpp Hotel.o Room.o Functions.o -o HotelTest


# payment unit tests
Payment.o: Payment.h Payment.cpp
	g++ -c Payment.cpp

PaymentTest: Payment.o Payment-main.cpp Functions.o
	g++ Payment.o Payment-main.cpp Functions.o -o PaymentTest


# all tests
tests: LoginTest RoomTest HotelTest PaymentTest
	./LoginTest
	./RoomTest
	./HotelTest
	./PaymentTest

# clean all .o files
clean:
	-rm *.o project LoginTest testMenu RoomTest HotelTest PaymentTest
