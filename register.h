#ifndef REGISTER_H
#define REGISTER_H

#include "cashier.cpp"
#include "receipt.cpp"

class Register {
    private:
        Cashier cashier_;
        std::vector<Product> productList_;
        Receipt receipt_;
        float balance_due_;
        float tender_received_;
        float change_due_;
        float deposit_balance_;
    public:
        Register();
        Register(const float& balance);
        Register(const Register& other);
        ~Register();
        Register& operator=(const Register& other);
        int getDepositBalance() const;
        float getProductPrice(const Product& product);
        void addProduct(const Product& product);
        void removeProduct(const Product& product);
        void checkout(const float& tender_received);
        void printReceipt();
        float close();
};

#endif
