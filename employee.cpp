#include "employee.h"

Employee::Employee() : firstName_("NULL"), lastName_("NULL") {}

Employee::Employee(const std::string& firstName, const std::string& lastName) : firstName_(firstName), lastName_(lastName) {}

Employee::Employee(const Employee& other) : firstName_(other.firstName_), lastName_(other.lastName_) {}

Employee::~Employee() {}

Employee& Employee::operator=(const Employee& other) {
    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
    return *this;
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

void Employee::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Employee::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}
