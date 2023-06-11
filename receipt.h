#ifndef RECEIPT_H
#define RECEIPT_H

#include "product.h"
#include <iostream>
#include <vector>

class Receipt {
    private:
        std::vector<Product> productList_;
    public:
        Receipt() {}

        Receipt(const std::vector<Product>& productList) {
            for (int i = 0; i < productList.size(); ++i) {
                productList_.push_back(productList[i]);
            }
        }

        Receipt(const Receipt& other) {
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }
        }

        ~Receipt() {}

        Receipt& operator=(const Receipt& other) {
            productList_.clear();
            for (int i = 0; i < other.productList_.size(); ++i) {
                productList_.push_back(other.productList_[i]);
            }
            return *this;
        }

        void print() {
            for (std::vector<Product>::const_iterator it = productList_.begin(); it != productList_.end(); ++it) {
                std::cout << it->getName() << " " << it->getPrice() << '\n';
            }
        }
};

#endif
