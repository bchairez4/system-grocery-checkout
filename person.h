#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string firstName_;
        std::string lastName_;
    public:
        Person();
        Person(const std::string& firstName, const std::string& lastName);
        Person(const Person& other);
        ~Person();
        Person& operator=(const Person& other);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
};

#endif
