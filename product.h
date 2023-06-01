#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:
        int ID_;
        std::string name_;
        float price_;
    public:
        Product();
        Product(const int& ID, const std::string& name, const float& price);
        Product(const Product& other);
        ~Product();
        Product& operator=(const Product& other);
        int getID() const;
        std::string getName() const;
        float getPrice() const;
        void setID(const int& ID);
        void setName(const std::string& name);
        void setPrice(const float& price);
};

#endif
