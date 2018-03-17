//
//  main.c
//  hw2p3.c trial 2
//
//  Created by Miranda Hampton on 1/30/17.
//  Inputs: 13 digit ISBN number
//  Outputs: Whether the code is valid or not
//  The user can enter any 13 digit code and see if it is a valid code by multiplying the numbers by 1 and 3 consequtively.
//
//
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void){
    long long int i;
    long long int total;
    long long int isbn;
    long long int d13;
    
    printf("Enter a 13-digit ISBN code:\n");
    scanf("%lld" , &isbn);
    
    for(i=12; i>=1; --i){
        if (i%2 == 1){
            total = total + (3 * (isbn / (long long int)(pow(10,i))));
        }
        else {
            total = total + (isbn / (long long int)(pow(10,i)));
        }
        isbn = isbn%(long long int)(pow(10,i));
    }
    
    d13 = isbn%10;
    
    total = total%10;
    total = 10 - total;
    printf("10-(%lld%%10)=%lld",total, d13);
    
    if (total == 10 && d13 ==0){
        printf("This is a valid isbn code.\n");
    }
    else if (total != d13){
        printf("This is not a valid isbn code.\n");
    }
    else{
        printf("This is a valid isbn code.\n");
    }
    
return(0);
    
}
