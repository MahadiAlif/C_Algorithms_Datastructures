#include <stdio.h>
#include <limits.h>

void printArray(int *arr, int size);
void findMinMax(int *arr, int size, int *min, int *max);

int min = INT_MAX;
int max = INT_MIN;


int main(){
    int number_array[5] = {1,2,3,4,5};
    int size = sizeof(number_array)/sizeof(number_array[0]);

    findMinMax(number_array,size, &min, &max);
    printArray(number_array, size);

    return 0;
}

void printArray(int *arr, int size){
    for (int i =0; i<size; i++){
        char digit = arr[i] + '0';
        printf("%c\n", digit);
    }
}

void findMinMax(int *arr, int size, int *min, int *max){
    for (int i = 0; i < size; i++){
        if (arr[i] > *max){
            max = arr[i];
        }
    }
    printf("%d", *max);
}