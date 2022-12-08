#include <iostream>
#include <string>
#include "Payment.h"
#include "Functions.h"

using namespace std;

int main(void)
{
    // check constructor, destructor
    cout << "TEST 1 - Checking constructor and destructor of classes with polymorphism" << endl;
    cout << "Should call both the constructor and destructor of base and derived classes" << endl << endl;

    cout << " - creating new card payment method - " << endl << endl;
    Card* c1 = new Card();
    delete c1;

    cout << endl << " - creating new paypal payment method - " << endl << endl;
    Paypal* p1 = new Paypal();
    delete p1;

    // check polymorphism
    cout << endl << "TEST 2 - Checking virtual setAmount()" << endl << endl;
    Payment* p2 = new Paypal();
    cout << "Paypal: room cost = $10, surcharge = 0.02" << endl;
    cout << "Expected cost: $10.2" << endl;
    p2->setAmount(10);
    delete p2;

    // check menu
    cout << "TEST 3 - Check menu display" << endl << endl;

    Payment* p3 = new Payment();
    string payOption;
    p3->displayPaymentMenu();
    getline(cin, payOption);

    delete p3;

    // validate card
    cout << endl << "TEST 4 - Check validation of card" << endl << endl;

    Card* card = new Card();    // can only access function through derived class pointer as function not in base
    card->validateCardDetails();
    delete card;

    // validate paypal details
    cout << endl << "TEST 5 - Check validation of paypal" << endl << endl;

    Paypal* pay = new Paypal();
    pay->validatePaypalDetails();
    delete pay;

    return 0;
}
