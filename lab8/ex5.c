#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trinagleA(int curr_row, int n);
void triangleB(int curr_row, int n);
void print_row(int curr_row, int curr_col);

int main(){

    
    trinagleA(1, 5); //calling first triangle function starting with 1
    triangleB(1,4); //calling second triangle function staring with 1

    return 0;
}

void trinagleA(int curr_row, int n){
    if (curr_row > n){
        return;
    }
    for (int i =0; i<curr_row; i++){
        printf("%d", curr_row);
    }
    printf("\n");
    trinagleA(curr_row+1, n);
}

void triangleB(int curr_row, int n){
    if (curr_row > n){
        return;
    }
    print_row(curr_row, 1);
    printf("\n");
    triangleB(curr_row+1, n);
}

void print_row(int curr_row, int curr_col){
    if (curr_col > curr_row){
        return;
    }
    printf("%d ", curr_col);
    print_row(curr_row, curr_col+1);
}