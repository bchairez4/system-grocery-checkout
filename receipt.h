#ifndef RECEIPT_H
#define RECEIPT_H

#include "product.h"
#include <iostream>
#include <vector>

class Receipt {
    private:
        std::vector<Product> productList_;
        float balanceDue_;
        float tenderReceived_;
        float changeDue_;
    public:
        Receipt() : balanceDue_(0.00f), tenderReceived_(0.00f), changeDue_(0.00f) {}

        Receipt(const std::vector<Product>& productList, float balanceDue, float tenderReceived, float changeDue)
        : balanceDue_(balanceDue), tenderReceived_(tenderReceived), changeDue_(changeDue) {
            for (int i = 0; i < productList.size(); ++i) {
                productList_.push_back(productList[i]);
            }
        }

        Receipt(const Receipt& other) 
        : balanceDue_(other.balanceDue_), tenderReceived_(other.tenderReceived_), changeDue_(other.changeDue_) {
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }
        }

        ~Receipt() {}

        Receipt& operator=(const Receipt& other) {
            balanceDue_ = other.balanceDue_;
            tenderReceived_ = other.tenderReceived_;
            changeDue_ = other.changeDue_;
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }
            return *this;
        }

        float getBalanceDue() const {
            return balanceDue_;
        }

        float getTenderReceived() const {
            return tenderReceived_;
        }

        float getChangeDue() const {
            return changeDue_;
        }

        void print(const bool& discount) {
            std::cout << "Cherries Grocery Store" << '\n';
            std::cout << "Where Good Quality Matters." << '\n';
            std::cout << '\n';

            for (std::vector<Product>::const_iterator it = productList_.begin(); it != productList_.end(); ++it) {
                std::cout << it->getName() << " " << it->getPrice() << '\n';
            }
            std::cout << '\n';

            if (discount) {
                std::cout << "Reward discount: -$3.00" << '\n';
            }

            std::cout << "Balance Due: $" << balanceDue_ << '\n';
            std::cout << "Tender Received: $" <<  tenderReceived_ << '\n';
            std::cout << "Change: $" << changeDue_ << '\n';
            std::cout << '\n';

            std::cout << "Thank you for shopping with us!" << '\n';
            
        }
};

#endif
