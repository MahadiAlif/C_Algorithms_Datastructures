#include <stdio.h>
#include <ctype.h>
#include <string.h>

float calculate_median(float arr[], int n);
void merge_sort(float* arr, int low, int high);
void merge(float* arr, int low, int mid, int high);

int main(){

    FILE* file = fopen("racing.txt", "r");
    if (!file){
        printf("error opening file");
        return 1;
    }
    
    float lap_info[100];
    int count = 0;
    while (fscanf(file, "%*s %*s %*d:%f", &lap_info[count]) != EOF){
        count++;
    }
    fclose(file);
    printf("unsorted lap times");
    for (int i = 0; i < count; i++){
        printf("%.3f\n", lap_info[i]);
    }
    merge_sort(lap_info, 0, count-1);
    printf("Sorted lap times:\n");
    for (int i = 0; i < count; i++) {
        printf("%.3f\n", lap_info[i]);
    }

    
    float median = calculate_median(lap_info, count);
    printf("Median lap time: %.3f ms\n", median);

    return 0;
}

void merge_sort(float* arr, int low, int high){
    if (low < high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(float* arr, int low, int mid, int high){
     int i = low, j = mid + 1, k = 0;
    int size = high - low + 1;
    float *temp = (float *)malloc(size * sizeof(float));

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

float calculate_median(float arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

