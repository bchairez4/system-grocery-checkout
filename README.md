# system-grocery-checkout

Created by Brian Chairez

This C++ project implements a grocery checkout system.

The grocery checkout system functions similarly to its real-life counterpart in which a collection of items is brought to the checkout in order to purchase said items. After successfully making the purchase, a receipt will be generated and will reflect the relevant transaction.

The way it works is a Cashier will be assigned to an available register which will be able to keep track of a list of items ready for 'purchase' as well as its running balance. All products available for purchase are held in a faux database that would theoretically periodically change to list new products, remove old products, and or change the prices to existing products. The Cashier adds all relevant items and prices to complete the transaction and finally 'accepts' proper payment while 'handing back' proper change. The final list of sold items with listed relevant information is generated as a receipt.
