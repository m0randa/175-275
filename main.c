//
//  main.c
//  lab
//
//  Created by Miranda on 3/23/17.
//  Copyright © 2017 Miranda. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void){
    char longS[100] ="";
    char shortS[100]="";
    int num = 0;
    int letter;
    char *sub;
    char *sub2;

    printf("ENter a long string:");
    fgets(longS, 100, stdin);
    printf("Enter short string:");
    scanf(" %s", shortS);
    
    sub2 = longS;
    sub = shortS;
    
    while((sub2 = strstr(sub2, sub)) != NULL){
        printf("Found %s at location %i\n", shortS, sub2-longS+1);
        num = num +1;
        sub2++;
    }
    
    printf("Word occurs %d times", num);
    
    
    
    
    

}
