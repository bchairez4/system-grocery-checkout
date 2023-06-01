#include "employee.h"

Employee::Employee() : ID_(-1), firstName_("NULL"), lastName_("NULL") {}

Employee::Employee(const std::string& firstName, const std::string& lastName) : firstName_(firstName), lastName_(lastName) {
    //ID is a random 6 digit number 
    std::srand((unsigned) time(NULL));

    ID_ = 1 + (std::rand() % 1000000);
}

Employee::Employee(const Employee& other) : ID_(other.ID_), firstName_(other.firstName_), lastName_(other.lastName_) {}

Employee::~Employee() {}

Employee& Employee::operator=(const Employee& other) {
    ID_ = other.ID_;
    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
}

int Employee::getID() const {
    return ID_;
}

std::string Employee::getFirstName() const {
    return firstName_;
}

std::string Employee::getLastName() const {
    return lastName_;
}

std::string Employee::getFullName() const {
    return (firstName_ + " " + lastName_);
}

void Employee::setID(const int& ID) {
    ID_ = ID;
}

void Employee::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Employee::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}
