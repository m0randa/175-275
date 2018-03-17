//
//  main.c
//  hw6p2
//
//  Created by Miranda Hampton on 3/6/17.
//  inputs: two txt files
//  outputs: the mean of the numbers from text 1, and from txt 2. The standard deviation from both, and the corelation between the two.

//  The code takes a list of 500 numbers and stores them into an array. Using different functions the mean is calcualted and the standradr deviation is calcualted. Then the correlation is calcualted using the mean and the standard deviation
//

#include <stdio.h>
#include <math.h>
#define size 500

void read_file(FILE *inp, double z[], int length){
    int i=0;
    double val;
        while((fscanf(inp, "%lf", &val)!= EOF) && i< length){
            z[i] = val;
            i++;
        }
    return;
}
void calc_mean(int length, double z[], double *mean){
    int i =0;
    double total = 0;
    for(i = 0;i<length; ++i){
        total = total + z[i];
        *mean = total / length;
    }
    return;
}

void calc_std(int length, double z[], double *std){
    int i;
    double val1 =0;
    double val2 = 0;
    
    for(i=0;i<length;++i){
        val1 = val1 + pow(z[i],2);
        val2 = val2 + z[i];
    }
    *std = sqrt((val1/500)-(pow((val2/500),2)));
    return;
}

int main(void){
    FILE* inp1 = fopen("f1.txt", "r");
    FILE* inp2 = fopen("f2.txt", "r");
    double x[size];
    double y[size];
    int length = size;
    double mean1;
    double mean2;
    double std1 = 0;
    double std2 = 0;
    double corr = 0;
    
    read_file(inp1,x,length);
    read_file(inp2, y, length);
    
    calc_mean(length,x, &mean1);
    calc_mean(length, y, &mean2);
    
    calc_std(length,x, &std1);
    calc_std(length, y, &std2);
  
    for(int i=0; i<length; ++i){
        corr = corr + ((x[i]-mean1)*(y[i]-mean2)/(500*std1*std2));
    }
    
    printf("Mean of data in f1.txt is %.5lf\n", mean1);
    printf("Mean of data in f2.txt is %.5lf\n", mean2);
    printf("Standard deviation of data in f1.txt is %.5lf\n", std1);
    printf("Standard deviation of data in f2.txt is %.5lf\n", std2);
    printf("The correlation is %.5lf\n", corr);
    
    fclose(inp1);
    fclose(inp2);
    
    return(0);
}
