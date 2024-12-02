#include <stdio.h>
#include <string.h>

void swap(int arr[], int x, int y);
void selsort(int arr[], int n);

int main(){

    int arr[] = {10,20,5,50,1};
    selsort(arr, 5);


}

void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;

}

void selsort(int arr[], int n){
    for (int i = 0; i<n-1;i++){
      int min = i;
      for (int j = i+1; j < n; j++){
        if (arr[j] < arr[min]){
            min = j;
        }
      }
      swap(arr, i, min);
    }
    for (int i =0; i<n; i++){
            printf("%d\t", arr[i]);
        }
    }
