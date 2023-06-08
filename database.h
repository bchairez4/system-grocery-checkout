#ifndef DATABASE_H
#define DATABASE_H

#include "cashier.cpp"
#include "customer.cpp"
#include "product.cpp"
#include <fstream>
#include <unordered_map>

class Database {
    private:
        std::unordered_map<int, Cashier> cashiers_;
        std::unordered_map<int, Customer> customers_;
        std::unordered_map<std::string, Product> products_;
    public:
        Database();
        Database(const Database& other);
        ~Database();
        Database& operator=(const Database& other);
        std::unordered_map<int, Cashier>::iterator findCashier(const int& pin);
        std::unordered_map<int, Customer>::iterator findCustomer(const int& phoneNumber);
        std::unordered_map<std::string, Product>::iterator findProduct(const std::string& name);
        bool containsCashier(const int& pin) const;
        bool containsCustomer(const int& phoneNumber) const;
        bool containsProduct(const std::string& name) const;
        void addCashier(const Cashier& cashier);
        void addCustomer(const Customer& customer);
        void addProduct(const Product& product);
        void loadCashiers(const std::string& fileName);
        void loadCustomers(const std::string& fileName);
        void loadProducts(const std::string& fileName);
        void save();
        void saveCashiers();
        void saveCustomers();
        void saveProducts();
        void updateCashier(const Cashier& oldCashier, const Cashier& newCashier);
        void updateCustomer(const Customer& oldCustomer, const Customer& newCustomer);
        void updateProduct(const Product& oldProduct, const Product& newProduct);
        void removeCashier(const Cashier& cashier);
        void removeCustomer(const Customer& customer);
        void removeProduct(const Product& product);

};

#endif
