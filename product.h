#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:
        std::string department_;
        std::string name_;
        float price_;
    public:
        Product();
        Product(const std::string& department, const std::string& name, const float& price);
        Product(const Product& other);
        ~Product();
        Product& operator=(const Product& other);
        std::string getDepartment() const;
        std::string getName() const;
        float getPrice() const;
        void setDepartment(const std::string& department);
        void setName(const std::string& name);
        void setPrice(const float& price);
};

#endif
