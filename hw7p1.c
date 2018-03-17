//
//  main.c
//  tictactoe
//
//  Created by Miranda Hampton on 3/7/17.
//  inputs: person playing against computer inputs the coordinates they want X to go.
//  outputs: The computer inputs an O and the board is printed
//  Interactive tic tac toe game against the computer. 
//

#include <stdio.h>
#define X 'X'
#define O 'O'
#define E ' '

int check_board(int x[][3]){
    int i;
    int j;
    int tie = 0;
    
    for(i=0; i<3; ++i){
        for(j=0; j<3;j++)
            tie = tie + x[i][j];
        if(x[i][0] + x[i][1] + x[i][2] == X + X + X || x[0][i] + x[1][i] + x[2][i] == X + X + X || x[0][0] + x[1][1] + x[2][2] == X + X + X || x[0][2] + x[1][1] + x[2][0] == X + X + X){
            return 0;
        }
        else if(x[i][0] + x[i][1] + x[i][2] == O + O + O || x[0][i] + x[1][i] + x[2][i] == O + O + O || x[0][0] + x[1][1] + x[2][2] == O + O + O || x[0][2] + x[1][1] + x[2][0] == O + O + O){
            return 1;
        }
        else if(tie == X + X + X + X + X + O + O + O + O)
            return 2;
    }
    return 3;
}


int computerO(int x[][3]){
    int i;
    for(i =0; i<3; ++i){//checks to see if it can win
        if(x[i][0] + x[i][1] + x[i][2] == E + O + O){
            if(x[i][0] == E){
                x[i][0] = O;
                printf("The computer entered a 'O'at position: %d 0\n", i);
            }
            else if(x[i][1] == E){
                x[i][1] = O;
                printf("The computer entered a 'O'at position: %d 1\n", i);}
            else if(x[i][2] == E){
                x[i][2] = O;
                printf("The computer entered a 'O'at position: %d 2\n", i);}
            return 1;
        }
        else if(x[0][i] + x[1][i] + x[2][i] == E + O + O){
            if(x[0][i] == E){
                x[0][i] = O;
                printf("The computer entered a 'O'at position: 0 %d\n", i);}
            else if(x[1][i] == E){
                x[1][i] = O;
                printf("The computer entered a 'O'at position: 1 %d\n", i);}
            else if(x[2][i] == E){
                x[2][i] = O;
                printf("The computer entered a 'O'at position: 2 %d\n", i);}
            return 1;
        }
        else if(x[0][0] + x[1][1] + x[2][2] == E + O + O){
            if(x[0][0] == E){
                x[0][0] = O;
                printf("The computer entered a 'O'at position: 0 0\n");}
            else if(x[1][1] == E){
                x[1][1] = O;
                printf("The computer entered a 'O'at position: 1 1\n");}
            else if(x[2][2] == E){
                x[2][2] = O;
                printf("The computer entered a 'O'at position: 2 2\n");}
            return 1;
        }
        else if(x[0][2] + x[1][1] + x[2][0] == E + O + O){
            if(x[0][2] == E){
                x[0][2] = O;
                printf("The computer entered a 'O'at position: 0 2\n");}
            else if(x[1][1] == E){
                x[1][1] = O;
                printf("The computer entered a 'O'at position: 1 1\n");}
            else if(x[2][0] == E){
                x[2][0] = O;
                printf("The computer entered a 'O'at position: 2 0\n");}
            return 1;
        }
    
    }   //end of checking for OO
    if(check_board(x) != 0){//checks to see it can block opponent
    for(i =0; i<3; ++i){
        if(x[i][0] + x[i][1] + x[i][2] == E + X + X){
            if(x[i][0] == E){
                x[i][0] = O;
                printf("The computer entered a 'O'at position: %d 0\n", i);}
            else if(x[i][1] == E){
                x[i][1] = O;
                printf("The computer entered a 'O'at position: %d 1\n", i);}
            else if(x[i][2] == E){
                x[i][2] = O;
                printf("The computer entered a 'O'at position: %d 2\n", i);}
            return 2;
        }
        else if(x[0][i] + x[1][i] + x[2][i] == E + X + X){
            if(x[0][i] == E){
                x[0][i] = O;
                printf("The computer entered a 'O'at position: 0 %d\n", i);}
            else if(x[1][i] == E){
                x[1][i] = O;
                printf("The computer entered a 'O'at position: 1 %d\n", i);}
            else if(x[2][i] == E){
                x[2][i] = O;
                printf("The computer entered a 'O'at position: 2 %d\n", i);}
            return 2;
        }
        else if(x[0][0] + x[1][1] + x[2][2] == E + X + X){
            if(x[0][0] == E){
                x[0][0] = O;
                printf("The computer entered a 'O'at position: 0 0\n");}
            else if(x[1][1] == E){
                x[1][1] = O;
                printf("The computer entered a 'O'at position: 1 1\n");}
            else if(x[2][2] == E){
                x[2][2] = O;
                printf("The computer entered a 'O'at position: 2 2\n");}
            return 2;
        }
        else if(x[0][2] + x[1][1] + x[2][0] == E + X + X){
            if(x[0][2] == E){
                x[0][2] = O;
                printf("The computer entered a 'O'at position: 0 2\n");}
            else if(x[1][1] == E){
                x[1][1] = O;
                printf("The computer entered a 'O'at position: 1 1\n");}
            else if(x[2][0] == E){
                x[2][0] = O;
                printf("The computer entered a 'O'at position: 2 0\n");}
            return 2;
        }
        
    }
    //end of checking to block player 1
        //places O in random spot depending on whats empty
        if(x[1][1] == E){
        x[1][1] = O;
            printf("The computer entered a 'O'at position: 1 1\n");}
        else if(x[0][0] == E){
        x[0][0] = O;
            printf("The computer entered a 'O'at position: 0 0\n");}
        else if(x[0][2] == E){
        x[0][2] = O;
            printf("The computer entered a 'O'at position: 0 2\n");}
        else if(x[2][0] == E){
        x[2][0] = O;
            printf("The computer entered a 'O'at position: 2 0\n");}
        else if(x[0][1] == E){
        x[0][1] = O;
            printf("The computer entered a 'O'at position: 0 1\n");}
        else if(x[2][1] == E){
        x[2][1] = O;
            printf("The computer entered a 'O'at position: 2 1\n");}
        else if(x[1][0] == E){
        x[1][0] = O;
            printf("The computer entered a 'O'at position: 1 0\n");}
        else if(x[1][2] == E){
        x[1][2] = O;
            printf("The computer entered a 'O'at position: 1 2\n");}
    }
    return 3;
}

