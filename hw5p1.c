//
//  main.c
//  hw5p1
//
//  Created by Miranda Hampton on 2/20/17.
//  inputs: a distance in inches
//  outputs: the same distance in yards, feet, and inches
//  The users input is used to determine the number of yards, then the remain determines number of feet, and then the remaining is the number of inches.

#include <stdio.h>
void dist_conv(int d, int *p_y, int *p_f, int *p_i){ //pointers for yards, feet, and inches
    *p_y = d / 36;          //converts total inches to yards
    d = d -(*p_y *36);      //changes total inches
    *p_f = d / 12;          //converts total inches to feet
    d = d - (*p_f *12);     //changes total inches
    *p_i = d;               //assigns inches pointer to remaining inches
    
    return;
}

int main(void){
    int d;
    int in;
    int ft;
    int yd;
    
    printf("Enter the distance in inches: ");
    scanf(" %d", &d);
    
    dist_conv(d, &yd, &ft, &in); //calls function, and stores points into yd, ft, and in variables
    
    printf("%d inches equal %d yards, %d feet, and %d inches.\n", d, yd, ft, in);
    
    return(0);
}

