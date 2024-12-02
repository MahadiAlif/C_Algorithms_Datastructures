#include <stdio.h>

//odd even problem

void odd(int num);
void even(int num);

int main(){
    int num = 1;
    odd(num);

    return 0;
}

void odd(int num){
    if (num <= 10){
        printf("%d ", num+1);
        num++;
        even(num);
    }
    return;
}

void even(int num){
    if (num <= 10){
        printf("%d ", num-1);
        num++;
        odd(num);
    }
    return;
}