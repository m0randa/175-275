//
//  main.c
//  hw6p1
//
//  Created by Miranda Hampton on 3/6/17.
//  inputs: user inputs loan amount, the annual percentage rate, and the monthly payment amount.
//  outputs: The code calcualtes how long the loan will be paid off, within a 35 year window, how much over you paid with your last payment, and how much total you spent. 
//
//  This code will take the user's inputs and then calculate the amount of money due. There's a counter to count the days, and as it increases the amount owed become greater becasue of interest, but on the last day of the month the monthly payment is dededucted. Code continues until amount due is less than 0.
//

#include <stdio.h>
#include <math.h>

const double e = 2.71828182845905;

int main(void){
    int i;
    int counter=1;
    double monthly;
    double todaysP =0;
    double amountOwed[12784];
    double amountPayed[12784];
    double time[12784];
    double r; //interest rate
    double APR; //annual percentage rate
    
    for(i=0; i<12784; ++i)
        time[i] =0;
    for(i=0; i<12784; ++i)
        amountPayed[i]=0;
    for(i=0; i<12784; ++i)
        amountOwed[i]=0;
    
    printf("Enter in the total loan amount: ");
    scanf("%lf", &amountOwed[0]);
    printf("\nEnter in the Annual Percentage Rate (APR) %%: ");
    scanf("%lf", &APR);
    printf("\nEnter in the monthly payment amount: ");
    scanf("%lf", &monthly);
    
    r = (APR) / (100 * 365.242);
    for(i=1; i<=12784; ++i){
        if(counter<30){
            todaysP = 0;
            counter++;
        }
        else if(counter>= 30){
            todaysP = monthly;
            counter =1;
        }
        amountOwed[i] = (amountOwed[i-1]*(pow(e,r)))-todaysP;
        amountPayed[i] = amountPayed[i-1]+todaysP;
        time[i] = i / 365.242;
        if(amountOwed[i] <= 0)
            break;
        }
    
    printf("Total loan amount = $%.2lf\n", amountOwed[0]);
    printf("Annual Percentage Rate (APR) is %%%.2lf\n", APR);
    printf("Monthly payment amount = $%.2lf\n", monthly);
    printf("After %.3lf years: you will owe $%.2lf : The total payout is $%.2lf\n", time[i],amountOwed[i], amountPayed[i]);
    
    return(0);
    
}
