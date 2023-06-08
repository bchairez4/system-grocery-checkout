#include "customer.h"

Customer::Customer() : phoneNumber_(-1), rewardPoints_(-1) {}

Customer::Customer(const std::string& firstName, const std::string& lastName, const int& phoneNumber, const int& rewardPoints)
: Person(firstName, lastName), phoneNumber_(phoneNumber), rewardPoints_(rewardPoints) {}

Customer::Customer(const Customer& other) : phoneNumber_(other.phoneNumber_), rewardPoints_(other.rewardPoints_) {
    cart_.clear();
    for (int i = 0; i < other.cart_.size(); ++i) {
        cart_.push_back(cart_[i]);
    }
}

Customer::~Customer() {}

Customer& Customer::operator=(const Customer& other) {
    setFirstName(other.getFirstName());
    setLastName(other.getLastName());
    cart_.clear();
    for (int i = 0; i < other.cart_.size(); ++i) {
        cart_.push_back(cart_[i]);
    }
    return *this;
}

int Customer::getPhoneNumber() const {
    return phoneNumber_;
}

int Customer::getRewardPoints() const {
    return rewardPoints_;
}

void Customer::setPhoneNumber(const int& phoneNumber) {
    phoneNumber_ = phoneNumber;
}

void Customer::setRewardPoints(const int& rewardPoints) {
    rewardPoints_ = rewardPoints;
}

void Customer::setCart(const std::vector<Product>& cart) {
    for (int i = 0; i < cart.size(); ++i) {
        cart_.push_back(cart[i]);
    }
}

void Customer::addToCart(const Product& product) {
    cart_.push_back(product);
}

void Customer::removeFromCart(const Product& product) {
    for (std::vector<Product>::iterator it = cart_.begin(); it != cart_.end(); ++it) {
        if (it->getName() == product.getName()) {
            cart_.erase(it);
            return;
        }
    }
}
