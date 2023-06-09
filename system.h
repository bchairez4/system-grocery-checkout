#ifndef SYSTEM_H
#define SYSTEM_H

#include "lane.cpp"
#include "database.cpp"

class System {
    private:
        float profit_;
        Lane lane_;
        Customer customer_;
        Database database_;
    public:
        System();
        System(const System& other);
        ~System();
        System& operator=(const System& other);
        bool containsCashier(const Cashier& cashier) const;
        bool containsCustomer(const Customer& customer) const;
        bool containsProduct(const Product& product) const;
        void displayCashierDatabase() const;
        void displayCustomerDatabase() const;
        void displayProductDatabase() const;
        float getProfit() const;
        void updateProfit(const float& income);
        Cashier getCurrentCashier() const;
        void signInCashier(const int& pin);
        void signOutCashier();
        void addCashier(const Cashier& cashier);
        void removeCashier(const Cashier& cashier);
        void updateCashier(const Cashier& oldCashier, const Cashier& newCashier);
        Customer getCurrentCustomer() const;
        void signInCustomer(const int& phoneNumber);
        void signOutCustomer();
        void nextCustomer(const Customer& customer);
        void addCustomer(const Customer& customer);
        void removeCustomer(const Customer& customer);
        Product getProduct(const std::string& name) const;
        float getProductPrice(const Product& product) const;
        void addProductToCart(const Product& product);
        void removeProductFromCart(const Product& product);
        void addProduct(const Product& product);
        void removeProduct(const Product& product);
        void updateProductPrice(const Product& product, const float& newPrice);
};

#endif