//
//  main.c
//  hw8p2.c
//
//  Created by Miranda Hampton on 3/23/17.
//  inputs: word search file, and the word you want to find
//  outputs: how many times that word occurs in the file, and where
//  The code will scan a file, then ask the user for a word (in all caps),
//  It will then search the file to see if that word is in the word search.
//  If it is, it will tell you which line and how many times it occurs, then show you the line
//  If it doesn't, then it will tell you the word isn't in the FILE.
//
//

#include <stdio.h>
#include <string.h>

int search_current_line(char Line_str[], char word[]){
    int num =0;
    char *sub;
    char *sub1;
    sub = Line_str;
    sub1 = word;
    while((sub = strstr(sub, sub1)) != NULL){
        num++;
        sub++;
    }
    return num;
}
int main(void){
    FILE* inp = fopen("DataFile.txt", "r");
    char word[20] = "";
    char line[101] = "";
    int num=0;
    int i=0;
    int j= 0;
    int k =0;
    char ans = 'y';
    while(ans != 'q'){
        printf("Enter a word you want to search for: ");
        scanf(" %s", word);
        i=0;
        j=0;
        k =0;
        while((fgets(line, 101, inp))!= NULL){
            i++;
            num = search_current_line(line, word);
            if(num != 0){
                printf("Found %s %d times on line %d\n", word, num, (i+1)/2 );
                printf("The line is: %s\n", line);
                k = k+ num;
            }
            else{
                j = j+1;
            }
        }
        if(j == 402)
            printf("The string: \"%s\" was NOT found in the puzzle.\n", word);
        else
            printf("The string: \"%s\" was found a total of %d times in the puzzle.\n", word, k);
        rewind(inp);
        printf("Do you want to search another word (q to quit)?");
        scanf(" %c", &ans);
    }
    fclose(inp);
    return (0);
}

