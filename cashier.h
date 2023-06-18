#ifndef CASHIER_H
#define CASHIER_H

#include "person.h"

class Cashier : public Person {
    private:
        int pin_;
    public:
        Cashier() : pin_(-1) {}

        Cashier(const int& pin, const std::string& firstName, const std::string& lastName) 
        : Person(firstName, lastName), pin_(pin) {}

        Cashier(const Cashier& other)
        : Person(other.getFirstName(), other.getLastName()), pin_(other.pin_) {}

        ~Cashier() {}

        Cashier& operator=(const Cashier& other) {
            if (!other.getFirstName().empty()) {
                setFirstName(other.getFirstName());
            }
            if (!other.getLastName().empty()) {
                setLastName(other.getLastName());
            }
            pin_  = other.pin_;
            return *this;
        }

        int getPin() const {
            return pin_;
        }

        void setPin(const int& pin) {
            pin_ = pin;
        }
};

#endif
