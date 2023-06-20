#ifndef DATABASE_H
#define DATABASE_H

#include "cashier.h"
#include "customer.h"
#include "product.h"
#include <fstream>
#include <unordered_map>

#define CASHIERS "cashiers.txt"
#define CUSTOMERS "customers.txt"
#define PRODUCTS "products.txt"

class Database {
    private:
        std::unordered_map<int, Cashier> cashiers_;
        std::unordered_map<int, Customer> customers_;
        std::unordered_map<std::string, Product> products_;
    public:
        Database() {
            loadCashiers(CASHIERS);
            loadCustomers(CUSTOMERS);
            loadProducts(PRODUCTS);
        }

        Database(const Database& other) : cashiers_(other.cashiers_), customers_(other.customers_), products_(other.products_) {}

        ~Database() {
            save();
        }

        Database& operator=(const Database& other) {
            cashiers_ = other.cashiers_;
            customers_ = other.customers_;
            products_ = other.products_;
            return *this;
        }

        std::unordered_map<int, Cashier>::iterator findCashier(const int& pin) {
            std::unordered_map<int, Cashier>::iterator it = cashiers_.find(pin);
            return it;
        }

        std::unordered_map<int, Customer>::iterator findCustomer(const int& phoneNumber) {
            std::unordered_map<int, Customer>::iterator it = customers_.find(phoneNumber);
            return it;
        }

        std::unordered_map<std::string, Product>::iterator findProduct(const std::string& name) {
            std::unordered_map<std::string, Product>::iterator it = products_.find(name);
            return it;
        }

        Cashier getCashier(const int& pin) const {
            std::unordered_map<int, Cashier>::const_iterator it = cashiers_.find(pin);

            return it->second;
        }

        Customer getCustomer(const int& phoneNumber) const {
            std::unordered_map<int, Customer>::const_iterator it = customers_.find(phoneNumber);

            return it->second;
        }

        Product getProduct(const std::string& name) const {
            std::unordered_map<std::string, Product>::const_iterator it = products_.find(name);

            return it->second;
        }

        std::vector<std::string> getProductDepartments() const {
            std::unordered_map<std::string, int> departments;

            for (std::unordered_map<std::string, Product>::const_iterator it = products_.cbegin(); it != products_.cend(); ++it) {
                if (departments.find(it->second.getDepartment()) != departments.end()) {
                    continue;
                } else {
                    departments.insert({it->second.getDepartment(), 1});
                }
            }

            std::vector<std::string> departmentVector;
            for (std::unordered_map<std::string, int>::const_iterator it = departments.cbegin(); it != departments.cend(); ++it) {
                departmentVector.push_back(it->first);
            }

            return departmentVector;
        }

        bool authenticateCashier(const int& pin) const {
            std::unordered_map<int, Cashier>::const_iterator it = cashiers_.find(pin);

            if (it != cashiers_.end()) {
                if (it->second.getPin() == pin) {
                    return true;
                }
            }

            return false;
        }

        bool authenticateCustomer(const int& phoneNumber) const {
            std::unordered_map<int, Customer>::const_iterator it = customers_.find(phoneNumber);

            if (it != customers_.end()) {
                if (it->second.getPhoneNumber() == phoneNumber) {
                    return true;
                }
            }

            return false;
        }

        bool containsCashier(const int& pin) const {
            return cashiers_.count(pin) > 0;
        }

        bool containsCustomer(const int& phoneNumber) const {
            return customers_.count(phoneNumber) > 0;
        }

        bool containsProduct(const std::string& name) const {
            return products_.count(name) > 0;
        }

        void displayCashierDatabase() const {
            for (std::unordered_map<int, Cashier>::const_iterator it = cashiers_.cbegin(); it != cashiers_.cend(); ++it) {
                std::cout << it->second.getPin() << " "
                          << it->second.getFirstName() << " "
                          << it->second.getLastName() << '\n';
            }
        }

        void displayCustomerDatabase() const {
            for (std::unordered_map<int, Customer>::const_iterator it = customers_.cbegin(); it != customers_.cend(); ++it) {
                std::cout << it->second.getFirstName() << " "
                          << it->second.getLastName() << " "
                          << it->second.getPhoneNumber() << " "
                          << it->second.getRewardPoints() << '\n';
            }
        }

        void displayProductDatabase() const {
            for (std::unordered_map<std::string, Product>::const_iterator it = products_.cbegin(); it != products_.cend(); ++it) {
                std::cout << it->second.getDepartment() << " " 
                          << it->second.getName() << " " 
                          << std::fixed << std::setprecision(2) << it->second.getPrice() << '\n';
            }
        }

        void displayProductDatabaseByDepartment(const std::string& department) const {
            for (std::unordered_map<std::string, Product>::const_iterator it = products_.cbegin(); it != products_.cend(); ++it) {
                if (it->second.getDepartment() == department) {
                    std::cout << it->second.getDepartment() << " " 
                              << it->second.getName() << " " 
                              << std::fixed << std::setprecision(2) << it->second.getPrice() << '\n';
                }
            }
        }

