#include <stdio.h>

int mult(int x, int y);

int main(){
    int x,y;
    printf("please enter value for x\n");
    scanf("%d", &x);
    printf("please enter the value for y\n");
    scanf("%d", &y);
    printf("%d",mult(x,y));

    return 0;
}

int mult(int x, int y){
    if (y==1){
        return x;
    }
    else{
        return mult(x,y-1) + x;
    }
}