#include <stdio.h>
#include <stdlib.h>
int main(){

    int number[3];
    printf("please enter a number\n");
    
    for (int i =0; i<3; i++){
        scanf("%d", &number[i]);
        printf(number[i]);
    }
    

    return 0;
}