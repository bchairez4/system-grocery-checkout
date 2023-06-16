#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:
        std::string department_;
        std::string name_;
        float price_;
    public:
        Product() : department_("NULL"), name_("NULL"), price_(0.00f) {}

        Product(const std::string& department, const std::string& name, const float& price) : department_(department), name_(name), price_(price) {}

        Product(const Product& other) : department_(other.department_), name_(other.name_), price_(other.price_) {}

        ~Product() {}

        Product& operator=(const Product& other) {
            department_ = other.department_;
            name_ = other.name_;
            price_ = other.price_;
            return *this;
        }

        std::string getDepartment() const {
            return department_;
        }

        std::string getName() const {
            return name_;
        }

        float getPrice() const {
            return price_;
        }

        void setDepartment(const std::string& department) {
            department_ = department;
        }

        void setName(const std::string& name) {
            name_ = name;
        }

        void setPrice(const float& price) {
            price_ = price;
        }
};

#endif
