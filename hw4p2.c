//
//  main.c
//  hw4p2
//
//  Created by Miranda Hampton on 2/13/17.
//  Inputs: Using the resistorcolor.txt file to determine the color of each resisitor
 /*ouputs: Calculates the amount of Ohm the resistor has based on color from the file and store it into another file called resistorvalue.txt.*/
//
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int col_to_num(char color, int choice){ //function to turn the color into its desired value
    int num;
    switch(color){
        case 'B':
        case 'b':
            if (choice == 1)
                num = 0;
            else if (choice == 2)
                num = 1;
            else if (choice == 3)
                num = 6;
            else
                num = 100;
            break;
            
        case 'G':
        case 'g':
            if (choice == 1)
                num = 5;
            else if (choice == 2)
                num = 8;
            else if (choice == 3)
                num = -1;
            else
                num = 100;
            break;
            
        case 'R':
        case 'r':
            if(choice == 0)
                num =2;
            else
                num =100;
            break;
        case 'O':
        case 'o':
            if(choice == 0)
                num =3;
            else
                num =100;
            break;
        case 'Y':
        case 'y':
            if(choice == 0)
                num =4;
            else
                num =100;
            break;
        case'V':
        case 'v':
            if(choice == 0)
                num =7;
            else
                num =100;
            break;
        case 'W':
        case 'w':
            if(choice == 0)
                num =9;
            else
                num =100;
            break;
        case 'S':
        case 's':
            if(choice == 0)
                num =-2;
            else
                num =100;
            break;
        default:
            num = 100;
            break;
    }
    return num;
}

int main(void){
    FILE *inp, *outp;
    char color1;
    char color2;
    char color3;
    int val1;
    int val2;
    int val3;
    int tens = 0;
    int ones = 0;
    int exp = 0;
    double tot = 0.0;
    
    
    inp = fopen("resistorcolor.txt", "r");
    outp = fopen("resistorvalue.txt", "w");
    
    if( inp == NULL){
        printf("ERROR");
    }
    else{
        while(fscanf(inp, "%c %d %c %d %c %d%*c ", &color1, &val1, &color2, &val2, &color3, &val3)!= EOF){
            fprintf(outp, "%c %d %c %d %c %d\t", color1, val1, color2, val2, color3, val3);
            tens = col_to_num(color1, val1); //calls the function
            ones = col_to_num(color2, val2);
            exp = col_to_num(color3, val3);
            if (tens == 100 || tens == -1 || tens == -2){
                fprintf(outp, "Wrong 1st color band\n");}
            else if(ones == 100 || ones == -1 || ones == -2){
                fprintf(outp, "Wrong 2nd color band\n");}
            else if(exp == 100 || exp == 7 || exp == 8 || exp == 9){
                fprintf(outp,"Wrong 3rd color band\n");}
            else{
                tot = ((tens *10) + ones) * (pow(10,exp));
                fprintf(outp,"%.2lf Ohm\n", tot);
            }
        }}
    fclose(inp);
    fclose(outp);
    return (0);
}
