//
//  main.c
//  old maid
//
//  Created by Miranda Hampton and ALex Reyes on 4/6/17.
//  Copyright © 2017 Miranda. All rights reserved.
//  And Alex Reyes
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct card_s {//struct for our cards
    char suit;
    int face;
    struct card_s *listp;
} card;

void createDeck(card **head);                                               //function to create the deck
void shuffleDeck(card **head);												//function to shuffle the deck
void printCards(card *head);												//function to print the cards, either with just a suit or the entire card design
void dealCards(card **user, card **comp, card *deck);						//function that deals the cards to the computer and the plaer
card *findCard(card *head, int index);										//a function that returns a card in a linked list, given the index of that card
int deckLength(card *head);													//function that finds the length of a linked list
void removePairs(card **hand);												//function that removes pairs from a deck of cards, based on card value
void removePairsHARDMODE(card **hand);                                      //function that removes pairs from a deck of cards, based on card value and color of card
void userTurn(card **comp, int length, card **user, char name[]);           //function that is called whenever it is the user's turn to play
void compTurn(card **comp, card **user, int length);						//function that is called whenever it is the computer's turn to play
void userTurnHARDMODE(card **comp, int length, card **user, char name[]);   //function that is called whenever it is the user's turn to play in hardmode
void compTurnHARDMODE(card **comp, card **user, int length);                //function that is called whenever it is the computer's turn to play in hardmode
int checkLose(card *user, card *comp);										/*function that checks to see if the game is over, returns 1 if the user loses, 2 if the
                                                                             computer loses, and 0 if no one has lost yet*/

