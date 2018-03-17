//----------------------------------------------------------------------//
// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           8/24/2017
// Project Number: 0
// Project Name:   ececms
//
// Contains the main function.
//----------------------------------------------------------------------//

#include "item.h"
#include <string.h>

/**
 * description: Creates a new item struct and returns it
 *
 * @requirement returns item with blank (strlen returns 0) name and 0.0 price if parameter price is negative
 * @requirement returns item with blank (strlen returns 0) name and 0.0 price if parameter name is blank
 * @param name is the name of the product
 * @param price is the price in USD
 * @return the new item struct
 */
item createItem(char name[], double price){
    
    item newItem;
    return newItem;
}

/**
 * description: Calculates the total price of all items in an array.
 *
 * @requirement returns -1 if total is negative or if an item's name is blank
 * @param items is an array of item structs
 * @param numItems is the number of items in the items array
 * @return the total price
 */
double calculateTotal(item items[], int numItems){
    return 0.0;
}
