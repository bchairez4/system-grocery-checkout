#include "receipt.h"

Receipt::Receipt() {}

Receipt::Receipt(const Receipt& other) {
    productList_.clear();
    for (int i = 0; i < other.productList_.size(); ++i) {
        productList_.push_back(other.productList_[i]);
    }
}

Receipt::~Receipt() {}

Receipt& Receipt::operator=(const Receipt& other) {
    productList_.clear();
    for (int i = 0; i < other.productList_.size(); ++i) {
        productList_.push_back(other.productList_[i]);
    }
    return *this;
}

void Receipt::create(const std::vector<Product>& productList) {
    for (int i = 0; i < productList.size(); ++i) {
        productList_.push_back(productList[i]);
    }
}

void Receipt::print() {
    for (std::vector<Product>::const_iterator it = productList_.begin(); it != productList_.end(); ++it) {
        std::cout << it->getName() << " " << it->getPrice() << '\n';
    }
}
