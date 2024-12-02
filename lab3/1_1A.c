#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length_max 10

int main(){

    char number[length_max];

    printf("please choose the quantity of tokens to deposit: \n");
    fgets(number, length_max, stdin);
    int lenghth  = strlen(number);
    
    int number_int = atoi(number);
    printf("%d\n", number_int);

    return 0;

}