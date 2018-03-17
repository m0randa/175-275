//
//  main.c
//  homework 2
//
//  Created by Miranda Hampton on 1/28/17.
//  inputs: Your passanger class and how much your luggage weighs
//  outputs: How much luggage will cost
//  when you imput the class and the luggage weight, based on the cost per amount it weighs and per class, you will get the total you have to pay.
//

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void){
    char letter;
    float lug;
    float cost;
    
    
    printf("Enter Passanger Class (E for Economy, B for Business, V for VIP):\n");
    scanf("%c", &letter);
    
    printf("Enter luggage weight:\n");
    scanf("%f", &lug);
    
    switch (letter){
        case 'E':
            if (lug < 25){
                printf("Total cost is $0.00\n");
            }
            else if (lug >= 25 && lug <= 40){
                cost = 1.5 * (lug - 25);
                printf("Total cost is $%.2f\n", cost);
            }
            else{
                cost =  22.5 + (2 * (lug - 40));
                printf("Total cost is $%.2f\n", cost);
            }
            break;
        case 'B':
            if (lug < 35){
                printf("Total cost is $0.00\n");
            }
            else if (lug >= 35 && lug <= 50){
                cost = 1.25 * (lug - 35);
                printf("Total cost is $%.2f\n", cost);
            }
            else{
                cost = 18.75 + (1.5 * (lug - 50));
                printf("Total cost is $%.2f\n", cost);
            }
            break;
        case 'V':
            if (lug < 60){
                printf("Total cost is $0.00\n");
            }
            else{
                cost = 30;
                printf("Total cost is $%.2f\n", cost);
            }
            break;
        default :
            printf("Wrong Passenger class\n");
            break;
    }
    
            return(0);
    }
