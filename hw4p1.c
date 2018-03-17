//
//  main.c
//  hw4p1
//
//  Created by Miranda Hampton on 2/13/17.
//  inputs: user inputs which function they want to use then inputs an X Value
//  output: An answer for the function they chose calculated with the X value they input. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(int n){
    double product = 1.0;
    int i;
    for (i =2; i<=n; i++){
        product = product *i;
    }
    
    return product;
}

double my_cosh(double realValX){        //cosh function
    double realValY = 0.0;
    double j;
    
    for (int n = 0; n <40; n =n+2){     //for loop to determine n
        double i = n;
        for(j = 1; i != 0; --i)         //calculating the exponent
            j = j * realValX;
        realValY = realValY + ((j) / factorial(n));
    }
    
    return realValY;
}

double my_sinh(double realValueX){      //sinh function
    double realValY = 0.0;
    double j;
    
    for (int n = 1; n < 40; n = n+2){   //loop to calculate n
        double i = n;
        for(j = 1; i != 0; --i)         //for loop for exponents
            j = j * realValueX;
        realValY = realValY + ((j) / factorial(n)); // exquations for sinh
    }
    
    return realValY;
}

int main(void){
    int option;
    double xVal;
    double answer;
    char letter = 'y';
   
    while(letter != 'q'){
        option = 0;
        
        while(option >4 || option <1){
            printf("Option\tFunction\n1\t\tsinh(x)\n2\t\tcosh(x)\n3\t\tsinh(2x)\n4\t\tcosh(2x)\n");
            printf("\nEnter 1-4:\n");
            scanf("%d" , &option);
        }
        printf("Enter value of x:\n");
        scanf("%lf", &xVal);
        
        switch(option){
            case 1:
                answer = my_sinh(xVal);
                printf("sinh(%.3lf) = %.5lf\n" , xVal, answer);
                break;
                
            case 2:
                answer = my_cosh(xVal);
                printf("cosh(%.3lf) = %.5lf\n" , xVal, answer);
                break;
                
            case 3:
                answer = 2 * my_sinh(xVal) * my_cosh(xVal);
                printf("sinh(%.3lf) = %.5lf\n" , (xVal*2), answer);
                break;
                
            case 4:
                answer = (2 * (my_sinh(xVal)*my_sinh(xVal))) +1;
                printf("cosh(%.3lf) = %.5lf\n" , (xVal*2), answer);
                break;
        }
        
        printf("Do you want to continue (q to quit)?");
        scanf(" %c", &letter);
    }
    return (0);
    
}

