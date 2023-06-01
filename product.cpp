#include "product.h"

Product::Product() : ID_(-1), name_("NULL"), price_(-1.0f) {}

Product::Product(const int& ID, const std::string& name, const float& price) : ID_(ID), name_(name), price_(price) {}

Product::Product(const Product& other) : ID_(other.ID_), name_(other.name_), price_(other.price_) {}

Product::~Product() {}

Product& Product::operator=(const Product& other) {
    ID_ = other.ID_;
    name_ = other.name_;
    price_ = other.price_;
    return *this;
}

int Product::getID() const {
    return ID_;
}

std::string Product::getName() const {
    return name_;
}

float Product::getPrice() const {
    return price_;
}

void Product::setID(const int& ID) {
    ID_ = ID;
}

void Product::setName(const std::string& name) {
    name_ = name;
}

void Product::setPrice(const float& price) {
    price_ = price;
}
