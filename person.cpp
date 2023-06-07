#include "person.h"

Person::Person() : firstName_("NULL"), lastName_("NULL") {}

Person::Person(const std::string& firstName, const std::string& lastName) : firstName_(firstName), lastName_(lastName) {}

Person::Person(const Person& other) : firstName_(other.firstName_), lastName_(other.lastName_) {}

Person::~Person() {}

Person& Person::operator=(const Person& other) {
    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
    return *this;
}

std::string Person::getFirstName() const {
    return firstName_;
}

std::string Person::getLastName() const {
    return lastName_;
}

std::string Person::getFullName() const {
    return (firstName_ + " " + lastName_);
}

void Person::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Person::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}
