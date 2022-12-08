#include <iostream>
#include <string>
#include "Payment.h"
#include "Functions.h"

using namespace std;

//constructor
Payment::Payment()
{
    payAmount = 0.00;
    cout << "Payment constructor called" << endl;
}

// display menu
void Payment::displayPaymentMenu()
{
    cout << endl;
    cout << "-------------------" << endl;
    cout << "   PAYMENT GATEWAY " << endl;
    cout << "-------------------" << endl;
    cout << "1. Credit/Debit card (no fee)" << endl;
    cout << "2. PayPal (2" << "%" << " fee)" << endl;
    cout << endl;
    cout << "Select a payment method (enter 1 or 2): ";
}

// set total amount to be paid
void Payment::setAmount(int roomCost)
{
    payAmount = roomCost;
}

// payment destructor
Payment::~Payment()
{
    cout << "Called Payment destructor. " << endl;
}

// card constructor
Card::Card()
{
    cardName = "no name";
    expirationMonth = "00";
    expirationYear = "00";
    cardNumber = "no number";
    cout << "Called Card constructor" << endl;
}

// set amount to be paid by card
void Card::setAmount(int roomCost)
{
    payAmount = roomCost;
    cout << "Amount to be paid: $" << payAmount << endl;
}

// validate card details
void Card::validateCardDetails()
{
    // card name
    cout << "Enter name of card holder: ";
    getline(cin, cardName);

    // expiration month
    expiryMonth:

    cout << "Enter the card expiry month (MM): ";
    getline(cin, expirationMonth);


    if (expirationMonth.length() > 2)
    {                 // check for two digits
        cout << "ERROR: Enter two digits." << endl;
        goto expiryMonth;
    }

    else if (stringHasSpace(expirationMonth))  // check for spaces and empty input
    {
        goto expiryMonth;
    }

    for (int i = 0; i < expirationMonth.length(); i++)  // check all digits
    {
        if (!isdigit(expirationMonth[i]))
        {
            cout << "ERROR: Enter digits only." << endl;
            goto expiryMonth;
        }
    }

    if (stoi(expirationMonth) < 0 || stoi(expirationMonth) > 12)    // check month is within valid range
    {
        cout << "Invalid month. Check your input and try again." << endl;
        goto expiryMonth;
    }

    // expiration year
    expiryYear:

    cout << "Enter the card expiry year (YY): ";
    getline(cin, expirationYear);


    if (expirationYear.length() > 2)        // check for two digits
    {
        cout << "ERROR: Enter two digits." << endl;
        goto expiryYear;
    }

    else if (stringHasSpace(expirationYear))    // check for spaces and empty input
    {
        goto expiryYear;
    }

    for (int i = 0; i < expirationYear.length(); i++)   // check all digits
    {
        if (!isdigit(expirationYear[i]))
        {
            cout << "ERROR: Enter digits only." << endl;
            goto expiryYear;
        }
    }

    if (stoi(expirationYear) < 0 || stoi(expirationYear) < 21)  // check year is within valid range
    {
        cout << "Invalid year. Check your input and try again." << endl;
        goto expiryYear;
    }

    // card number
    cardNum:

    cout << "Enter card number: ";
    getline(cin, cardNumber);

    if (stringHasSpace(cardNumber))     //check for spaces
    {
        goto cardNum;
    }

    //validate card number - 16 digits
    for (int cardIndex = 0; cardIndex < cardNumber.length(); cardIndex++)
    {
        if (isdigit(cardNumber[cardIndex]) == 0)
        {
            cout << "Card number must contain digits only. Try again." << endl;
            goto cardNum;
        }
        else if (cardNumber.length() != 16)
        {
            cout << "Not enough digits. Try again." << endl;
            goto cardNum;
        }
    }
    cout << "Payment successful." << endl;
}

Card::~Card()
{
    cout << "Called card destructor" << endl;
}

Paypal::Paypal()
{
    paypalSurcharge = 0.02;
    email = "no email";
    password = "no password";
    cout << "Called paypal constructor" << endl;
}

void Paypal::validatePaypalDetails()
{

    // validate email input
    emailInput:

    cout << "Enter your email: ";
    getline(cin, email);

    // check for empty inputs and spaces
    if (stringHasSpace(email))
    {
        goto emailInput;
    }

    // check if @ sign is included
    bool isEmail = false;
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            isEmail = true;
        }
    }

    if (!isEmail) {
        cout << "ERROR: Email not detected." << endl;
        goto emailInput;
    }

    // validate password - only check for spaces
    pwInput:

    cout << "Enter your password: ";
    getline(cin, password);

    if (stringHasSpace(password))
    {
        goto pwInput;
    }

    cout << "Login details verified. Please pay the specified amount." << endl;
}

void Paypal::setAmount(int roomCost)
{
    payAmount = roomCost + (paypalSurcharge * roomCost);
    cout << "Amount to be paid (incl. a 2 percent surcharge): $" << payAmount << endl;
}

Paypal::~Paypal()
{
    cout << "Called paypal destructor" << endl;
}
