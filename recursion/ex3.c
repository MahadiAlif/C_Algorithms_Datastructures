#include <stdio.h>

int fun(int n);

int main(){
    printf("%d", fun(8));
    return 0;
}

int fun(int n){
    if (n == 1){
        return 0;
    }
    else{
        return 1 + fun(n/2); //this is a non-tail recursive. as addition needs to be done after returning.
    }
}