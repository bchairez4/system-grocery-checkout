#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "product.h"
#include "person.h"

class Customer : public Person {
    private:
        int phoneNumber_;
        int rewardPoints_;
        std::vector<Product> cart_;
    public:
        Customer() : phoneNumber_(-1), rewardPoints_(-1) {}

        Customer(const std::string& firstName, const std::string& lastName, const int& phoneNumber, const int& rewardPoints)
        : Person(firstName, lastName), phoneNumber_(phoneNumber), rewardPoints_(rewardPoints) {}

        Customer(const Customer& other) : phoneNumber_(other.phoneNumber_), rewardPoints_(other.rewardPoints_) {
            cart_.clear();
            for (int i = 0; i < other.cart_.size(); ++i) {
                cart_.push_back(cart_[i]);
            }
        }

        ~Customer() {}

        Customer& operator=(const Customer& other) {
            setFirstName(other.getFirstName());
            setLastName(other.getLastName());
            cart_.clear();
            for (int i = 0; i < other.cart_.size(); ++i) {
                cart_.push_back(cart_[i]);
            }
            return *this;
        }

        std::vector<Product> getCart() const {
            return cart_;
        }

        bool contains(const std::string& productName) const{
            for (std::vector<Product>::const_iterator it = cart_.cbegin(); it != cart_.cend(); ++it) {
                if (it->getName() == productName) {
                    return true;
                }
            }

            return false;
        }

        bool emptyCart() const {
            return cart_.empty();
        }

        int getPhoneNumber() const {
            return phoneNumber_;
        }

        int getRewardPoints() const {
            return rewardPoints_;
        }

        void setPhoneNumber(const int& phoneNumber) {
            phoneNumber_ = phoneNumber;
        }

        void setRewardPoints(const int& rewardPoints) {
            rewardPoints_ = rewardPoints;
        }

        void setCart(const std::vector<Product>& cart) {
            for (int i = 0; i < cart.size(); ++i) {
                cart_.push_back(cart[i]);
            }
        }

        void addToCart(const Product& product) {
            cart_.push_back(product);
        }

        void removeFromCart(const Product& product) {
            for (std::vector<Product>::iterator it = cart_.begin(); it != cart_.end(); ++it) {
                if (it->getName() == product.getName()) {
                    cart_.erase(it);
                    return;
                }
            }
        }

        void displayCart() const {
            std::cout << "Current Cart:" << '\n';
            for (std::vector<Product>::const_iterator it = cart_.cbegin(); it != cart_.cend(); ++it) {
                std::cout << it->getName() << " " << it->getPrice() << '\n';
            }
            std::cout << '\n';
        }
};

#endif
