//
//  main.c
//  hw5p2
//
//  Created by Miranda Hampton on 2/20/17.
//  Inputs: user inuts the key for the encrypted code
//  outputs: the code is now decrypted
/*  The user has to input a specfic key for the code, this case it's 3, the file encrypted.txt is opened and then decrypted using a specfic code and that key. The decrypted code is then written into another file. The user is then asked if they want to re-encrypt with another key.*/

#include <stdio.h>

int mod( int x, int y){
    while(x<0){
        x+=y;
    }
    return x%y;
}

void decrypt_fun(int shift, char *pt_letter){
    if(*pt_letter >= 'a' && *pt_letter <= 'z'){
        *pt_letter = (*pt_letter - shift) - 'a';    //'a' is subtracted to get the number
        *pt_letter = mod(*pt_letter,26) + 'a';      //for the character to be 0-26
    }
    if(*pt_letter >= 'A' && *pt_letter <= 'Z'){
        *pt_letter = (*pt_letter - shift) - 'A';
        *pt_letter = mod(*pt_letter,26) + 'A';
        
        return;
    }}

void encrypt_fun(int shift, char *pt_letter){
    if(*pt_letter >= 'a' && *pt_letter <= 'z'){
        *pt_letter = (*pt_letter + shift) - 'a';
        *pt_letter = mod(*pt_letter, 26) + 'a';
    }
    if(*pt_letter >= 'A' && *pt_letter <= 'Z'){
        *pt_letter = (*pt_letter +shift) - 'A';
        *pt_letter = mod(*pt_letter, 26) + 'A';
    }
    return;
}

int main(void){
    int key = 3;
    int k = 0;
    char letter;
    char ans;
    
    
    while(k != key){
        printf("Enter the decryption key: ");
        scanf(" %d", &k);
        if(k != key)
            printf("Wrong key\n");
    }
    FILE *inp, *outp;
    inp = fopen("encrypted.txt", "r");
    outp = fopen("decrypted.txt", "w");
    if(inp == NULL)
        printf("ERROR");
    else{
        while(fscanf(inp, "%c", &letter) != EOF){
            if((letter <= 'z' && letter >= 'a') || (letter >= 'A' && letter <= 'Z')){
                decrypt_fun(k, &letter);
                fprintf(outp, "%c", letter);    //only prints letter characters
            }
            else{
                fprintf(outp, "%c", letter);    //prints non-letter characters like spaces
            }
        }
        
        fclose(inp);    //closes files so they can be reopen to be encrypted
        fclose(outp);
        
        printf("File decrypted!\n Do you want to re-encrypt the file (y/n)?");
        scanf(" %c", &ans);
        if(ans == 'y'){
            printf("Enter an encryption key: ");
            scanf(" %d", &key);
            inp = fopen("decrypted.txt", "r");
            outp = fopen("encrypted.txt", "w");
            
            if(inp == NULL)
                printf("ERROR");
            else{
                while(fscanf(inp, "%c", &letter) != EOF){
                    if((letter <= 'z' && letter >= 'a') || (letter >= 'A' && letter <= 'Z')){
                        encrypt_fun(key, &letter);      //reencrypts the file with new key
                        fprintf(outp, "%c", letter);
                    }
                    else{
                        fprintf(outp, "%c", letter);
                    }}}
            
            printf("File encrypted!\nGoodbye");
        }
        else{
            printf("Goodbye");
        }
        
        fclose(inp);
        fclose(outp);
        //if user wishes to decrypt the file again, the codes "key" variable must be changed to their new key.
        
        return(0);
        
        
    }}
