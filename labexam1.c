//
//  main.c
//  lab practical
//
//  Created by Miranda Hampton on 3/2/17.
//
//Lab Practical

#include <stdio.h>

int gcd(int x, int y){
    int rem =1, gcd =0;
    
    if(x==0)
        gcd=y;
    else if(y==0)
        gcd=x;
    else{
        while(rem!=0){
            gcd=y;
            rem=x%y;
            x=y;
            y=rem;
        }
    }
    return gcd;
}

void commonDivisor(int num, int* max_pt, FILE* outp){
    int div;
    int i;
    
    
    fprintf(outp, "\n%d\t\t", num);
    for(i=1; i<num; ++i){
        div = gcd(num, i);
        if(div != 1){
            fprintf(outp, "%d ", i);
            if(*max_pt<i){
                *max_pt = i;}}
        }
    
        }
    
    int main(void){
        FILE* inp;
        FILE* outp;
        int num;
        int maxVal = 0;
        
        inp = fopen("data.txt", "r");
        outp = fopen("output.txt", "w");
        
        fprintf(outp, "Value\tNumbers\n");
        while(fscanf(inp, "%d", &num)!=EOF){
            commonDivisor(num, &maxVal, outp);
            
        }
        fprintf(outp, "\nThe maximum value of all numbers found is %d", maxVal);
        fclose(inp);
        fclose(outp);
    }

