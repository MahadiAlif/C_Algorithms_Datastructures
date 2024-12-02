#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length_max 10

int main(){

    char number[length_max];

    printf("please choose the quantity of tokens to deposit: \n");
    fgets(number, length_max, stdin);
    int lenghth  = strlen(number);
    
    float number_float = atof(number);
    printf("You deposited: %.2f\n", number_float);

    return 0;

}