void player1(int x[][3]){
    int x1;
    int x2;
    
    printf("Player 1, enter an 'X' :\n");
    scanf("%d %d", &x1, &x2);
    if(x[x1][x2] != E){
        printf("Error. Try Again.\n");
        player1(x);
    }
    else{
        x[x1][x2] = X;
    }
    
}

void print_board(int x[][3]){
    
    printf(" %c | %c | %c\n", x[0][0], x[0][1], x[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", x[1][0], x[1][1], x[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", x[2][0], x[2][1], x[2][2]);
    
}

int main(void){
    int x[3][3];
    char name[20] = "";
    int i;
    int j;
    int turn;
    int win =3;
    
    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j){
            x[i][j] = E;
        }
    }
    
    printf("Player 1 enter your name: ");
    scanf(" %s", name);
    printf(" %s, Let's play tic tac toe:\n", name);
    
    print_board(x);
    while(win == 3){
        for(turn =1; turn <10; turn++){
            if(turn%2 == 1){
                player1(x);
                print_board(x);
                win = check_board(x);
                
            }
            else if(turn%2 == 0){
                computerO(x);
                print_board(x);
                win = check_board(x);
                
            }
            else if(turn == 9){
                print_board(x);
                win = check_board(x);
            }
            if(win < 3)
                break;
        }
   
}
    if(win == 0)
        printf(" %s wins\n", name);
    else if(win == 1)
        printf("Computer wins\n");
    else if(win == 2)
        printf("Tie\n");
    
    return (0);
}

