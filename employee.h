#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    private:
        std::string firstName_;
        std::string lastName_;
    public:
        Employee();
        Employee(const std::string& firstName, const std::string& lastName);
        Employee(const Employee& other);
        ~Employee();
        Employee& operator=(const Employee& other);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
};

#endif
