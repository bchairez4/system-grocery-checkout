#include "system.h"

System::System() : profit_(0.00f) {}

System::System(const System& other) 
: profit_(other.profit_), lane_(other.lane_), customer_(other.customer_), database_(other.database_) {}

System::~System() {}

System& System::operator=(const System& other) {
    profit_ = other.profit_;
    lane_ = other.lane_;
    customer_ = other.customer_;
    database_ = other.database_;
    return *this;
}

bool System::containsCashier(const Cashier& cashier) const {
    return database_.containsCashier(cashier.getPin());
}

bool System::containsCustomer(const Customer& customer) const {
    return database_.containsCustomer(customer.getPhoneNumber());
}

bool System::containsProduct(const Product& product) const {
    return database_.containsProduct(product.getName());
}

void System::displayCashierDatabase() const {
    database_.displayCashierDatabase();
}

void System::displayCustomerDatabase() const {
    database_.displayCustomerDatabase();
}

void System::displayProductDatabase() const {
    database_.displayProductDatabase();
}

float System::getProfit() const {
    return profit_;
}

void System::updateProfit(const float& income) {
    profit_ += income;
}

Cashier System::getCurrentCashier() const {
    return lane_.getCurrentCashier();
}

void System::signInCashier(const int& pin) {
    if (lane_.isSignedIn()) {
        return;
    }

    if (database_.authenticateCashier(pin)) {
        Cashier cashier = database_.getCashier(pin);
        lane_.assignRegister(cashier);
        lane_.signIn(pin);
    }
}

void System::signOutCashier() {
    if (lane_.isSignedIn()) {
        lane_.signOut();
    }
}

void System::addCashier(const Cashier& cashier) {
    database_.addCashier(cashier);
}

void System::removeCashier(const Cashier& cashier) {
    database_.removeCashier(cashier);
}

void System::updateCashier(const Cashier& oldCashier, const Cashier& newCashier) {
    database_.updateCashier(oldCashier, newCashier);
}

Customer System::getCurrentCustomer() const {
    return customer_;
}

void System::signInCustomer(const int& phoneNumber) {
    if (database_.authenticateCustomer(phoneNumber)) {
        Customer customer = database_.getCustomer(phoneNumber);
        customer_ = customer;
    }
}

void System::signOutCustomer() {
    if (customer_.getFirstName() != "NULL") {
        Customer defaultCustomer;
        customer_ = defaultCustomer;
    }
}

void System::nextCustomer(const Customer& customer) {
    customer_ = customer;
}

void System::addCustomer(const Customer& customer) {
    database_.addCustomer(customer);
}

void System::removeCustomer(const Customer& customer) {
    database_.removeCustomer(customer);
}

Product System::getProduct(const std::string& name) const {
    return database_.getProduct(name);
}

float System::getProductPrice(const Product& product) const {
    return database_.getProduct(product.getName()).getPrice();
}

void System::addProductToCart(const Product& product) {
    customer_.addToCart(product);
}

void System::removeProductFromCart(const Product& product) {
    customer_.removeFromCart(product);
}

void System::addProduct(const Product& product) {
    database_.addProduct(product);
}

void System::removeProduct(const Product& product) {
    database_.removeProduct(product);
}

void System::updateProductPrice(const Product& product, const float& newPrice) {
    Product updatedProduct = product;
    updatedProduct.setPrice(newPrice);
    database_.updateProduct(product, updatedProduct);
}
