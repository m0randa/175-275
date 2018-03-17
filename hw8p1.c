//
//  main.c
//  hw8p1.c
//
//  Created by Miranda Hampton on 3/22/17.
//  inputs: user inputs a sentence
//  ouputs: reversed sentence and number of words words
//  The user will enter a sentence, then the computer will flip the sentence and say the words in the reverse order
//  then it will count how many words there are.
////ptm =(char*)malloc(sizeof(char));
//


#include <stdio.h>
#include <string.h>

void flip_state(char state[]){
    char newstate[100] ="";
    char *temp;
    temp = state;
    
    while((temp = strrchr(state, ' ')) != NULL){
        
            strcpy(newstate, temp+1);
            printf("%s ", newstate);
        *temp = '\0';
        
    }
    
    printf("%s\n", state);
}



int main(void){
    int i;
    char state[100] = "";
    int num =1;
    
    printf("Enter a statement: ");
    fgets(state, 100, stdin);
    for(i=0;i<100;i++){
        if(state[i] == ' '){
            ++num;
        }
    }
    
    state[strlen(state)-1] = '\0';
    flip_state(state);
    
    
    printf("There are %d words in the statement\n", num);
    
    
    return 0;

}
