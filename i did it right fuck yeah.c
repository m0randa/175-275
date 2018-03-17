//
//  main.c
//  that one test question
//
//  Created by Miranda on 2/28/17.
//  Copyright © 2017 Miranda. All rights reserved.
//

#include <stdio.h>

void square(int side){
    FILE *outp;
    
    outp= fopen("square.txt", "w");
    for(int i=1; i<= side; ++i){
        if(i == 1 || i ==side){
            fprintf(outp, "|");
            for(int j =1; j<=side; ++j){
                fprintf(outp, "-");
            }
            fprintf(outp, "|\n");
            }
        if(i<side && i>1){
            fprintf(outp,"|");
            for(int j =1; j<=side; ++j){
                fprintf(outp, " ");
            }
            fprintf(outp, "|\n");
        }
        }
    fclose(outp);
    
    }


int main(void){
    int side;
    
    printf("Enter a side length: ");
    scanf(" %d", &side);
    
    square(side);
}

