#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//take M,N
//allocate mem
//do the sorting in selsort, insort, bubble
//measure the time
//use loop to take N reading
//free the mem

void swap(int arr[], int x, int y);
void bubble(int arr[], int n);
void selsort(int arr[], int n);
void insort(int arr[], int n);
double mean_time(double *times, int M);

int main(){
    int M,N;
    printf("sorting times\n");
    scanf("%d", &M);
    printf("array size\n");
    scanf("%d", &N);

    double* bubble_times = (double*) malloc(M*sizeof(double));
    double* sel_times = (double*) malloc (M*sizeof(double));
    double* ins_times = (double*) malloc(M*sizeof(double));

    for (int i = 0; i<M; i++){
        int* arr = (int*) malloc(N*sizeof(int));

        srand(time(NULL)+i);
        for (int i =0; i<N; i++){
        arr[i] = rand() % 1000;
        }

        int* bubble_arr = (int*) malloc(N*sizeof(int));
        int* sel_arr = (int*) malloc(N*sizeof(int));
        int* ins_arr = (int*) malloc(N*sizeof(int));

        memcpy(bubble_arr, arr, N*sizeof(int));
        memcpy(sel_arr, arr, N*sizeof(int));
        memcpy(ins_arr, arr, N*sizeof(int));

         clock_t t1 = clock();
        bubble(bubble_arr, N);
        clock_t t2 = clock();
        bubble_times[i] = (double) (t2-t1) / CLOCKS_PER_SEC;

        t1 = clock();
        selsort(sel_arr, N);
        t2 = clock();
        sel_times[i] = (double) (t2-t1) / CLOCKS_PER_SEC;

        t1 = clock();
        insort(ins_arr, N);
        t2 = clock();
        ins_times[i] = (double) (t2-t1) / CLOCKS_PER_SEC;

        free(arr);
        free(bubble_arr);
        free(sel_arr);
        free(ins_arr);

    }

    printf("Insertion Sort ---- time spent: %f\n", mean_time(ins_times, M));
    printf("Bubble sort ---- time spent: %f\n", mean_time(bubble_times, M));
    printf("Selection sort ---- time spent: %f\n", mean_time(sel_times, M));

    free(sel_times);
    free(ins_times);
    free(bubble_times);


    return 0;
}

void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;

}

void bubble(int arr[], int n){
    int flag = 1;
    for (int i =0; i<n-1 && flag == 1; i++){
        flag = 0;
        for (int j =0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]){
                flag = 1;
                swap(arr, j, j+1);
            }
        }
    }
    /*for (int i =0; i<n; i++){
            printf("%d\t", arr[i]);
        }
        printf("\n");*/
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
}

void insort(int arr[], int n){
    for (int i =1; i<n; i++){
        int x = arr[i];
        int j = i-1;
        while (j>=0 && x < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
    /*for (int i =0; i<n; i++){
            printf("%d\t", arr[i]);
        }
        printf("\n");*/
}

double mean_time(double* times, int M){
    double sum = 0;
    for (int i = 0; i<M; i++){
        sum = sum + times[i];
    }
    return sum/M;
}
