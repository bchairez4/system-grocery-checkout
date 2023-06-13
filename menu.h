#ifndef MENU_H
#define MENU_H

#include "system.h"

class Menu {
    private:
        System system_;
    public:
        Menu() {
            displayWelcome();

            char input = ' ';
            while (input != 'q') {
                if (system_.customerSignedIn()) {
                    displayCustomerRewardMenu();
                    input = customerRewardMenu();
                } else {
                    displayCustomerMenu();
                    input = customerMenu();
                }
            }

            displayFarewell();
        }

        Menu(const Menu& other) : system_(other.system_) {}

        ~Menu() {}

        Menu& operator=(const Menu& other) {
            system_ = other.system_;
            return *this;
        }

        void displayWelcome() const {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Welcome to Cherries Grocery System!" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Please type in your choice followed by pressing \'enter\'." << '\n';
            std::cout << '\n';
        }

        void displayFarewell() const {
            std::cout << "Thank you for using the Cherries Grocery System." << '\n';
            std::cout << "Hope to see you again soon." << '\n';
        }

        void displayAdminMenu() const {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Main Menu" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "1) Display Cashier Database" << '\n';
            std::cout << "2) Add Cashier to Database" << '\n';
            std::cout << "3) Remove Cashier From Database" << '\n';
            std::cout << "4) Display Customer Database" << '\n';
            std::cout << "5) Add Customer To Database" << '\n';
            std::cout << "6) Remove Customer From Database" << '\n';
            std::cout << "7) Display Product Database" << '\n';
            std::cout << "8) Add Product To Database" << '\n';
            std::cout << "9) Remove Product From Database" << '\n';
            std::cout << "0) Exit" << '\n';
        }

        void displayCustomerMenu() const {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Main Menu" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "1) Sign In" << '\n';
            std::cout << "2) Sign Up" << '\n';
            std::cout << "3) Add Product to Cart" << '\n';
            std::cout << "4) Remove Product from Cart" << '\n';
            std::cout << "5) Display Products" << '\n';
            std::cout << "6) Display Products by Category" <<  '\n';
            std::cout << "7) Check Cart" << '\n';
            std::cout << "8) Checkout" << '\n';
            std::cout << "9) Exit" << '\n';
            std::cout << '\n';
        }

        void displayCustomerRewardMenu() const {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Main Menu" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "1) Check Reward Points" << '\n';
            std::cout << "2) Add Product to Cart" << '\n';
            std::cout << "3) Remove Product from Cart" << '\n';
            std::cout << "4) Display Products" << '\n';
            std::cout << "5) Display Products by Category" <<  '\n';
            std::cout << "6) Check Cart" << '\n';
            std::cout << "7) Checkout" << '\n';
            std::cout << "8) Exit" << '\n';
            std::cout << '\n';
        }

        char customerMenu() {
            char input = ' ';
            std::cin.get(input);
            std::cin.ignore(100, '\n');
            std::cout << '\n';

            switch(input) {
                case '1':
                    signIn();
                    break;
                case '2':
                    signUp();
                    break;
                case '3':
                    addProductToCart();
                    break;
                case '4':
                    removeProductFromCart();
                    break;
                case '5':
                    displayProducts();
                    break;
                case '6':
                    displayProductsByCategory();
                    break;
                case '7':
                    checkCart();
                    break;
                case '8':
                    checkout();
                    break;
                case '9':
                    return 'q';
                    break;
                default:
                    std::cout << "Please type a valid choice followed by pressing \'enter\'." << '\n';
                    break;
            }

            return input;
        }

        char customerRewardMenu() {
            char input = ' ';
            std::cin.get(input);
            std::cin.ignore(100, '\n');
            std::cout << '\n';

            switch(input) {
                case '1':
                    checkRewardPoints();
                    break;
                case '2':
                    addProductToCart();
                    break;
                case '3':
                    removeProductFromCart();
                    break;
                case '4':
                    displayProducts();
                    break;
                case '5':
                    displayProductsByCategory();
                    break;
                case '6':
                    checkCart();
                    break;
                case '7':
                    checkout();
                    break;
                case '8':
                    return 'q';
                    break;
                default:
                    std::cout << "Please type a valid choice followed by pressing \'enter\'." << '\n';
            }

            return input;
        }

        void signIn() {
            int phoneNumber = -1;

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Sign In" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            std::cout << "Enter your Phone Number (ex: 0000000):  ";
            std::cin >> phoneNumber;
            std::cin.ignore();
            std::cout << '\n';

            if (!system_.containsCustomer(phoneNumber)) {
                std::cout << "Error. Number not associated to an account." << '\n';
                return;
            }

            system_.signInCustomer(phoneNumber);

            std::cout << "Welcome back " << system_.getCurrentCustomer().getFirstName() << "!" << '\n';
            std::cout << '\n';
        }

        void signUp() {
            std::string firstName, lastName = "";
            int phoneNumber, rewardPoints = 0;

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Sign Up" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            std::cout << "Please enter your first name: ";
            std::getline(std::cin, firstName);
            std::cout << '\n';

            std::cout << "Please enter your last name: ";
            std::getline(std::cin, lastName);
            std::cout << '\n';

            std::cout << "Please enter your phone number (ex: 0000000): ";
            std::cin >> phoneNumber;
            std::cin.ignore();
            std::cout << '\n';

            Customer newCustomer(firstName, lastName, phoneNumber, rewardPoints);
            system_.addCustomer(newCustomer);
            std::cout << '\n';
        }

        void checkRewardPoints() {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Check Reward Points" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            std::cout << "Current Reward Points Available: " << system_.getCustomerRewardPoints() << " points." << '\n';
            std::cout << '\n';
        }

        void addProductToCart() {
            std::string productName = "";

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Add Product To Cart" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            std::cout<< "What product would you like to add to your cart?" << '\n';
            std::getline(std::cin, productName);
            std::cout << '\n';

            if (!system_.containsProduct(productName)) {
                std::cout << "Error. " << productName << " is not a product we have currently in stock." << '\n';
                std::cout << "To see what is in stock please choose Display Products option in the menu" << '\n';
                return;
            }

            Product newProduct = system_.getProduct(productName);
            system_.addProductToCart(newProduct);

            std::cout << "Added " << productName << " to cart." << '\n';
            std::cout << '\n';
        }

        void removeProductFromCart() {
            std::string productName = "";

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Remove Product From Cart" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            if (system_.emptyCustomerCart()) {
                std::cout << "Error. Cart is currently empty." << '\n';
                return;
            }

            std::cout << "Which product would you like to remove?: ";
            std::getline(std::cin, productName);
            std::cout << '\n';

            if (!system_.containsInCart(productName)) {
                std::cout << "Error. " << productName << " is not in your cart." << '\n';
                return;
            }

            Product product = system_.getProduct(productName);
            system_.removeProductFromCart(product);

            std::cout << "Removed " << productName << " from cart." << '\n';
            std::cout << '\n';
        }

        void displayProducts() {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Display Products" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            system_.displayProductDatabase();
            std::cout << '\n';
        }

        void displayProductsByCategory() {
            std::string department = "";

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Display Products By Category" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            std::cout << "Type in a category: ";
            std:getline(std::cin, department);
            std::cout << '\n';

            system_.displayProductDatabaseByDepartment(department);
            std::cout << '\n';
        }

        void checkCart() {
            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Check Cart" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            if (system_.emptyCustomerCart()) {
                std::cout << "Cart is empty." << '\n';
                std::cout << '\n';
                return;
            }

            system_.displayCustomerCart();
            std::cout << "Current Balance Due: $" << system_.getCustomerCartTotal() << '\n';
            std::cout << '\n';
        }

        void checkout() {
            int tenderReceived = 0;

            std::cout << "--------------------------------------------------------------------" << '\n';
            std::cout << "Checkout" << '\n';
            std::cout << "--------------------------------------------------------------------" << '\n';

            if (system_.emptyCustomerCart()) {
                std::cout << "Empty Cart." << '\n';
                return;
            }

            system_.displayCustomerCart();

            std::cout << "Amount Due: " << system_.getCustomerCartTotal() << '\n';;
            std::cout << '\n';

            std::cout << "Pay Amount: $";
            std::cin >> tenderReceived;
            std::cin.ignore();
            std::cout << '\n';

            if (tenderReceived < system_.getCustomerCartTotal()) {
                while (tenderReceived < system_.getCustomerCartTotal()) {
                    std::cout << "Total is $" << system_.getCustomerCartTotal() 
                              << " and you entered $" << tenderReceived << '\n';
                    std::cout << "Enter the correct amount: $";
                    std::cin >> tenderReceived;
                    std::cin.ignore();
                    std::cout << '\n';
                }
            }

            float income = system_.checkOutCustomer(tenderReceived);
            std::cout << '\n';
        }
};

#endif