int main(void) {
    char ans = 'y';
    char userCharacter = 'n';
    char name[20];
    int length;
    int counter = 0;
    int win = 0;
    
    while (ans != 'q') {													//while loop to keep the game going until the user enters a q
        card *deck = NULL;													//declarations of the deck, the user's hand, and the computer's hand
        card *user = NULL;
        card *comp = NULL;
        printf("Please tell me your name\n");
        scanf(" %s", name);
        length = (int)strlen(name);
        for(int i=0; i<length +34; i++){                                    //some cool text art thanks to Miranda
            printf("*");
        }
        printf("\n*   Hi %s!, Let's play old maid!   *\n", name);
        for(int i=0; i<length +34; i++){
            printf("*");
        }
        printf("\n");
        printf("Would you like to play hard mode? ;) (y or n)");
        scanf(" %c", &userCharacter);
        if (userCharacter == 'y'){
            printf(" /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$        /$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$$$\n");      //some cool text art thanks to Miranda
            printf("| $$  | $$ /$$__  $$| $$__  $$| $$__  $$      | $$$    /$$$ /$$__  $$| $$__  $$| $$_____/\n");
            printf("| $$  | $$| $$  \\ $$| $$  \\ $$| $$  \\ $$      | $$$$  /$$$$| $$  \\ $$| $$  \\ $$| $$      \n");
            printf("| $$$$$$$$| $$$$$$$$| $$$$$$$/| $$  | $$      | $$ $$/$$ $$| $$  | $$| $$  | $$| $$$$$   \n");
            printf("| $$__  $$| $$__  $$| $$__  $$| $$  | $$      | $$  $$$| $$| $$  | $$| $$  | $$| $$__/   \n");
            printf("| $$  | $$| $$  | $$| $$  \\ $$| $$  | $$      | $$\\  $ | $$| $$  | $$| $$  | $$| $$      \n");
            printf("| $$  | $$| $$  | $$| $$  | $$| $$$$$$$/      | $$ \\/  | $$|  $$$$$$/| $$$$$$$/| $$$$$$$$\n");
            printf("|__/  |__/|__/  |__/|__/  |__/|_______/       |__/     |__/ \\______/ |_______/ |________/\n");
            printf("\n /$$$$$$ /$$   /$$ /$$$$$$ /$$$$$$$$ /$$$$$$  /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$  \n");
            printf("|_  $$_/| $$$ | $$|_  $$_/|__  $$__/|_  $$_/ /$$__  $$|__  $$__/| $$_____/| $$__  $$  \n");
            printf("  | $$  | $$$$| $$  | $$     | $$     | $$  | $$  \\ $$   | $$   | $$      | $$  \\ $$   \n");
            printf("  | $$  | $$ $$ $$  | $$     | $$     | $$  | $$$$$$$$   | $$   | $$$$$   | $$  | $$  \n");
            printf("  | $$  | $$  $$$$  | $$     | $$     | $$  | $$__  $$   | $$   | $$__/   | $$  | $$  \n");
            printf("  | $$  | $$\\  $$$  | $$     | $$     | $$  | $$  | $$   | $$   | $$      | $$  | $$\n");
            printf(" /$$$$$$| $$ \\  $$ /$$$$$$   | $$    /$$$$$$| $$  | $$   | $$   | $$$$$$$$| $$$$$$$/\n");
            printf("|______/|__/  \\__/|______/   |__/   |______/|__/  |__/   |__/   |________/|_______/ \n");
            
            
            createDeck(&deck);						//the following statements create a deck, shuffle it, deal it to the players, then removes the pairs
            shuffleDeck(&deck);						//notice how these are the hardmode functions, as this is the loop for playing hardmode
            dealCards(&user, &comp, deck);
            printf("%s's hand has %d cards\n", name, deckLength(user));
            printCards(user);
            printf("Press Enter to Continue\n");
            system("read");							//note: this is the same as system("pause"); in visual studios, which is used to make the game feel more like a game
            printf("Dealer's hand removes Pairs:\n");
            removePairsHARDMODE(&comp);
            printf("Press Enter to Continue\n");
            system("read");
            printf("%s's hand removed Pairs:\n", name);
            removePairsHARDMODE(&user);
            
            printf("%s, your hand has %d cards:\n", name, deckLength(user));
            shuffleDeck(&user);
            printCards(user);
            printf("Press Enter to Continue\n");
            system("read");
            
            while (deckLength(user) != 0 || deckLength(comp) != 0) {		//this while loop is where most of the game goes on, as it doesnt stop until someone wins
                if (((deckLength(user)) > (deckLength(comp))) && counter == 0) {
                    win = checkLose(user, comp);
                    if (win == 1) {     //some cool text art thanks to Miranda
                        printf("  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███   \n ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒ \n▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒ \n░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄   \n░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒ \n ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░ \n  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░ \n░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░  \n      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░      \n\n");
                        printf("▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████  ▐██▌  ▐██▌ \n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀  ▐██▌  ▐██▌ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███    ▐██▌  ▐██▌ \n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄  ▓██▒  ▓██▒ \n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒ ▒▄▄   ▒▄▄  \n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ░▀▀▒  ░▀▀▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░ ░  ░  ░  ░ \n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░       ░     ░ \n ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░ ░     ░    \n\n");
                        break;
                    }
                    else if (win == 2) {
                        printf("%s wins!!!!!!!!!!!!!!!!\n", name);//some cool text art thanks to Miranda
                        printf("YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN\nY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N\nY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N\nY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N\nYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N\n   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N\n    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N\n     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N\n      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N\n       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N\n       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N\n    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N\n    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N\n    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN\n\n");
                        break;
                    }
                    shuffleDeck(&user);										//the hands are shuffled each turn so it is unknown which card will be picked
                    shuffleDeck(&comp);
                    printf("%s, you go first.\n", name);
                    printf("Press Enter to Continue\n");
                    system("read");
                    length = deckLength(comp);
                    userTurnHARDMODE(&comp, length, &user, name);
                    counter++;
                }
                else if (((deckLength(user)) < (deckLength(comp))) && counter == 0) {
                    win = checkLose(user, comp);
                    if (win == 1) {     //some cool text art thanks to Miranda
                        printf("  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███   \n ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒ \n▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒ \n░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄   \n░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒ \n ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░ \n  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░ \n░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░  \n      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░      \n\n");
                        printf("▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████  ▐██▌  ▐██▌ \n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀  ▐██▌  ▐██▌ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███    ▐██▌  ▐██▌ \n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄  ▓██▒  ▓██▒ \n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒ ▒▄▄   ▒▄▄  \n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ░▀▀▒  ░▀▀▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░ ░  ░  ░  ░ \n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░       ░     ░ \n ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░ ░     ░    \n\n");
                        break;
                    }
                    else if (win == 2) {//some cool text art thanks to Miranda
                        printf("%s wins!!!!!!!!!!!!!!!!\n", name);
                        printf("YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN\nY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N\nY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N\nY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N\nYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N\n   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N\n    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N\n     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N\n      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N\n       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N\n       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N\n    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N\n    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N\n    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN\n\n");
                        break;
                    }
                    shuffleDeck(&user);
                    shuffleDeck(&comp);
                    printf("I go first.!\n");
                    printf("Press Enter to Continue\n");
                    system("read");
                    length = deckLength(user);
                    compTurnHARDMODE(&comp, &user, length);
                    counter = 2;
                }
                else {
                    if (counter % 2 == 0) {
                        win = checkLose(user, comp);
                        if (win == 1) {     //some cool text art thanks to Miranda
                            printf("  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███   \n ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒ \n▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒ \n░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄   \n░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒ \n ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░ \n  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░ \n░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░  \n      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░      \n\n");
                            printf("▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████  ▐██▌  ▐██▌ \n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀  ▐██▌  ▐██▌ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███    ▐██▌  ▐██▌ \n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄  ▓██▒  ▓██▒ \n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒ ▒▄▄   ▒▄▄  \n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ░▀▀▒  ░▀▀▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░ ░  ░  ░  ░ \n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░       ░     ░ \n ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░ ░     ░    \n\n");
                            break;
                        }
                        else if (win == 2) {
                            printf("%s wins!!!!!!!!!!!!!!!!\n", name);//some cool text art thanks to Miranda
                            printf("YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN\nY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N\nY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N\nY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N\nYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N\n   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N\n    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N\n     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N\n      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N\n       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N\n       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N\n    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N\n    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N\n    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN\n\n");
                            break;
                        }
                        shuffleDeck(&user);
                        shuffleDeck(&comp);
                        userTurnHARDMODE(&comp, deckLength(comp), &user, name);
                        counter++;
                    }
                    else if (counter % 2 == 1) {
                        win = checkLose(user, comp);
                        if (win == 1) {     //some cool text art thanks to Miranda
                            printf("  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███   \n ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒ \n▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒ \n░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄   \n░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒ \n ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░ \n  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░ \n░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░  \n      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░      \n\n");
                            printf("▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████  ▐██▌  ▐██▌ \n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀  ▐██▌  ▐██▌ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███    ▐██▌  ▐██▌ \n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄  ▓██▒  ▓██▒ \n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒ ▒▄▄   ▒▄▄  \n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ░▀▀▒  ░▀▀▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░ ░  ░  ░  ░ \n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░       ░     ░ \n ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░ ░     ░    \n\n");
                            break;
                        }
                        else if (win == 2) {
                            printf("%s wins!!!!!!!!!!!!!!!!\n", name);//some cool text art thanks to Miranda
                            printf("YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN\nY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N\nY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N\nY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N\nYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N\n   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N\n    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N\n     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N\n      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N\n       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N\n       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N\n       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N\n    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N\n    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N\n    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN\n\n");
                            break;
                        }
                        shuffleDeck(&user);
                        shuffleDeck(&comp);
                        counter++;
                        compTurnHARDMODE(&comp, &user, deckLength(comp));
                    }
                }
            }
            printf("Do you wish to play again? (press q to quit)\n");
            scanf(" %c", &ans);
            
        }
        
        else {						//the following statements are the exact same as the one above, except they aren't in hardmode
            
            createDeck(&deck);
            shuffleDeck(&deck);
            dealCards(&user, &comp, deck);
            printf("%s's hand has %d cards\n", name, deckLength(user));
            printCards(user);
            printf("Press Enter to Continue\n");
            system("read");
            printf("Dealer's hand removes Pairs:\n");
            removePairs(&comp);
            printf("Press Enter to Continue\n");
            system("read");
            printf("%s's hand removed Pairs:\n", name);
            removePairs(&user);
            
            printf("%s, your hand has %d cards:\n", name, deckLength(user));
            shuffleDeck(&user);
            printCards(user);
            printf("Press Enter to Continue\n");
            system("read");
            
            while (deckLength(user) != 0 || deckLength(comp) != 0) {
                if (((deckLength(user)) > (deckLength(comp))) && counter == 0) {
                    win = checkLose(user, comp);
                    if (win == 1) {
                        printf("Dealer Wins!\n You're the Joker!! Loser!!\n");
                        break;
                    }
                    else if (win == 2) {
                        printf("%s wins!! I'm the Joker ):", name);
                        break;
                    }
                    shuffleDeck(&user);
                    shuffleDeck(&comp);
                    printf("%s, you go first.\n", name);
                    printf("Press Enter to Continue\n");
                    system("read");
                    length = deckLength(comp);
                    userTurn(&comp, length, &user, name);
                    counter++;
                }
                else if (((deckLength(user)) < (deckLength(comp))) && counter == 0) {
                    win = checkLose(user, comp);
                    if (win == 1) {
                        printf("Dealer Wins!\n You're the Joker!! Loser!!\n");
                        break;
                    }
                    else if (win == 2) {
                        printf("%s wins!! I'm the Joker ):", name);
                        break;
                    }
                    shuffleDeck(&user);
                    shuffleDeck(&comp);
                    printf("I go first.!\n");
                    printf("Press Enter to Continue\n");
                    system("read");
                    length = deckLength(user);
                    compTurn(&comp, &user, length);
                    counter = 2;
                }
                else {
                    if (counter % 2 == 0) {
                        win = checkLose(user, comp);
                        if (win == 1) {
                            printf("Dealer Wins!\n You're the Joker!! Loser!!\n");
                            break;
                        }
                        else if (win == 2) {
                            printf("%s wins!! I'm the Joker ):\n", name);
                            break;
                        }
                        shuffleDeck(&user);
                        shuffleDeck(&comp);
                        userTurn(&comp, deckLength(comp), &user, name);
                        counter++;
                    }
                    else if (counter % 2 == 1) {
                        win = checkLose(user, comp);
                        if (win == 1) {
                            printf("Dealer Wins!\n You're the Joker!! Loser!!\n");
                            break;
                        }
                        else if (win == 2) {
                            printf("%s wins!! I'm the Joker ):\n", name);
                            break;
                        }
                        shuffleDeck(&user);
                        shuffleDeck(&comp);
                        counter++;
                        compTurn(&comp, &user, deckLength(comp));
                    }
                }
            }
            printf("Do you wish to play again? (press q to quit)\n");			//this is what checks if the user wants to play again
            scanf(" %c", &ans);
        }
    }
    return 0;
}
void printCards(card *head) {	//this is the print cards function, and it functions by reading what the value of the card and printing whatever aspects relates to it
    while (head != NULL) {		//these two for loops are for when you want the symbols for the cards or when you want the actual structure of the card
        if (head->suit == 's')
            printf("\u2660");
        else if (head->suit == 'c')
            printf("\u2663");
        else if (head->suit == 'd')
            printf("\u2662");
        else if (head->suit == 'h')
            printf("\u2661");
        if (head->face > 1 && head->face < 10)
            printf("%d\t", head->face);
        else if (head->face == 10)
            printf("10\t");
        else if (head->face == 1)
            printf("A\t");
        else if (head->face == 11)
            printf("J\t");
        else if (head->face == 12)
            printf("Q\t");
        else if (head->face == 13)
            printf("K\t");
        else
            printf("JOKER\t");
        head = head->listp;
    }
    printf("\n");
    while (head != NULL) {
        printf(" _______ \n|       |\n");
        if (head->suit == 's')
            printf("|♠️");
        else if (head->suit == 'c')
            printf("|♣️");
        else if (head->suit == 'd')
            printf("|♦️");
        else if (head->suit == 'h')
            printf("|♥️");
        if (head->face > 1 && head->face < 10)
            printf("%d    |\n", head->face);
        else if (head->face == 10)
            printf("10   |\n");
        else if (head->face == 1)
            printf("A    |\n");
        else if (head->face == 11)
            printf("J    |\n");
        else if (head->face == 12)
            printf("Q    |\n");
        else if (head->face == 13)
            printf("K    |\n");
        else {
            printf("| JOKER |\n");
        }
        
        for (int i = 0; i<3; i++)
            printf("|       |\n");
        if (head->face != 10) {
            if (head->suit == 's')
                printf("|    ♠️");
            else if (head->suit == 'c')
                printf("|    ♣️");
            else if (head->suit == 'd')
                printf("|    ♦️");
            else if (head->suit == 'h')
                printf("|    ♥️");
        }
        else {
            if (head->suit == 's')
                printf("|   ♠️");
            else if (head->suit == 'c')
                printf("|   ♣️");
            else if (head->suit == 'd')
                printf("|   ♦️");
            else if (head->suit == 'h')
                printf("|   ♥️");
        }
        
        if (head->face > 1 && head->face < 11) {
            printf("%d|\n", head->face);
        }
        else if (head->face == 1)
            printf("A|\n");
        else if (head->face == 11)
            printf("J|\n");
        else if (head->face == 12)
            printf("Q|\n");
        else if (head->face == 13)
            printf("K|\n");
        else {
            printf("| JOKER |\n");
        }
        printf("|_______|\n\n");
        head = head->listp;
    }
}
void createDeck(card **head) {                              //this function creates the deck, using a nested for loop
    card *temp = NULL, *tail = NULL;
    int i, j, k;
    k = 0;
    for (j = 1; j <= 5; j++) {								//the i and the j tell which suit and face to give it, respectively
        for (i = 1; i< 14; i++) {
            temp = (card*)malloc(sizeof(card));				//allocating the memory
            if (j == 1) {
                temp->suit = 'c';
                temp->face = i;
                if (i == 1)
                    tail = temp;
            }
            else if (j == 2) {
                temp->suit = 's';
                temp->face = i;
            }
            else if (j == 3) {
                temp->suit = 'h';
                temp->face = i;
            }
            else if (j == 4) {
                temp->suit = 'd';
                temp->face = i;
            }
            else if (j == 5 && i == 1) {
                temp->suit = 'J';
                temp->face = 100;
            }
            else {
                break;
            }
            if (*head == NULL) {
                *head = temp;
                k++;
            }
            
            if (k>0) {
                
                tail->listp = temp;
            }
            tail = temp;
            tail->listp = NULL;
        }
    }
}
void dealCards(card **user, card **comp, card *deck) {//function that splits the deck into the user's hand and the computer's hand
    int i;
    card *tailu = NULL, *tailc = NULL, *temp = NULL;//need temp to make the new card, and the tails to keep track of the dealing process for the user and the computer
    for (i = 1; i <= 53; i++) {//because the cards are shuffled at this point. you can just go back and forther between the user and the computer when dealing the cards
        temp = (card*)malloc(sizeof(card));
        temp = deck;
        if (i % 2 == 0) {								//this loop happens every other time
            if (*comp == NULL) {						//case for first card
                *comp = temp;
            }
            else {
                (tailc)->listp = temp;
            }
            tailc = temp;								//simple way to create linked list members
            deck = deck->listp;
        }
        else {
            
            if (*user == NULL) {
                *user = temp;
            }
            else {
                (tailu)->listp = temp;
            }
            if (i == 53) {								//end of the deck case
                (tailc)->listp = NULL;
            }
            tailu = temp;
            deck = deck->listp;
        }
    }
}



