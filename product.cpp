#include "product.h"

Product::Product() : department_("NULL"), name_("NULL"), price_(-1.0f) {}

Product::Product(const std::string& department, const std::string& name, const float& price) : department_(department), name_(name), price_(price) {}

Product::Product(const Product& other) : department_(other.department_), name_(other.name_), price_(other.price_) {}

Product::~Product() {}

Product& Product::operator=(const Product& other) {
    department_ = other.department_;
    name_ = other.name_;
    price_ = other.price_;
    return *this;
}

std::string Product::getDepartment() const {
    return department_;
}

std::string Product::getName() const {
    return name_;
}

float Product::getPrice() const {
    return price_;
}

void Product::setDepartment(const std::string& department) {
    department_ = department;
}

void Product::setName(const std::string& name) {
    name_ = name;
}

void Product::setPrice(const float& price) {
    price_ = price;
}
