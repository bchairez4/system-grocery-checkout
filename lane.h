#ifndef LANE_H
#define LANE_H

#include "register.cpp"
#include <queue>

class Lane {
    private:
        bool signedIn_;
        Register reg_;
        std::queue<Product> cart_;
    public:
        Lane();
        Lane(const std::vector<Product>& cart);
        Lane(const Lane& other);
        ~Lane();
        Lane& operator=(const Lane& other);
        Cashier getCurrentCashier() const;
        Register getRegister() const;
        std::queue<Product> getCart() const;
        bool isSignedIn() const;
        bool isAssigned() const;
        void signIn(const int& pin);
        void signOut();
        void assignRegister(const Cashier& cashier);
        float closeRegister();
        void addProductsToLane(const std::vector<Product>& cart);
        void scanProducts();
        void removeProduct(const Product& product);
        void checkout(const float& tenderReceived);
};

#endif
