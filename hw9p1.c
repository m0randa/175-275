//
//  main.c
//  hw9p1
//
//  Created by Miranda Hampton on 3/29/17.
//  inputs: User inputs a IP address, the operating system, and the length of the network
//  outputs: Code outputs which IP addresses from the FILE that belong to the same network
//  and are assigned to hosts running the same operating system.
//
/*  The code will first read the file into an array, then ask the user for it's inputs. Based on the length entered it will check and compare the certain decimal numbers for lengths of 24, 16, or 8. If the lengths are anything else, the code will convert them into their binary numbers and compare them that way.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x,y,z,w;
    char os[8];
} host;

void print_host(host *h){
    printf("%d.%d.%d.%d %s\n", h->x, h->y, h->z, h->w, h->os);
}
void find_hosts(host *net, int size, host t, int len){
    char mark = 'm';
    
    if(strchr(t.os, '?') != NULL)//looks for all operating systems
        mark = '?';
    
    for(int i = 0; i < size; i++){
        
        if(len >= 24){ //compares all three decimal numbers
            if((net[i].x == t.x)&&(net[i].y == t.y)&&(net[i].z == t.z))
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
        }
        
        else if(len == 16){//compares two decimal numbers
            if((net[i].x == t.x)&&(net[i].y == t.y))
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
        }
        
        else if(len == 8){//compares 1 decimal number
            if(net[i].x == t.x)
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
        }
        
        else if(len < 24 && len > 16){ //converts decimal to binary
            int test;
            int z1 = net[i].z;
            int z2 = t.z;
            int r;
            int b = 0, j = 1, b2 = 0;
            test = 24 - len;
            test = pow(10,test);
            if(z1 == z2){
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
            }
            else{
                while(z1 != 0) {
                    r = z1 % 2;
                    z1 = z1 / 2;
                    b = b + (r * j);
                    j = j * 10;
                }
                j = 1;
                while(z2 != 0) {
                    r = z2 % 2;
                    z2 = z2 / 2;
                    b2 = b2 + (r * j);
                    j = j * 10;
                }
                if((net[i].x == t.x)&&(net[i].y == t.y)&&(b - b2 < test)){
                    if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                        print_host(&net[i]);
                }
            }
        }
        
        else if(len < 16 && len > 8){
            int test;
            int z1 = net[i].y;
            int z2 = t.y;
            int r;
            int b = 0, j = 1, b2 = 0;
            test = 16 - len;
            test = pow(10,test);
            if(z1 == z2){
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
            }
            else{
                while(z1 != 0) {
                    r = z1 % 2;
                    z1 = z1 / 2;
                    b= b + (r * j);
                    j = j * 10;
                }
                j = 1;
                while(z2 != 0) {
                    r = z2 % 2;
                    z2 = z2 / 2;
                    b2 = b2 + (r * j);
                    j = j * 10;
                }
                if((net[i].x == t.x)&&(b - b2 < test)){
                    if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                        print_host(&net[i]);
                }
            }
        }
        
        else if(len < 8){
            int test;
            int z1 = net[i].x;
            int z2 = t.x;
            int r;
            int b = 0, j = 1, b2 = 0;
            test = 8 - len;
            test = pow(10,test);
            if(z1 == z2){
                if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                    print_host(&net[i]);
            }
            else{
                while(z1 != 0) {
                    r = z1 % 2;
                    z1 = z1 / 2;
                    b= b + (r * j);
                    j = j * 10;
                }
                j = 1;
                while(z2 != 0) {
                    r = z2 % 2;
                    z2 = z2 / 2;
                    b2 = b2 + (r * j);
                    j = j * 10;
                }
                if(b - b2 < test){
                    if((strcmp(net[i].os, t.os) == 0) || (mark == '?'))
                        print_host(&net[i]);
                }
            }
        }
    }
}


host convert_IP(char s[]){
    host IP;
    char *pt;
    int i =0;
    
    pt=s;
    
    IP.x = atoi(s);
    
    while((pt=strchr(pt, '.'))!=NULL){
        if(i==0)
            IP.y = atoi(pt+1);
        else if(i==1)
            IP.z = atoi(pt+1);
        else if(i==2)
            IP.w = atoi(pt+1);
        i++;
        pt++;
        
    }
    
    return IP;
}


int main(void){
    FILE* inp = fopen("hosts.txt", "r");
    char address[20], temp[100];
    host IP;
    int len;
    host *pt, *arr;
    int i = 0;
    
    if(inp == NULL)
        printf("ERRROR\n");
    else{ //Counts the number of elements in the file
        
        while(fgets(temp, 100, inp) != NULL)
            i++;
        rewind(inp);
        
        pt = (host*)calloc(sizeof(host), i); //dynamically allocated memory
        arr = pt;
        while(fscanf(inp, "%d.%d.%d.%d %s", &arr->x, &arr->y, &arr->z, &arr->w, arr->os)!=EOF)
              arr++;
        fclose(inp);
        
      
        printf("Enter the target IP address: \n");
        scanf("%s", address);
        IP = convert_IP(address);
        
        printf("Enter the os, or enter \"?\" for any os: \n");
        scanf("%s", IP.os);
        
        printf("Enter the length of the network part: \n");
        scanf(" %d", &len);
        
        arr = pt; //points back to the beginning
        
        find_hosts(arr, i,IP, len);
    
    
    }
    free(pt);
    return(0);
}
