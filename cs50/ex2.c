#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int number;
    int num[] = {1,5,10,20,100,50};
    printf("enter a number\n");
    scanf("%d", &number);

    for (int i = 0;  i<6; i++){
        if (num[i] == number){
            printf("found");
            return 0;
        }
    }
    printf("not found");
    return 1;


}