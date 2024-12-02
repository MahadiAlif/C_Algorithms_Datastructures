#include <stdio.h>

float powerf(float x, int n);

int main(){
    float x = 2;
    int  n = 5;
    printf("%.2f", powerf(x,n));
    return 0;
}

float powerf(float x, int n){
    if (n == 0){
        return 1;
    }
    else{
        return x * powerf(x, n-1);
    }
}