#ifndef REGISTER_H
#define REGISTER_H

#include "cashier.h"
#include "receipt.h"
#include <fstream>

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
        Register(): balanceDue_(0.00f), tenderReceived_(0.00f), changeDue_(0.00f), depositBalance_(0.00f) {}

        Register(const float& depositBalance) : balanceDue_(0.00f), tenderReceived_(0.00f), changeDue_(0.00f), depositBalance_(depositBalance) {}

        Register(const Register& other) 
        : cashier_(other.cashier_), balanceDue_(other.balanceDue_), tenderReceived_(other.tenderReceived_), changeDue_(other.changeDue_), depositBalance_(other.depositBalance_) {
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }

            receipts_.clear();
            for (int i = 0; i < other.receipts_.size(); ++i) {
                receipts_.push_back(other.receipts_[i]);
            }
        }

        ~Register() {}

        Register& operator=(const Register& other) {
            cashier_ = other.cashier_;
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }
            receipts_.clear();
            for (int i = 0; i < other.receipts_.size(); ++i) {
                receipts_.push_back(other.receipts_[i]);
            }
            balanceDue_ = other.balanceDue_;
            tenderReceived_ = other.tenderReceived_;
            changeDue_ = other.changeDue_;
            depositBalance_ = other.depositBalance_;
            return *this;
        }

        Cashier getCashier() const {
            return cashier_;
        }

        std::vector<Product> getProductList() const {
            return productList_;
        }

        std::vector<Receipt> getReceipts() const {
            return receipts_;
        }

        float getBalanceDue() const {
            return balanceDue_;
        }

        float getChangeDue() const {
            return changeDue_;
        }

        int getDepositBalance() const {
            return depositBalance_;
        }

        float getProductPrice(const Product& product) const {
            return product.getPrice();
        }

        void setCashier(const Cashier& cashier) {
            cashier_ = cashier;
        }

        void addProduct(const Product& product) {
            productList_.push_back(product);
            balanceDue_ += product.getPrice();
        }

        // erases first found instance of given product
        void removeProduct(const Product& product) {
            for (std::vector<Product>::iterator it = productList_.begin(); it != productList_.end(); ++it) {
                if (it->getName() == product.getName()) {
                    productList_.erase(it);
                    balanceDue_ -= product.getPrice();
                    return;
                }
            }
        }

        float checkout(const float& tenderReceived) {
            tenderReceived_  = tenderReceived;
            changeDue_ = tenderReceived_ - balanceDue_; 
            depositBalance_ += balanceDue_;

            return balanceDue_;
        }

        void generateReceipt() {
            std::string receipt = "receipt" + std::to_string(receipts_.size()+1) + ".txt";

            std::ofstream file(receipt, std::ofstream::out);

            if (!file) {
                return;
            }

            file << "Cherries Grocery Store" << '\n';
            file << "Where Good Quality Matters." << '\n';
            file << '\n';

            file << "Cashier: " << cashier_.getFirstName() << " " << cashier_.getLastName().at(0) << "." << '\n';
            file << '\n';

            for (int i = 0; i < productList_.size(); ++i) {
                file << productList_[i].getName() << " " << productList_[i].getPrice() << '\n';
            }

            file << '\n';

            file << "Balance Due: $" << balanceDue_ << '\n';
            file << "Tender Received: $" <<  tenderReceived_ << '\n';
            file << "Change: $" << changeDue_ << '\n';
            file << '\n';

            file << "Thank you for shopping with us!" << '\n';
        }

        void printReceipt() {
            Receipt receipt(productList_, balanceDue_, tenderReceived_, changeDue_);

            //save receipt to history of receipts
            generateReceipt();
            std::cout << "Your receipt has been printed. See you again soon" << '\n';
            receipts_.push_back(receipt);

            //reset variables for next transaction
            balanceDue_ = 0.00f;
            tenderReceived_ = 0.00f;
            changeDue_ = 0.00f;
            productList_.clear();
        }

        // Closing the register has to take out money made
        float close() {
            Cashier null_cashier;
            cashier_ = null_cashier;
            
            return depositBalance_;
        }
};

#endif
