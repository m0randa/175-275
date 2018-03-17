//
//  main.c
//  hw3p1
//
//  Created by Miranda Hampton on 2/5/17.
//  Copyright © 2017 Miranda. All rights reserved.
//inputs: user inputs a number, and a letter based on if they want to continue or not
//outputs: The user is told if thier number is a perfect number or not
// WHen the number is inputted, the code finds all the divisors of the number, then adds them together and compares the total to the
// original number. If the numbers are the same, the number is perfect. The user is then asked if they want to continue
// if they say yes, it repeats, if they say no the code terminates and says Goodbye.

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int num;
    int div;
    int i;
    int j;
    int total;
    char letter = 'y';
    
    while(letter != 'n'){
        printf("Enter a perfect number:\n");
        scanf(" %d", &num);
        j = 0;
        total = 0;
        for(i = 1; i <= (num/2); ++i){
            div = num%i;
            if (div == 0){
                total = total + i; //adds all the divisors together
            }
        j= j +1; //counts number of iterations
        }
        if (total == num){
            printf("Number %d is perfect\n" , num);
        }
        else{
            printf("Number %d is not perfect\n", num);
        }
        printf("Number of iterations: %d\n", j);
        printf("Do you want to continue (y/n)?");
        scanf(" %c", &letter);
    }
    printf("Goodbye");
    return(0);
}
