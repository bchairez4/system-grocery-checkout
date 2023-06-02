#ifndef CASHIER_H
#define CASHIER_H

#include "employee.cpp"

class Cashier : public Employee {
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