int deckLength(card *head) {            //this functon just goes until the end of head and increments the counter each time, then returns this counter
    int counter = 0;
    while (head != NULL) {
        counter++;
        head = head->listp;             //increments the head
    }
    return counter;
}

card *findCard(card *head, int index) {	//function to return a card from the index of the head node entered
    int counter = 1;
    if (index <= 0)						//if the user tries to access a node before the head just dont let them and return null
        return NULL;
    else if (index == 1)				//if they want the first card
        return head;
    while (head != NULL) {				//if they want not before the head or the head, increment the head index amount of times and return that node of the linked list
        if (counter == index) {
            return head;
        }
        else {
            counter++;
            head = head->listp;
        }
    }
    return head;
}


void shuffleDeck(card **head) {                                         //function to shuffle the cards
    srand((int)time(0));                                                //needed call to call a random number
    int length = 0, k = 0;
    length = deckLength(*head);
    int random1 = 0, random2 = 0;
    for (int i = 0; i < 10; i++) {                                      //shuffles 10 times the length of the deck
        for (int j = 0; j < length; j++) {
            if (*head == NULL)
                break;
            card *before1 = NULL, *before2 = NULL;                      //uses all of these variabales to not lose the values of the two cards that need to be swapped
            card *curr1 = *head, *curr2 = *head, *temp = NULL;
            k = 0;
            temp = (card *)malloc(sizeof(card));
            random1 = ((rand() % length)) + 1;                          //finds a random number between 1 and amount of cards+1
            random2 = ((rand() % length)) + 1;
            
            if ((random1 == random2) && random1 != deckLength(*head))	//makes sure the random numbers aren't the same
                random1++;
            else if (random1 == random2 && random1 == deckLength(*head))
                random1--;
            
            before1 = findCard(*head, random1 - 1);						//finds the previous card to the first card you want to swap
            if (before1 != NULL)
                curr1 = before1->listp;									//the first card
            
            before2 = findCard(*head, random2 - 1);						//finds the previous card to the second card you want to swap
            if (before2 != NULL)
                curr2 = before2->listp;									//the second card
            
            
            if (before1 != NULL)
                before1->listp = curr2;									//replaces the first card to the second card and the rest of the cards after that
            else
                *head = curr2;											//or just changes the head if the first card was actually the first card in the deck
            if (before2 != NULL)
                before2->listp = curr1;									//does the same exept for the second card
            else
                *head = curr1;
            temp = curr2->listp;										//then these statements connect the rest of the list
            curr2->listp = curr1->listp;
            curr1->listp = temp;
            
        }
    }
}

