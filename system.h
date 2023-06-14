#ifndef SYSTEM_H
#define SYSTEM_H

#include "lane.h"
#include "database.h"

class System {
    private:
        float profit_;
        Lane lane_;
        Customer customer_;
        Database database_;
    public:
        System() : profit_(0.00f) {
            assignCashier(database_.getCashier(8919));
        }

        System(const System& other) 
        : profit_(other.profit_), lane_(other.lane_), customer_(other.customer_), database_(other.database_) {}

        ~System() {}

        System& operator=(const System& other) {
            profit_ = other.profit_;
            lane_ = other.lane_;
            customer_ = other.customer_;
            database_ = other.database_;
            return *this;
        }

        bool containsCashier(const int& pin) const {
            return database_.containsCashier(pin);
        }

        bool containsCustomer(const int& phoneNumber) const {
            return database_.containsCustomer(phoneNumber);
        }

        bool containsProduct(const std::string& name) const {
            return database_.containsProduct(name);
        }

        void displayCashierDatabase() const {
            database_.displayCashierDatabase();
        }

        void displayCustomerDatabase() const {
            database_.displayCustomerDatabase();
        }

        void displayProductDatabase() const {
            database_.displayProductDatabase();
        }

        void displayProductDatabaseByDepartment(const std::string& department) const {
            database_.displayProductDatabaseByDepartment(department);
        }

        float getProfit() const {
            return profit_;
        }

        void updateProfit(const float& income) {
            profit_ += income;
        }

        Cashier getCurrentCashier() const {
            return lane_.getCurrentCashier();
        }

        void signInCashier(const int& pin) {
            if (lane_.isSignedIn()) {
                return;
            }

            if (database_.authenticateCashier(pin)) {
                Cashier cashier = database_.getCashier(pin);
                lane_.assignRegister(cashier);
                lane_.signIn(pin);
            }
        }

        void signOutCashier() {
            if (lane_.isSignedIn()) {
                lane_.signOut();
            }
        }

        void assignCashier(const Cashier& cashier) {
            lane_.assignRegister(cashier);
        }

        void closeOutCashier() {
            float deposit = lane_.closeRegister();
            updateProfit(deposit);
        }

        void addCashier(const Cashier& cashier) {
            database_.addCashier(cashier);
        }

        void removeCashier(const Cashier& cashier) {
            database_.removeCashier(cashier);
        }

        void updateCashier(const Cashier& oldCashier, const Cashier& newCashier) {
            database_.updateCashier(oldCashier, newCashier);
        }

        Customer getCurrentCustomer() const {
            return customer_;
        }

        bool customerSignedIn() const {
            return customer_.getFirstName() != "NULL";
        }

        bool containsInCart(const std::string& productName) const {
            return customer_.contains(productName);
        }

        bool emptyCustomerCart() const {
            return customer_.emptyCart();
        }

        float getCustomerCartTotal() const {
            return customer_.getCartTotal();
        }

        int getCustomerRewardPoints() const {
            return customer_.getRewardPoints();
        }

        void displayCustomerCart() const {
            customer_.displayCart();
        }

        void signInCustomer(const int& phoneNumber) {
            if (database_.authenticateCustomer(phoneNumber)) {
                Customer customer = database_.getCustomer(phoneNumber);
                customer_ = customer;
            }
        }

        void signOutCustomer() {
            if (customer_.getFirstName() != "NULL") {
                Customer defaultCustomer;
                customer_ = defaultCustomer;
            }
        }

        void checkoutCustomer(const float& tenderReceived) {
            lane_.addProductsToLane(customer_.getCart());
            customer_.clearCart();

            lane_.scanProducts();

            float purchaseAmount = lane_.checkout(tenderReceived);
            if (customerSignedIn()) {
                int pointsGained = purchaseAmount/3;
                customer_.setRewardPoints(pointsGained);
                database_.updateCustomerRewardPoints(customer_, pointsGained);
                signOutCustomer();
            }
        }

        void addCustomer(const Customer& customer) {
            database_.addCustomer(customer);
        }

        void removeCustomer(const Customer& customer) {
            database_.removeCustomer(customer);
        }

        Product getProduct(const std::string& name) const {
            return database_.getProduct(name);
        }

        float getProductPrice(const Product& product) const {
            return database_.getProduct(product.getName()).getPrice();
        }

        void addProductToCart(const Product& product) {
            customer_.addToCart(product);
        }

        void removeProductFromCart(const Product& product) {
            customer_.removeFromCart(product);
        }

        void addProduct(const Product& product) {
            database_.addProduct(product);
        }

        void removeProduct(const Product& product) {
            database_.removeProduct(product);
        }

        void updateProductPrice(const Product& product, const float& newPrice) {
            Product updatedProduct = product;
            updatedProduct.setPrice(newPrice);
            database_.updateProduct(product, updatedProduct);
        }
};

#endif
