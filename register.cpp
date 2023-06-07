#include "register.h"

Register::Register(): balanceDue_(0.00f), tenderReceived_(0.00f), changeDue_(0.00f), depositBalance_(0.00f) {}

Register::Register(const float& depositBalance) : balanceDue_(0.00f), tenderReceived_(0.00f), changeDue_(0.00f), depositBalance_(depositBalance) {}

Register::Register(const Register& other) 
: cashier_(other.cashier_), balanceDue_(other.balanceDue_), tenderReceived_(other.tenderReceived_), changeDue_(other.changeDue_), depositBalance_(other.depositBalance_) {
    productList_.clear();
    for (int i = 0; i < other.productList_.size(); ++i) {
        productList_.push_back(other.productList_[i]);
    }

    receipts_.clear();
    for (int i = 0; i < other.receipts_.size(); ++i) {
        receipts_.push_back(other.receipts_[i]);
    }
}

Register::~Register() {}

Register& Register::operator=(const Register& other) {
    cashier_ = other.cashier_;
    productList_.clear();
    for (int i = 0; i < other.productList_.size(); ++i) {
        productList_.push_back(other.productList_[i]);
    }
    receipts_.clear();
    for (int i = 0; i < other.receipts_.size(); ++i) {
        receipts_.push_back(other.receipts_[i]);
    }
    balanceDue_ = other.balanceDue_;
    tenderReceived_ = other.tenderReceived_;
    changeDue_ = other.changeDue_;
    depositBalance_ = other.depositBalance_;
    return *this;
}

Cashier Register::getCashier() const {
    return cashier_;
}

std::vector<Product> Register::getProductList() const {
    return productList_;
}

std::vector<Receipt> Register::getReceipts() const {
    return receipts_;
}

float Register::getBalanceDue() const {
    return balanceDue_;
}

float Register::getChangeDue() const {
    return changeDue_;
}

int Register::getDepositBalance() const {
    return depositBalance_;
}

float Register::getProductPrice(const Product& product) const {
    return product.getPrice();
}

void Register::setCashier(const Cashier& cashier) {
    cashier_ = cashier;
}

void Register::addProduct(const Product& product) {
    productList_.push_back(product);
    balanceDue_ += product.getPrice();
}

// erases first found instance of given product
void Register::removeProduct(const Product& product) {
    for (std::vector<Product>::iterator it = productList_.begin(); it != productList_.end(); ++it) {
        if (it->getName() == product.getName()) {
            productList_.erase(it);
            balanceDue_ -= product.getPrice();
            return;
        }
    }
}

void Register::checkout(const float& tenderReceived) {
    tenderReceived_  = tenderReceived;
    changeDue_ = balanceDue_ - tenderReceived_;

    depositBalance_ += balanceDue_;
}

void Register::printReceipt() {
    Receipt receipt(productList_);

    std::cout << "Cherries Grocery Store" << '\n';
    std::cout << "Where Good Quality Matters." << '\n';
    std::cout << '\n';

    std::cout << "Cashier: " << cashier_.getFirstName() << " " << cashier_.getLastName().at(0) << "." << '\n';
    std::cout << '\n';

    receipt.print();
    std::cout << '\n';

    std::cout << "Balance Due: $" << balanceDue_ << '\n';
    std::cout << "Tender Received: $" <<  tenderReceived_ << '\n';
    std::cout << "Change: $" << changeDue_ << '\n';
    std::cout << '\n';

    std::cout << "Thank you for shopping with us!" << '\n';

    //save receipt to history of receipts
    receipts_.push_back(receipt);

    //reset variables for next transaction
    balanceDue_ = 0.00f;
    tenderReceived_ = 0.00f;
    changeDue_ = 0.00f;
}

// Closing the register has to take out money made
float Register::close() {
    Cashier null_cashier;

    cashier_ = null_cashier;
    productList_.clear();
    
    float deposit = depositBalance_;
    depositBalance_ = 0.00f;

    return deposit;
}