void removePairs(card **hand) {											//this function removes two given pairs
    int counter1 = 1;
    int counter2 = 2;
    int same = 0;
    card *temp = *hand;
    card *beforetemp = *hand;
    card *temp2 = (*hand)->listp, *beforetemp2;
    while (temp != NULL) {												//this while loop increments the first card that is checked
        same = 0;
        
        counter2 = counter1 + 1;
        temp2 = temp->listp;                                            //making sure that the second card is never the first card, and that is starts at the one after
        while (temp2 != NULL) {                                                     //this while loop increments the second card until a pair is found
            if (temp->face == temp2->face) {
                
                printf("Removing Pair: %c%d, %c%d\n", temp->suit, temp->face, temp2->suit, temp->face);
                beforetemp = findCard(*hand, counter1 - 1);                         /*finding the cards before the ones to remove, this function is similar to
                                                                                     shuffle deck in that you mustbe careful not to lose any data*/
                beforetemp2 = findCard(*hand, counter2 - 1);
                if (beforetemp2 == temp) {                                          //case when the cards are right next to each other
                    beforetemp2 = findCard(*hand, counter2 - 2);
                    same = 1;
                }
                if (beforetemp != NULL) {											//when the first card is not the first card in the hand
                    if (beforetemp2->listp == NULL)
                        beforetemp->listp = NULL;
                    else {
                        beforetemp->listp = temp->listp;
                        counter1--;
                    }
                }
                
                else {																//this is when the first card to swap is the first card in the hand
                    *hand = temp->listp;
                    counter1 = 0;
                }
                if (beforetemp2 != NULL) {											//this is when the second card isnt the first card in the hand
                    beforetemp2->listp = temp2->listp;								//removes temp 2 from the list
                    if (same != 0)													//this case is when the cards aren't next to each other
                        temp = temp->listp;
                }
                
                else {
                    *hand = temp2->listp;											//then if the second card was the first card
                    temp = temp->listp;
                }
                break;
            }
            else {																	//increments temp 2 and counter 2
                temp2 = temp2->listp;
                counter2++;
            }
        }
        counter1++;
        if (temp->listp == NULL || temp == NULL)
            return;																	//end condition
        temp = temp->listp;															//finally increments the first card
        
    }
    
    
    
}

