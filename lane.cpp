#include "lane.h"

Lane::Lane() : signedIn_(false) {}

Lane::Lane(const std::vector<Product>& cart) {
    for (int i = 0; i < cart.size(); ++i) {
        cart_.push(cart[i]);
    }
}

Lane::Lane(const Lane& other) : signedIn_(other.signedIn_), reg_(other.reg_), cart_(other.cart_) {}

Lane::~Lane() {}

Lane& Lane::operator=(const Lane& other) {
    signedIn_ = other.signedIn_;
    reg_ = other.reg_;
    cart_ = other.cart_;
    return *this;
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

bool Lane::isSignedIn() const {
    return signedIn_;
}

bool Lane::isAssigned() const {
    return reg_.getCashier().getFirstName() != "NULL";
}

void Lane::signIn(const int& pin) {
    if (isAssigned()) {
        return;
    }

    if (reg_.getCashier().getPin() == pin) {
        signedIn_ = true;
    }
}

void Lane::signOut() {
    if (isAssigned()) {
        signedIn_ = false;
    }
}

void Lane::assignRegister(const Cashier& cashier) {
    reg_.setCashier(cashier);
}

float Lane::closeRegister() {
    if (!isAssigned()) {
        return 0.00f;
    }

    float deposit = reg_.close();

    return deposit;
}

void Lane::scanProducts() {
    // Simulates scanning an item from the treadmill one at a time as a customer unloads their cart
    while (!cart_.empty()) {
        reg_.addProduct(cart_.front());
        cart_.pop();
    }
}

void Lane::removeProduct(const Product& product) {
    reg_.removeProduct(product);
}

void Lane::checkout(const float& tenderReceived) {
    reg_.checkout(tenderReceived);
    reg_.printReceipt();
}
