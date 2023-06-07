#ifndef CASHIER_H
#define CASHIER_H

#include "person.cpp"

class Cashier : public Person {
    private:
        int pin_;
    public:
        Cashier();
        Cashier(const int& pin, const std::string& firstName, const std::string& lastName);
        Cashier(const Cashier& other);
        ~Cashier();
        Cashier& operator=(const Cashier& other);
        int getPin() const;
        void setPin(const int& pin);
};

#endif