void userTurn(card **comp, int length, card **user, char name[]) {//function for the user turn
    int choice;
    int i;
    card *temp = *comp, *beforetemp = *comp;
    card *usernew = *user;
    printf("%s, this is your hand:\n", name);
    printCards(*user);
    printf("Press Enter to Continue\n");
    system("read");
    
    
    printf("I have %d cards.\n", length);					//computer saying how many cards it has
    for (i = 1; i <= length; ++i) {							//print all availabale cards
        printf("%d\t", i);
    }
    printf("\nWhich one do you choose?\nPick a number between 1 and %d\n", length);
    scanf(" %d", &choice);
    
    if (choice>0 && choice <= length) {						//makes sure they picked a right card
        printf("Good choice!\n");
        temp = findCard(temp, choice);						//temp for the card
        beforetemp = findCard(beforetemp, choice - 1);		//temp for the card before it
        if (beforetemp != NULL) {							//if it isnt the first card
            beforetemp->listp = temp->listp;
        }
        else												//if it is the first card
            *comp = temp->listp;
        
        while (usernew->listp != NULL)						//gets to the end of the users hand
            usernew = usernew->listp;
        usernew->listp = temp;								//adds card to the end of their hand
        temp->listp = NULL;									//makes the end of their hand null again
        removePairs(user);									//function calls for removing pairs and for printing cards
        printCards(*user);
        printf("Press Enter to Continue\n");
        system("read");
        return;
    }
    else {
        printf("Please choose a card I actually have!\n");
        userTurn(comp, length, user, name);					//calls the function again if they didnt pick a possible choice
    }
    
}


