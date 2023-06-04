#include "lane.h"

Lane::Lane() {}

Lane::Lane(const Lane& other) : reg_(other.reg_), cart_(other.cart_) {}

Lane::~Lane() {}

Lane& Lane::operator=(const Lane& other) {
    reg_ = other.reg_;
    cart_ = other.cart_;
}

Cashier Lane::getCurrentCashier() const {
    return reg_.getCashier();
}

Register Lane::getRegister() const {
    return reg_;
}

std::queue<Product> Lane::getCart() const {
    return cart_;
}

void Lane::assignRegister(const Cashier& cashier) {
    reg_.setCashier(cashier);
}

float Lane::closeRegister() {
    float deposit = reg_.close();

    return deposit;
}

void Lane::scanProducts() {
    // Simulates scanning an item from the treadmill one at a time as a customer unloads thier cart
    while (!cart_.empty()) {
        reg_.addProduct(cart_.front());
        cart_.pop();
    }
}

void Lane::removeProduct(const Product& product) {
    reg_.removeProduct(product);
}

void Lane::checkout(const float& tender_given) {
    reg_.checkout(tender_given);
}
