//
//  main.c
//  hw1p1.c
//
//  Created by Miranda Hampton on 1/23/17.
//  Copyright © 2017 Miranda. All rights reserved.
/* In this program the user imputs the length and width of a room, the length of a tile, price of a tile and sales tax. The user will then recieve the area of the room, the number of tiles they need to fill the room, the price of all the tiles, and the total cost of all the tiles plus tax. */

#include <stdio.h>
#include <math.h>

int main(void){
    
    float lRoom;        //variable for the length of the room
    float wRoom;        //variable for the width of the room
    float lTile;        //variable for the length of one tile
    float priceTile;    //variable for the price of the tile
    float tax;          //variable for the sales tax for final price
    float total;        //variable for the total amount of each needed
    /* All of them are floats because decimal numbers need to be imputted at different times*/
    
    printf("Enter length of the room in inches:\n");    //This prints the phrase Enter length of the room in inches:
    scanf("%f", &lRoom);                                //scans users input and stores in lRoom variable
    
    printf("Enter width of the room in inches:\n");     //prompts user for width of room
    scanf("%f", &wRoom);                                //scan users input and stores in wRoom variable
    
    printf("Enter length of one side of a single tile in inches:\n");       //prompts user for length of a tile side
    scanf("%f", &lTile);                                  //scans users input and stores in lTile variable
    
    printf("Enter price per tile in dollars:\n");       //prompts user for price
    scanf("%f", &priceTile);                            //scans user input and stores in priceTile variable
    
    printf("Enter percent sales tax:\n");               //prompts user for percent tax
    scanf("%f", &tax);                                  //scans users input and stores in tax variable
    
    total = lRoom * wRoom;                              //equation to find total area of the room
    printf("The total area to be tiled is %.0f square inches.\n", total);   /*calculates and prints total area
                                                                             of the room using %.0f to place the stored amount with 0 decimals*/
    
    total = ceil((lRoom) / (lTile)) * ceil((wRoom) / (lTile));  /* equation to find the total amount of tiles
                                                                 needed. ceil is used because we want the
                                                                 largest whole number for number of tiles
                                                                 because we need to buy whole tiles. */
    
    printf("The total number of tiles to be purchased is %.0f\n", total); /*calculates and prints total tiles
                                                                           used with no decimals*/
    
    total = total * priceTile;          //equation to find the total price of all the tiles
    printf("The cost of the purchase before tax is $%.2f\n", total);    /*prints the cost with two decimals
                                                                         places*/
    
    total = total + (total * (tax / 100));          // equation to find the total amoutn with tax
    //tax is divided by 100 because the tax is given in percent
    
    printf("The cost of the purchase including tax is %.2f.\n", total); /*prints the total cost with tax with 2
                                                                         decimal places*/
    
    
    
    return(0);
    
    
}