void compTurn(card **comp, card **user, int length) {		//computer's turn!
    card *temp = *user;
    card *beforetemp = NULL;
    card *compnew = *comp;
    srand((int)time(0));									//used because the computer picks a random card from the user
    int random1;
    random1 = ((rand() % deckLength(*user)) + 1);			//finds a random card in the user's hand
    printf("I choose card #%d from you\n", random1);
    temp = findCard(*user, random1);						//temp value for this card
    
    beforetemp = findCard(*user, random1 - 1);				//temp value for the card before it
    if (beforetemp != NULL)									//if the card isnt the first card
        beforetemp->listp = temp->listp;					//remove that card from the user's hand
    else
        *user = temp->listp;								//same as above except for the first card
    
    while (compnew->listp != NULL)							//gets to the end of the computer's hand
        compnew = compnew->listp;
    compnew->listp = temp;									//then adds the card to the end of their hand
    temp->listp = NULL;										//end the hand again
    removePairs(comp);										//remove the pairs
    printf("I now have %d cards.\n", deckLength(*comp));
    printf("Press Enter to Continue\n");
    system("read");
}


int checkLose(card *user, card *comp) {						//a function to check if someone has lost, returns 1 if the user loses, 2 if the computer loses, 0 if no one loses
    if (user != NULL) {
        if ((user->face == 100) && (user->listp == NULL)) { //if the user loses
            return 1;
        }
    }
    else if (comp != NULL) {
        if ((comp->face == 100) && (comp->listp == NULL)) { //if the computer loses
            return 2;
        }
    }
    else
        return 0;
    return 0;
}

