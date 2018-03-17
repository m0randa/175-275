//
//  main.c
//  game of life
//
//  Created by Miranda Hampton on 3/20/17.
//  inputs: a world file, and a letter to continue or not
//  outputs: the evolution of the world
//  This code reads a file with a world and then evolves it into a new world.
//  If an organism (*) touches less than 2 or more than 3 other organisms, it dies
//  If an organism touches exactly 2 or 3, it lives.
//  If a blank space touches three organisms, a new organism comes to life
//

#include <stdio.h>
#include <string.h>
#define SIZE 10
#define ALIVE 1
#define DEAD 0

void read_world(FILE *inp, int x[ ][SIZE]){    //reads a world from a file to array x
    int i;
    int j;
    char num;
    
    for(i =0; i<SIZE; i++){
        for(j=0; j<SIZE;j++){
            fscanf(inp, " %c", &num);
                if(num == '0')
                    x[i][j] = DEAD;
                else
                    x[i][j] = ALIVE;
            
            }
        }
    }


void print_world(int x[ ][SIZE]){// prints world stored in array x on screen
    int i,j;
    
    for(i =0; i<SIZE; i++){
        for(j=0; j<SIZE;j++){
            if(x[i][j] == ALIVE)
              printf("* ");
            else
                printf("0 ");
            if(j == 9)
                printf("\n");
            if(i == 9 && j ==9)
                printf("\n");
        }
    }
}


int evolve(int x[ ][SIZE], int row, int col){// returns the evolved cell value for cell x[row][col]
    int i;
    int j;
    int sum = 0;
    
    if(row == 0 || row == 9 || col == 0 || col == 9)
        return DEAD;
    if(x[row][col] == 1){
        for(i = row -1; i<= row +1; i++){
            for(j=col -1; j<= col+1;j++){
                    sum = sum + x[i][j];}}
        sum = sum -1;
        if(sum < 2 || sum > 3)
            return DEAD;
        else if(sum == 2 || sum ==3)
            return ALIVE;
    }
    else{
        //if(x[row-1][col-1]+x[row-1][col]+x[row-1][col+1]+x[row][col-1]+x[row][col+1]+x[row+1][col-1]+x[row+1][col]+x[row+1][col+1] == 3)
        for(i = row -1; i<= row +1; i++){
            for(j=col -1; j<= col+1;j++){
                sum = sum + x[i][j];}}
        if(sum ==3)
            return ALIVE;
    }
return 0;
}

void copy_world(int x[ ][SIZE], int y[ ][SIZE]){// copies world in x to y
    int i,j;
    for(i =0; i<SIZE; i++){
        for(j=0; j<SIZE;j++){
            y[i][j] = x[i][j];
        }
    }
}


int extinct(int x[][SIZE]){// returns a zero if all organisms are extinct
    int i,j;
    int num =0;
    for(i =0; i<SIZE; i++){
        for(j=0; j<SIZE;j++){
            num = num + x[i][j];
        }
    }
    if(num == 0)
        return DEAD;
    
return ALIVE;
}

int main(void){
    int old[10][10];
    int new[10][10];
    int j;
    int i;
    char ans = 'n';
    FILE* inp = fopen("world.txt", "r");
    
    read_world(inp,new);
    
    while(ans != 'q'){
        print_world(new);
        
        copy_world(new, old);
        
        for(i =0; i<SIZE; i++){
            for(j=0; j<SIZE;j++){
                new[i][j] = evolve(old, i, j);
            }
        }
        print_world(new);
        
        if(extinct(new) == DEAD){
            printf("Population extinct\n");
            break;
        }
        /*if(memcmp(new, old, sizeof(new)) == 0){ //COMPARES TWO ARRAYS TO SEE IF THEY'RE THE SAME
            printf("No further evolution\n");
            break;}*/
        
        
        
        printf("Would you like to continue (q to quit)?");
        scanf(" %c", &ans);
    }
}
