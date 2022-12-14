# Hotel-Reservation-System
Completed on 21/10/2021

## Description

This project uses the terminal to simulate an online hotel reservation system for guests using object oriented programming concepts in C++. 

**Login system:** When a guest accesses the online system, he/she can choose to login as an existing customer or create a new account. When creating a new account, the system will store the user’s login details so that the user does not have to create a new account every time they access the program. 

**Room booking system:** Once authenticated, the guest has two options: search for rooms, or cancel a previous booking. If the guest chooses to search for a specific type of room to book, a list of available room numbers will be displayed. If no rooms are available, the system will alert the guest and the guest has an option to search again for another room type. The guest selects the room number they want to book, and a summary of the booking will be generated with the user’s information and a unique booking ID. 

**Payment system:** The guest will be directed to the payments portal where they can choose to pay by credit/debit card, PayPal or BPAY. Each payment method will have different methods of calculating the cost due to the surcharges. An invoice of their payment will be displayed, and the guest has an option to make another booking.

If the guest chooses to cancel a booking, the guest enters in their booking ID and the system alerts whether it was a successful cancellation, along with the refund value. That specific room will then be made vacant to other guests.

## Technologies and Concepts Utilised
C++, object-oriented programming principles, unit testing and integration testing

## How to Run
On the command line, enter `make project` to run the entire project.

