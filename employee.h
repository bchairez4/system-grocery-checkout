#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <cstdlib>  //rand()

class Employee {
    private:
        int ID_;
        std::string firstName_;
        std::string lastName_;
    public:
        Employee();
        Employee(const std::string& firstName, const std::string& lastName);
        Employee(const Employee& other);
        ~Employee();
        Employee& operator=(const Employee& other);
        int getID() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        void setID(const int& ID);
        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
};

#endif
