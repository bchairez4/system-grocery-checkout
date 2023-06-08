#include "database.h"

#define CASHIERS "cashiers.txt"
#define CUSTOMERS "customers.txt"
#define PRODUCTS "products.txt"

Database::Database() {
    loadCashiers(CASHIERS);
    loadCustomers(CUSTOMERS);
    loadProducts(PRODUCTS);
}

Database::Database(const Database& other) {}

Database::~Database() {
    save();
}

Database& Database::operator=(const Database& other) {}

std::unordered_map<int, Cashier>::iterator Database::findCashier(const int& pin) {
    std::unordered_map<int, Cashier>::iterator it = cashiers_.find(pin);
    return it;
}

std::unordered_map<int, Customer>::iterator Database::findCustomer(const int& phoneNumber) {
    std::unordered_map<int, Customer>::iterator it = customers_.find(phoneNumber);
    return it;
}

std::unordered_map<std::string, Product>::iterator Database::findProduct(const std::string& name) {
    std::unordered_map<std::string, Product>::iterator it = products_.find(name);
    return it;
}

bool Database::containsCashier(const int& pin) const {
    return cashiers_.count(pin) > 0;
}

bool Database::containsCustomer(const int& phoneNumber) const {
    return customers_.count(phoneNumber) > 0;
}

bool Database::containsProduct(const std::string& name) const {
    return products_.count(name) > 0;
}

void Database::addCashier(const Cashier& cashier) {
    if (!containsCashier(cashier.getPin())) {
        cashiers_.insert({cashier.getPin(), cashier});
    }
}

void Database::addCustomer(const Customer& customer) {
    if (!containsCustomer(customer.getPhoneNumber())) {
        customers_.insert({customer.getPhoneNumber(), customer});
    }
}

void Database::addProduct(const Product& product) {
    if (!containsProduct(product.getName())) {
        products_.insert({product.getName(), product});
    }
}

void Database::loadCashiers(const std::string& fileName) {
    std::ifstream file(fileName, std::ifstream::in);

    if (!file) {
        return;
    }

    while (!file.eof()) {
        int pin = -1;
        std::string firstName, lastName = "";

        file >> firstName >> lastName >> pin >> std::ws;

        Cashier tempCashier(pin, firstName, lastName);
        cashiers_.insert({pin, tempCashier});
    }
}

void Database::loadCustomers(const std::string& fileName) {
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

void Database::loadProducts(const std::string& fileName) {
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

void Database::save() {
    saveCashiers();
    saveCustomers();
    saveProducts();
}

void Database::saveCashiers() {
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

void Database::saveCustomers() {
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

void Database::saveProducts() {
    std::ofstream file(PRODUCTS, std::ofstream::out);

    if (!file) {
        return;
    }

    for (std::unordered_map<std::string, Product>::iterator it = products_.begin(); it != products_.end(); ++it) {
        file << it->second.getDepartment() << " "
             << it->second.getName() << " "
             << it->second.getPrice() << '\n';
    }
}

void Database::updateCashier(const Cashier& oldCashier, const Cashier& newCashier) {
    std::unordered_map<int, Cashier>::iterator it = findCashier(oldCashier.getPin());

    if (it != cashiers_.end()) {
        it->second.operator=(newCashier);
    }
}

void Database::updateCustomer(const Customer& oldCustomer, const Customer& newCustomer) {
    std::unordered_map<int, Customer>::iterator it = findCustomer(oldCustomer.getPhoneNumber());

    if (it != customers_.end()) {
        it->second.operator=(newCustomer);
    }
}

void Database::updateProduct(const Product& oldProduct, const Product& newProduct) {
    std::unordered_map<std::string, Product>::iterator it = findProduct(oldProduct.getName());

    if (it != products_.end()) {
        it->second.operator=(newProduct);
    }
}

void Database::removeCashier(const Cashier& cashier) {
    if (containsCashier(cashier.getPin())) {
        std::unordered_map<int, Cashier>::iterator it = findCashier(cashier.getPin());
        cashiers_.erase(it);
    }
}

void Database::removeCustomer(const Customer& customer) {
    if (containsCustomer(customer.getPhoneNumber())) {
        std::unordered_map<int, Customer>::iterator it = findCustomer(customer.getPhoneNumber());
        customers_.erase(it);
    }
}

void Database::removeProduct(const Product& product) {
    if (containsProduct(product.getName())) {
        std::unordered_map<std::string, Product>::iterator it = findProduct(product.getName());
        products_.erase(it);
    }
}
