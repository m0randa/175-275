//
//  main.c
//  hw2p2
//
//  Created by Miranda Hampton on 1/28/17.
//  Inputs: coordinates of the point in the center of a circle with radius 1
//  Inputs: coordinates of another point
//  Output: whether the second coordinate is inside, on, or outside the circle.
//

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void){
    float x1;
    float x2;
    float y1;
    float y2;
    char letter = 'y';
    float d; // distance
    
    while (letter != 'q'){
        printf("Enter coordinates (x1,y1):");
        scanf("%f,%f", &x1, &y1);
        printf("Enter coordinates (x2,y2):");
        scanf("%f,%f", &x2, &y2);
        
        d = sqrt((pow((x2-x1),2.0) + pow((y2-y1),2.0))); //equation to see where the second point lies
        
               if (d > 1){
            printf("(%.1f,%.1f) is outside a circle of radius 1 centered at (%.1f,%.1f)", x2,y2,x1,y1);
        }
        else if (d == 1){
           printf("(%.1f,%.1f) is on the boundary of a circle of radius 1 centered at (%.1f,%.1f)", x2,y2,x1,y1);
        }
        else {
            printf("(%.1f,%.1f) is inside a circle of radius 1 centered at (%.1f,%.1f)", x2,y2,x1,y1);
        }
        printf("Do you want to continue (q to quit)?");
        scanf(" %c", &letter);
    }
    return 0;
}
