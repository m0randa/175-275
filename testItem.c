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
#include "testItem.h"
#include <string.h>

void runTests(){
    testCreateItem();
    testItemPriceIsPositive();
    testTotalOneItem();
    testTotalTwoItems();
    testNegativeTotal();
}

/*
 * @requirement pass if all items are set to correct values
 * @return pass: 1, fail: 0
 */
unsigned int testCreateItem(){
    item test = createItem("Toy", 10.0);
    if(strcmp(test.name, "Toy") != 0 || test.price != 10.0){
        printf("CreateItem failed\n");
        return 0;
    }
    else{
        printf("CreateItem passed\n");
        return 1;
    }
}

/*
 * @requirement pass if the name of the item returned is blank (strlen is 0) and price is 0.0 when name passed to createItem is blank
 * @return pass: 1, fail: 0
 */
unsigned int testItemNameIsBlank(){
    item test = createItem("", 1.0);
    if(strlen(test.name) != 0 || test.price != 0.0){
        printf("ItemNameBlank failed\n");
        return 0;
    }
    else{
        printf("ItemNameBlank passed\n");
        return 1;
    }

}

/*
 * @requirement pass if the name of the item returnd is blank (strlen is 0) and price is 0.0 when price passed to createItem is negative
 * @return pass: 1, fail: 0
 */
unsigned int testItemPriceIsPositive(){
    item test = createItem("", -1.0);
    if(strlen(test.name) != 0 || test.price != 0.0){
        printf("ItemPricePos failed\n");
        return 0;
    }
    else{
        printf("ItemPricePos passed\n");
        return 1;
    }
    
}

/*
 * @requirement pass if total returned from calculateTotal is correct when a single item array is passed in
 * @return pass: 1, fail: 0
 */
unsigned int testTotalOneItem(){
    item test[1];
    strcpy(test[0].name, "name");
    test[0].price = 10.0;
    
    double result = 0.0;
    result = calculateTotal(test, 1);
    if(result != 10.0){
        printf("TotalOneitem failed\n");
        return 0;
    }
    else{
        printf("TotalOneitem passed\n");
        return 1;
    }
}

/*
 * @requirement pass if total returned from calculateTotal is correct when a two item array is passed in
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testTotalTwoItems(){
    item test[2];
    strcpy(test[0].name, "name");
    test[0].price = 10.0;
    
    strcpy(test[1].name, "newname");
    test[1].price = 10.0;
    
    double result = 0.0;
    result = calculateTotal(test, 2);
    if(result != 20.0){
        printf("TotalTwoitem failed\n");
        return 0;
    }
    else{
        printf("TotalTwoitem passed\n");
        return 1;
    }
}

/*
 * @requirement pass if total returned from calculateTotal is -1.0 when the total price is negative
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testNegativeTotal(){
    item test[1];
    strcpy(test[0].name, "name");
    test[0].price = -10.0;
    
    double result = 0.0;
    result = calculateTotal(test, 1);
    if(result != -1.0){
        printf("NegItem failed\n");
        return 0;
    }
    else{
        printf("NegItem passed\n");
        return 1;
    }
}

/*
 * @requirement pass if total returned from calculateTotal is -1.0 when one item's name is blank
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testBlankItemName(){
    item test[1];
    strcpy(test[0].name, "");
    test[0].price = 10.0;
    
    double result = 0.0;
    result = calculateTotal(test, 1);
    if(result != -1.0){
        printf("BlankItem failed\n");
        return 0;
    }
    else{
        printf("BlankItem passed\n");
        return 1;
    }
}
