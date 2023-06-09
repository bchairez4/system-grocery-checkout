# system-grocery-checkout

Created by Brian Chairez

This C++ project implements a grocery checkout system.

The grocery checkout system functions similarly to its real-life counterpart in which a customer selects a collection of products which are then brought to the checkout register for purchase. 
After successfully making the purchase, a receipt will be generated as a text file that will reflect the relevant transaction. 
The reciept will be numbered according to the current order number of the register currently assigned. 
Customer loyalty rewards membership available to accumulate points with every purchase. Ultimately optional, not mandatory. 
Reward points can be accumulated and used for discounts on future purchases. 
This system offers a $3.00 discount for every 35 points gained. Points gained are based on total purchase amount. 
For every $3 spent, that is 1 point gained. 
Reward discounts are automatic and only discount what is possible, meaning no negative balances.

The system is showcased through the Menu class which acts as a user interface in which the current user is treated as a customer and is prompted to sign in, sign up, or start their order like normal. 
Signing in or signing up only affects reward point accumulation and redemption; the 'shopping' experience is the same regardless. 
The customer has the ability to add, view, and or remove products to and from their cart as they see fit. 
Products can be viewed as a whole or by department. 
Receipt is printed after an appropriate checkout. Any signed in customer will be automatically signed out for the start of the next new order. 

An admin sign in is available with higher privilege functionality. 
The admin user is able to directly modify the databases and the information contained within them. 
'Store profit' can be viewed via the Admin menu as well.
