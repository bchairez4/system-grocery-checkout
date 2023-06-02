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
}

void Receipt::print() {
    //Receipt header (store name, other basic stroe related info)
    //Cashier name
    //print contents of productList organized by: product-name  quanitity(?)  price
    //final total
    //currency given
    //change due
    //Receipt footer (thanks for shopping with us)
}
