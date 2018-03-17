//
//  main.c
//  sudoku
//
//  Created by Miranda on 3/24/17.
//  Copyright © 2017 Miranda. All rights reserved.
//
#define E 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printBoard(int x[][9]);

int checkOK(int board[][9], int r, int row, int col){
    int i,j;
   // printBoard(board);
    if(board[row][col] != E){
        return 0;
    }
    for( i=0; i <9; ++i){
        //printf("%d x[%d][%d] = %d\n", r, i, col, board[i][col]);
        if(board[i][col] == r+1){
            return 0;
        }
    }
    
    for(j=0; j<9; ++j){
        //printf("%d x[%d][%d] = %d\n", r, row, j, board[row][j]);
        if(board[row][j] == r+1){
            return 0;
        }
    }
    if(row == 0 || row == 3 || row == 6){
        if(col == 0 || col == 3 || col ==6){
            for(i = row; i < row+2; ++i){
                for(j=col; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col ==1 || col == 4 || col ==7){
            for(i = row; i < row+2; ++i){
                for(j=col-1; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col == 2 || col ==5 || col ==8){
            for(i = row; i < row+2; ++i){
                for(j=col-2; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
    }
    else if(row == 1 || row == 4 || row == 7){
        if(col == 0 || col == 3 || col ==6){
            for(i = row-1; i < row+2; ++i){
                for(j=col; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col ==1 || col == 4 || col ==7){
            for(i = row-1; i < row+2; ++i){
                for(j=col-1; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col == 2 || col ==5 || col ==8){
            for(i = row-1; i < row+2; ++i){
                for(j=col-2; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
    }
    else if(row == 2 || row == 5 || row == 8){
        if(col == 0 || col == 3 || col ==6){
            for(i = row-2; i < row+2; ++i){
                for(j=col; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col ==1 || col == 4 || col ==7){
            for(i = row-2; i < row+2; ++i){
                for(j=col-1; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
        else if(col == 2 || col ==5 || col ==8){
            for(i = row-2; i < row+2; ++i){
                for(j=col-2; j<col+2; ++j){
                    if(board[i][j] == r+1)
                        return 0;
                }
            }
        }
    }
    
    return 1;
}


void place(int board[][9], int ans){
    int i =0;
    int j =0;
    char row;
    int col;
    
    printf("Where do you want to place the %d?", ans);
    scanf(" %c %d", &row, &col);
    i =0;
    j=0;
    if((row > 'I' && row < 'Z') || (row > 'i' && row< 'z')){
        printf("Error. Please enter a letter between A and I\n");
        place(board, ans);
    }
    else if(col > 9 || col < 1){
        printf("Error. Please enter a number between 1 and 9");
        place(board, ans);
    }
    
    
    switch (row){
        case 'A':
        case 'a':
            i = 0;
            break;
        case 'B':
        case 'b':
            i =1;
            break;
        case 'C':
        case 'c':
            i = 2;
            break;
        case 'D':
        case 'd':
            i = 3;
            break;
        case 'E':
        case 'e':
            i = 4;
            break;
        case 'F':
        case 'f':
            i = 5;
            break;
        case 'G':
        case 'g':
            i = 6;
            break;
        case 'H':
        case 'h':
            i = 7;
            break;
        case 'I':
        case 'i':
            i = 8;
            break;
    }
    j = col -1;
    if(checkOK(board, ans, i, j) == 0){
        place(board, ans);
    }
    else{
        board[i][j] = ans;
    }
}

int player(int x[][9]){
    int ans;
    
    printf("What number do you want to use?\n");
    scanf(" %d", &ans);
    
    if(ans > 9 || ans < 1){
        printf("Please use a number in between 1 and 9\n");
        player(x);
    }
    return ans;
}


void printBoard(int x[][9]){
    int i,j;
    char row = 'A';
    
    for( i=0; i <9; ++i){
        for(j=0; j<9; ++j){
            if(j ==0 && i ==0){
                printf("     1   2   3    4   5   6    7   8   9\n");
                printf("  ||===========||===========||===========||\n");
            }
            if(j == 0){
                printf("%c ", row +i);
                printf("||");
            }
            if(j != 2 && j != 5 && j!= 8){
                if(x[i][j] == E)
                    printf("   |");
                else
                    printf(" %d |", x[i][j]);
            }
            else if( j ==2 || j==5|| j==8){
                if(x[i][j] == E)
                    printf("   ||");
                else
                    printf(" %d ||", x[i][j]);
            }
            if(j==8 && i ==2)
                printf("\n  ||===========||===========||===========||\n");
            else if(j==8 && i==5)
                printf("\n  ||===========||===========||===========||\n");
            else if(j==8 && i != 8)
                printf("\n  ||---+---+---||---+---+---||---+---+---||\n");
            else if(j ==8 && i == 8)
                printf("\n  ||===========||===========||===========||\n");
        }
    }
}
void rando(int board[][9]){
    srand((int)time(NULL));
    int k;
    int r;
    int r1;
    int r2;
    
    for(k=0; k <60; ++k){
        r = rand() % 9;
        r1 = rand() % 9;
        r2 = rand() % 9;
        if(checkOK(board, r, r1, r2) == 0){
            board[r1][r2] = E;
        }
        else{
            board[r1][r2] = r+1;
        }
    }
}

int main(void){
    int board[9][9];
    int ans;
    int i, j;
    char quit = 'y';
    
    for( i=0; i <9; ++i){
        for(j=0; j<9; ++j){
            board[i][j] = E;
        }
    }
    rando(board);
    
    printBoard(board);
    while( quit != 'q'){
        ans = player(board);
        
        place(board, ans);
        printBoard(board);
        
        printf("Do you wish to continue (q to quit)?");
        scanf(" %c", &quit);
    }
    
    
    
            
            
            
        
    }