        void addCashier(const Cashier& cashier) {
            if (!containsCashier(cashier.getPin())) {
                cashiers_.insert({cashier.getPin(), cashier});
            }
        }

        void addCustomer(const Customer& customer) {
            if (!containsCustomer(customer.getPhoneNumber())) {
                customers_.insert({customer.getPhoneNumber(), customer});
            }
        }

        void addProduct(const Product& product) {
            if (!containsProduct(product.getName())) {
                products_.insert({product.getName(), product});
            }
        }

        void loadCashiers(const std::string& fileName) {
            std::ifstream file(fileName, std::ifstream::in);

            if (!file) {
                return;
            }

            while (!file.eof()) {
                int pin = -1;
                std::string firstName, lastName = "";

                file >> pin >> firstName >> lastName >> std::ws;

                Cashier tempCashier(pin, firstName, lastName);
                cashiers_.insert({pin, tempCashier});
            }
        }

        void loadCustomers(const std::string& fileName) {
            std::ifstream file(fileName, std::ifstream::in);

            if (!file) {
                return;
            }

            while (!file.eof()) {
                int phoneNumber, rewardPoints = -1;
                std::string firstName, lastName = "";

                file >> firstName >> lastName >> phoneNumber >> rewardPoints >> std::ws;

                Customer tempCustomer(firstName, lastName, phoneNumber, rewardPoints);
                customers_.insert({phoneNumber, tempCustomer});
            }
        }

        void loadProducts(const std::string& fileName) {
            std::ifstream file(fileName, std::ifstream::in);

            if (!file) {
                return;
            }

            while (!file.eof()) {
                float price = 0.00f;
                std::string department, name = "";

                file >> department >> name >> price >> std::ws;

                Product tempProduct(department, name, price);
                products_.insert({name, tempProduct});
            }
        }

        void save() {
            saveCashiers();
            saveCustomers();
            saveProducts();
        }

        void saveCashiers() {
            std::ofstream file(CASHIERS, std::ofstream::out);

            if (!file) {
                return;
            }

            for (std::unordered_map<int, Cashier>::iterator it = cashiers_.begin(); it != cashiers_.end(); ++it) {
                file << it->second.getPin() << " "
                     << it->second.getFirstName() << " "
                     << it->second.getLastName() << '\n';
            }
        }

        void saveCustomers() {
            std::ofstream file(CUSTOMERS, std::ofstream::out);

            if (!file) {
                return;
            }

            for (std::unordered_map<int, Customer>::iterator it = customers_.begin(); it != customers_.end(); ++it) {
                file << it->second.getFirstName() << " " 
                     << it->second.getLastName() << " "
                     << it->second.getPhoneNumber() << " "
                     << it->second.getRewardPoints() << '\n';
            }
        }

        void saveProducts() {
            std::ofstream file(PRODUCTS, std::ofstream::out);

            if (!file) {
                return;
            }

            for (std::unordered_map<std::string, Product>::iterator it = products_.begin(); it != products_.end(); ++it) {
                file << it->second.getDepartment() << " "
                     << it->second.getName() << " "
                     << std::fixed << std::setprecision(2) << it->second.getPrice() << '\n';
            }
        }

        void updateCashier(const Cashier& oldCashier, const Cashier& newCashier) {
            std::unordered_map<int, Cashier>::iterator it = findCashier(oldCashier.getPin());

            if (it != cashiers_.end()) {
                it->second.operator=(newCashier);
            }
        }

        void updateCustomer(const Customer& oldCustomer, const Customer& newCustomer) {
            std::unordered_map<int, Customer>::iterator it = findCustomer(oldCustomer.getPhoneNumber());

            if (it != customers_.end()) {
                it->second.operator=(newCustomer);
            }
        }

        void updateCustomerRewardPoints(const Customer& customer, const int& rewardPoints) {
            std::unordered_map<int, Customer>::iterator it = findCustomer(customer.getPhoneNumber());

            if (it != customers_.end()) {
                it->second.setRewardPoints(rewardPoints);
            }
        }

        void updateProduct(const Product& oldProduct, const Product& newProduct) {
            std::unordered_map<std::string, Product>::iterator it = findProduct(oldProduct.getName());

            if (it != products_.end()) {
                it->second.operator=(newProduct);
            }
        }

        void removeCashier(const Cashier& cashier) {
            if (containsCashier(cashier.getPin())) {
                std::unordered_map<int, Cashier>::iterator it = findCashier(cashier.getPin());
                cashiers_.erase(it);
            }
        }

        void removeCustomer(const Customer& customer) {
            if (containsCustomer(customer.getPhoneNumber())) {
                std::unordered_map<int, Customer>::iterator it = findCustomer(customer.getPhoneNumber());
                customers_.erase(it);
            }
        }

        void removeProduct(const Product& product) {
            if (containsProduct(product.getName())) {
                std::unordered_map<std::string, Product>::iterator it = findProduct(product.getName());
                products_.erase(it);
            }
        }


};

#endif
