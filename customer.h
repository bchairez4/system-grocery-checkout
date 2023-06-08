#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "product.cpp"
#include "person.cpp"

class Customer : public Person {
    private:
        int phoneNumber_;
        int rewardPoints_;
        std::vector<Product> cart_;
    public:
        Customer();
        Customer(const std::string& firstName, const std::string& lastName, const int& phoneNumber, const int& rewardPoints);
        Customer(const Customer& other);
        ~Customer();
        Customer& operator=(const Customer& other);
        int getPhoneNumber() const;
        int getRewardPoints() const;
        void setPhoneNumber(const int& phoneNumber);
        void setRewardPoints(const int& rewardPoints);
        void setCart(const std::vector<Product>& cart);
        void addToCart(const Product& product);
        void removeFromCart(const Product& product);
};

#endif
