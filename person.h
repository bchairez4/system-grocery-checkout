#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string firstName_;
        std::string lastName_;
    public:
        Person() : firstName_("NULL"), lastName_("NULL") {}

        Person(const std::string& firstName, const std::string& lastName) : firstName_(firstName), lastName_(lastName) {}

        Person(const Person& other) : firstName_(other.firstName_), lastName_(other.lastName_) {}

        ~Person() {}

        Person& operator=(const Person& other) {
            firstName_ = other.firstName_;
            lastName_ = other.lastName_;
            return *this;
        }

        std::string getFirstName() const {
            return firstName_;
        }

        std::string getLastName() const {
            return lastName_;
        }

        std::string getFullName() const {
            return (firstName_ + " " + lastName_);
        }

        void setFirstName(const std::string& firstName) {
            firstName_ = firstName;
        }

        void setLastName(const std::string& lastName) {
            lastName_ = lastName;
        }
};

#endif