void removePairsHARDMODE(card **hand) {						//exact same as remove pairs, except checks the color
    int counter1 = 1;
    int counter2 = 2;
    int same = 0;
    card *temp = *hand;
    card *beforetemp = *hand;
    card *temp2 = (*hand)->listp, *beforetemp2;
    while (temp != NULL) {
        same = 0;
        
        counter2 = counter1 + 1;
        temp2 = temp->listp;
        while (temp2 != NULL) {
            if ((temp->face == temp2->face) && ((temp->suit == 'c' && temp2->suit == 's') || (temp->suit == 's' && temp2->suit == 'c') || (temp->suit == 'd' && temp2->suit == 'h') || (temp->suit == 'h' && temp2->suit == 'd'))) {
                
                printf("Removing Pair: %c%d, %c%d\n", temp->suit, temp->face, temp2->suit, temp->face);
                beforetemp = findCard(*hand, counter1 - 1);
                beforetemp2 = findCard(*hand, counter2 - 1);
                if (beforetemp2 == temp) {
                    beforetemp2 = findCard(*hand, counter2 - 2);
                    same = 1;
                }
                if (beforetemp != NULL) {
                    if (beforetemp2->listp == NULL)
                        beforetemp->listp = NULL;
                    else {
                        beforetemp->listp = temp->listp;
                        counter1--;
                    }
                }
                
                else {
                    *hand = temp->listp;
                    counter1 = 0;
                }
                if (beforetemp2 != NULL) {
                    beforetemp2->listp = temp2->listp;
                    if (same != 0)
                        temp = temp->listp;
                }
                
                else {
                    *hand = temp2->listp;
                    temp = temp->listp;
                }
                break;
            }
            else {
                temp2 = temp2->listp;
                counter2++;
            }
        }
        counter1++;
        if (temp->listp == NULL || temp == NULL)
            return;
        temp = temp->listp;
        
    }
    
    
    
}


