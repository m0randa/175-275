//
//  main.c
//  hw3p2
//
//  Created by Miranda Hampton on 2/5/17.
//  Copyright © 2017 Miranda. All rights reserved.
// inputs: the user inputs the coefficients of an equation, and their initial guess for x
// outputs: the code uses a for loop to determine a root of the polynomial or to determine if the roots are complex
// Using the equations of Newton-Raphson Method, we are able to easily discover the root of the polynomial.
//
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void){
    double c5; //variables had to be double because using the power function made them to great.
    double c4;
    double c3;
    double c2;
    double c1;
    double c0;
    double x;
    double y = 0;
    double y1;
    int i = 0;
    
    printf("This program is to find one root of 5th-order polynomial using Newton-Rhapson method.\n c5x^5 + c4x^4 + c3x^3 + c2x^2 + c1x + c0\n Enter polynomial coefficients: c5 c4 c3 c2 c1 c0 in this order:\n");
    scanf("%lf%lf%lf%lf%lf%lf", &c5, &c4, &c3, &c2, &c1, &c0);
    printf("Your polynomial is ");
    if (c5 != 0){
        printf("%.1fx^5 + ", c5);}
    if (c4 != 0){
        printf("%.1fx^4 + ", c4);}
    if (c3 != 0){
        printf("%.1fx^3 + ", c3);}
    if (c2 != 0){
        printf("%.1fx^2 + ", c2);}
    if (c1 != 0){
        printf("%.1fx + ", c1);}
    if (c0 != 0){
        printf("%.1f\n", c0);}
    
    printf("Enter initial guess for x:");
    scanf(" %lf" , &x);
    
    y = (c5 * pow(x,5)) + (c4 * pow(x,4)) + (c3 * pow(x,3)) + (c2 * pow(x,2)) + (c1 * x) + (c0);
   
    while ((y >= 0.00000001 || y <= -0.00000001) && (i <= 500)){
        y1 = (5 * c5 * pow(x,4)) + (4 * c4 * pow(x,3)) + (3 * c3 * pow(x,2)) + (2 * c2 * x) + (c1); // derivative of y
        if(y1 != 0){ //the equation cannot be divided by zero, so when y1 = 0 x never changes, but i continues to grow until >500
        x = x - (y / y1);
        }
        i = i +1; // number of iterations
        y = (c5 * pow(x,5)) + (c4 * pow(x,4)) + (c3 * pow(x,3)) + (c2 * pow(x,2)) + (c1 * x) + (c0); //new y value
        }
    
    if(i <500){
        printf("One of the roots of this polynomial is %f\n", x);
        printf("It takes %d iterations to obtain this answer." , i);
    }
    else {
    printf("The algorithm failed; roots may be complex\n");
    }

return(0);
        
}
