#ifndef LANE_H
#define LANE_H

#include "register.cpp"
#include <queue>

// A lane consists of a cashier, a cash register, and the items from a customers cart

class Lane {
    private:
        Register reg_;
        std::queue<Product> cart_;
    public:
        Lane();
        Lane(const Lane& other);
        ~Lane();
        Lane& operator=(const Lane& other);
        Cashier getCurrentCashier() const;
        Register getRegister() const;
        std::queue<Product> getCart() const;
        void assignRegister(const Cashier& cashier);
        float closeRegister();
        void scanProducts();
        void removeProduct(const Product& product);
        void checkout(const float& tender_given);
};

#endif
