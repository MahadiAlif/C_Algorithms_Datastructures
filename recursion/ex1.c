#include <stdio.h>

//finding factorial.

int factorial(int num);
int main(){


    printf("%d", factorial(5));
    return 0;
}

int factorial(int num){
    if (num == 1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}