void userTurnHARDMODE(card **comp, int length, card **user, char name[]) {      //same as user turn except hardmode fucntions
    int choice;
    int i;
    card *temp = *comp, *beforetemp = *comp;
    card *usernew = *user;
    printf("%s, this is your hand:\n", name);
    printCards(*user);
    printf("Press Enter to Continue\n");
    system("read");
    
    
    printf("I have %d cards.\n", length);
    for (i = 1; i <= length; ++i) {
        printf("%d\t", i);
    }
    printf("\nWhich one do you choose?\nPick a number between 1 and %d\n", length);
    scanf(" %d", &choice);
    
    if (choice>0 && choice <= length) {
        printf("Good choice!\n");
        temp = findCard(temp, choice);
        beforetemp = findCard(beforetemp, choice - 1);
        if (beforetemp != NULL)
            beforetemp->listp = temp->listp;
        else
            *comp = temp->listp;
        
        while (usernew->listp != NULL)
            usernew = usernew->listp;
        usernew->listp = temp;
        temp->listp = NULL;
        removePairsHARDMODE(user);
        printCards(*user);
        printf("Press Enter to Continue\n");
        system("read");
        return;
    }
    else {
        printf("Please choose a card I actually have!\n");
        userTurnHARDMODE(comp, length, user, name);
    }
    
}
void compTurnHARDMODE(card **comp, card **user, int length) {	//computer turn except in hardmode
    card *temp = *user;
    card *beforetemp = NULL;
    card *compnew = *comp;
    srand((int)time(0));
    int random1;
    random1 = ((rand() % deckLength(*user)) + 1);
    printf("I choose card #%d from you\n", random1);
    temp = findCard(*user, random1);
    
    beforetemp = findCard(*user, random1 - 1);
    if (beforetemp != NULL)
        beforetemp->listp = temp->listp;
    else
        *user = temp->listp;
    
    while (compnew->listp != NULL)
        compnew = compnew->listp;
    compnew->listp = temp;
    temp->listp = NULL;
    removePairsHARDMODE(comp);
    printf("I now have %d cards.\n", deckLength(*comp));
    printf("Press Enter to Continue\n");
    system("read");
}
