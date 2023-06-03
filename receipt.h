#ifndef RECEIPT_H
#define RECEIPT_H

#include "product.cpp"
#include <iostream>
#include <vector>

class Receipt {
    private:
        std::vector<Product> productList_;
    public:
        Receipt();
        Receipt(const Receipt& other);
        ~Receipt();
        Receipt& operator=(const Receipt& other);
        void create(const std::vector<Product>& productList);
        void print();
};

#endif
