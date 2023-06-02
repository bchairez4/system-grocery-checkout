#include "cashier.h"

Cashier::Cashier() : pin_(-1) {}

Cashier::Cashier(const int& pin, const std::string& firstName, const std::string& lastName) 
: Employee(firstName, lastName), pin_(pin) {}

Cashier::Cashier(const Cashier& other)
: Employee(other.getFirstName(), other.getLastName()), pin_(other.pin_) {}

Cashier::~Cashier() {}

Cashier& Cashier::operator=(const Cashier& other) {
    setFirstName(other.getFirstName());
    setLastName(other.getLastName());
    pin_  = other.pin_;
    return *this;
}

int Cashier::getPin() const {
    return pin_;
}

void Cashier::setPin(const int& pin) {
    pin_ = pin;
}
