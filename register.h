#ifndef REGISTER_H
#define REGISTER_H

#include "cashier.cpp"
#include "receipt.cpp"

class Register {
    private:
        Cashier cashier_;
        std::vector<Product> productList_;
        std::vector<Receipt> receipts_;
        float balanceDue_;
        float tenderReceived_;
        float changeDue_;
        float depositBalance_;
    public:
        Register();
        Register(const float& balance);
        Register(const Register& other);
        ~Register();
        Register& operator=(const Register& other);
        Cashier getCashier() const;
        std::vector<Product> getProductList() const;
        std::vector<Receipt> getReceipts() const;
        float getBalanceDue() const;
        float getChangeDue() const;
        int getDepositBalance() const;
        float getProductPrice(const Product& product) const;
        void setCashier(const Cashier& cashier);
        void addProduct(const Product& product);
        void removeProduct(const Product& product);
        void checkout(const float& tenderReceived);
        void printReceipt();
        float close();
};

#endif
