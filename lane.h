#ifndef LANE_H
#define LANE_H

#include "register.h"
#include <queue>

class Lane {
    private:
        bool signedIn_;
        Register reg_;
        std::queue<Product> cart_;
    public:
        Lane() : signedIn_(false) {}

        Lane(const std::vector<Product>& cart) {
            for (int i = 0; i < cart.size(); ++i) {
                cart_.push(cart[i]);
            }
        }

        Lane(const Lane& other) : signedIn_(other.signedIn_), reg_(other.reg_), cart_(other.cart_) {}

        ~Lane() {}

        Lane& operator=(const Lane& other) {
            signedIn_ = other.signedIn_;
            reg_ = other.reg_;
            cart_ = other.cart_;
            return *this;
        }

        Cashier getCurrentCashier() const {
            return reg_.getCashier();
        }

        Register getRegister() const {
            return reg_;
        }

        std::queue<Product> getCart() const {
            return cart_;
        }

        bool isSignedIn() const {
            return signedIn_;
        }

        bool isAssigned() const {
            return reg_.getCashier().getFirstName() != "NULL";
        }

        void signIn(const int& pin) {
            if (isAssigned()) {
                return;
            }

            if (reg_.getCashier().getPin() == pin) {
                signedIn_ = true;
            }
        }

        void signOut() {
            if (isAssigned()) {
                signedIn_ = false;
            }
        }

        void assignRegister(const Cashier& cashier) {
            reg_.setCashier(cashier);
        }

        float closeRegister() {
            if (!isAssigned()) {
                std::cout << "Error. Register is not assigned to a cashier." << '\n';
                return 0.00f;
            }

            float deposit = reg_.close();

            return deposit;
        }

        void addProductsToLane(const std::vector<Product>& cart) {
            for (std::vector<Product>::const_iterator it = cart.cbegin(); it != cart.cend(); ++it) {
                cart_.push(*it);
            }
        }

        void scanProducts() {
            while (!cart_.empty()) {
                reg_.addProduct(cart_.front());
                cart_.pop();
            }
        }

        void removeProduct(const Product& product) {
            reg_.removeProduct(product);
        }

        float checkout(const float& tenderReceived, const float& discount, const bool& isDiscounted) {
            float income = reg_.checkout(tenderReceived, discount);
            reg_.printReceipt(isDiscounted);
            return income;
        }
};

#endif
