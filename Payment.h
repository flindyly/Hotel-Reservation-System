#ifndef PAYMENT_H
#define PAYMENT_H

// payment base class
class Payment
{
    protected:
        float payAmount;

    public:
        Payment();                              // default constructor
        void displayPaymentMenu();              // display payment menu
        virtual void setAmount(int roomCost);   // set payment amount to the total room cost - polymorphism
        virtual ~Payment();                     // virtual destructor
};

// payment by card
class Card : public Payment
{
    private:
        std::string cardName;
        std::string expirationMonth;
        std::string expirationYear;
        std::string cardNumber;

    public:
        Card();                                 // default constructor
        virtual void setAmount(int roomCost);   // sets pay amount to the total room cost
        void validateCardDetails();             // validate card number, expiration date
        ~Card();                                // destructor
};

// payment by Paypal
class Paypal : public Payment
{
    private:
        float paypalSurcharge;
        std::string email;
        std::string password;

    public:
        Paypal();                               // constructor
        void validatePaypalDetails();           // check email and password
        virtual void setAmount(int roomCost);   // sets payment amount to total room cost including surcharge
        ~Paypal();                              // destructor
};

#endif
