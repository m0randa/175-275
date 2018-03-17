//
//  main.c
//  Labexam2.c
//
//  Created by Miranda Hampton on 4/20/17.
//  Copyright © 2017 Miranda. All rights reserved.
//

#include <stdio.h>
typedef struct song_t{
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int duration;
}song;

song readSong(FILE *inp);
void printSong(song *s);
void searchSong(song x[], int size, int duration);

int main(void){
    FILE *inp;
    char ans = 'y';
    int counter=0, i=0;
    char temp[50];
    int duration;
    song *arr, *pt;
    
    inp = fopen("songs.txt", "r");
    while(fgets(temp, 50, inp) != NULL)
        counter++;
    
    rewind(inp);
    
    pt = (song*)calloc(sizeof(song), counter/5);
    arr = pt;
    while(inp != EOF && i< counter/5){
        if(i==0)
            arr[i] = readSong(inp);
        else
            arr[i] = readSong(inp);
        i++;
    }
    while(ans != 'n'){
    printf("please enter a minimum song duration in minutes:\n");
    scanf(" %d", &duration);
    searchSong(arr, counter/5, duration);

        printf("Would you like to search for another song? (press n to quit)\n");
        scanf(" %c", &ans);
    }
}

song readSong(FILE *inp){
    song temp;
    if(inp ==NULL)
        printf("This file does not exist.");
    else{
        fgets(temp.title, 100, inp);
        fgets(temp.artist, 100, inp);
        fgets(temp.album, 100, inp);
        fscanf(inp, " %d ", &temp.year);
        fscanf(inp, " %d ", &temp.duration);
        }
    return temp;
}
void searchSong(song x[], int size, int duration){
    int i=0;
    int counter=0;
    int sec;
    
    sec = duration* 60;
    
    for(i=0; i<size; i++){
        if((x[i]).duration >= sec){
        printSong(&x[i]);
        counter++;
    }
    }
    if(counter == 0)
         printf("There are no songs equal or greater than %d minutes\n", duration);
}

void printSong(song *s){
    int min;
    int sec;
    min = s->duration /60;
    sec = s->duration %60;
    if(sec < 10)
        printf("%s%s%s%d\n%d:0%d\n\n", s->title, s->artist, s->album, s->year, min, sec);
    else
        printf("%s%s%s%d\n%d:%d\n\n", s->title, s->artist, s->album, s->year, min, sec);
}

