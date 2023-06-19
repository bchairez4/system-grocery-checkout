# system-grocery-checkout

Created by Brian Chairez

This C++ project implements a grocery checkout system.

The grocery checkout system functions similarly to its real-life counterpart in which a collection of products are chosen then brought to the checkout register for purchase. 
After successfully making the purchase, a receipt will be generated as a text file that will reflect the relevant transaction. 
The reciept will be named and numbered according to the current order number of the register currently assigned. 
Customer loyalty rewards membership available to accumulate points with every purchase. Ultimately optional, not mandatory. 
Reward points can be accumulated and used for discounts on future purchases. 
Reward discounts are automatic and only discount what is possible.

The system is showcased through the Menu class which acts as a user interface in which the current user is treated as a customer and is prompted to sign in, sign up, or start their order like normal. 
Signing in or signing up only affects reward point accumulation and redemption, other than that the 'shopping' experience is the same regardless. 
The customer has the ability to add, view, and or remove products to and from their cart as they see fit. 
Products can be viewed as a whole or by department. 
Reciept is printed after an appropriate checkout. Any signed in customer will be automatically signed out for the start of the next order. 

An admin sign in is available with higher priviledge functionality. 
The admin user is able to directly modify the databses and the information contained within them.
