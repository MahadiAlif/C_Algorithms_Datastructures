#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void merge_sort(void* dataset, int low, int high, size_t elem_size, int (*compare)(const void*, const void*));
void merge(void* dataset, int low, int mid, int high, size_t elem_size, int (*compare)(const void*, const void*));
int int_compare(const void* a, const void* b);
int float_compare(const void* a, const void* b);
int char_compare(const void* a, const void* b);

int main(int argc, char* argv[]){

    if (argc != 2){
        printf("not enough parameters\n");
        printf("data_type: 'd' for integers, 'f' for floats, 'c' for characters\n");
        return 1;
    }
    
    char mode = argv[1][0];
    int n;

    printf("Enter the size of the dataset: \n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Dataset size must be positive.\n");
        return 1;
    }

    void* dataset;
    size_t elem_size;
    int (*compare)(const void*, const void*);

    if (mode == 'd') {
        dataset = malloc(n * sizeof(int));
        elem_size = sizeof(int);
        compare = int_compare;
        printf("Generating random integers...\n");
        for (int i = 0; i < n; i++) {
            ((int*)dataset)[i] = rand() % 100; 
        }
    } 
    else if (mode == 'f') {
        dataset = malloc(n * sizeof(float));
        elem_size = sizeof(float);
        compare = float_compare;
        printf("Generating random floats...\n");
        for (int i = 0; i < n; i++) {
                ((float*)dataset)[i] = ((float)rand() / RAND_MAX) * 100;
            }
    } 
    else if (mode == 'c') {
        dataset = malloc(n * sizeof(char));
        elem_size = sizeof(char);
        compare = char_compare;
        printf("Generating random characters...\n");
        for (int i = 0; i < n; i++) {
            ((char*)dataset)[i] = 'a' + (rand() % 26); 
        }
    } else {
        printf("Invalid data type. Use 'd', 'f', or 'c'.\n");
        return 1;
    }

    printf("Unsorted dataset:\n");
    for (int i = 0; i < n; i++) {
        if (mode == 'd') printf("%d ", ((int*)dataset)[i]);
        else if (mode == 'f') printf("%.2f ", ((float*)dataset)[i]);
        else printf("%c ", ((char*)dataset)[i]);
    }
    printf("\n");

    merge_sort(dataset, 0, n - 1, elem_size, compare);

    printf("Sorted dataset:\n");
    for (int i = 0; i < n; i++) {
        if (mode == 'd') printf("%d ", ((int*)dataset)[i]);
        else if (mode == 'f') printf("%.2f ", ((float*)dataset)[i]);
        else printf("%c ", ((char*)dataset)[i]);
    }
    printf("\n");

    free(dataset);
    return 0;
}

void merge_sort(void* dataset, int low, int high, size_t elem_size, int (*compare)(const void*, const void*)) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(dataset, low, mid, elem_size, compare);
        merge_sort(dataset, mid + 1, high, elem_size, compare);
        merge(dataset, low, mid, high, elem_size, compare);
    }
}

void merge(void* dataset, int low, int mid, int high, size_t elem_size, int (*compare)(const void*, const void*)) {
    int left_size = mid - low + 1;
    int right_size = high - mid;

    void* left = malloc(left_size * elem_size);
    void* right = malloc(right_size * elem_size);

    memcpy(left, (char*)dataset + low * elem_size, left_size * elem_size);
    memcpy(right, (char*)dataset + (mid + 1) * elem_size, right_size * elem_size);

    int i = 0, j = 0, k = low;
    while (i < left_size && j < right_size) {
        if (compare((char*)left + i * elem_size, (char*)right + j * elem_size) <= 0) {
            memcpy((char*)dataset + k * elem_size, (char*)left + i * elem_size, elem_size);
            i++;
        } else {
            memcpy((char*)dataset + k * elem_size, (char*)right + j * elem_size, elem_size);
            j++;
        }
        k++;
    }

    while (i < left_size) {
        memcpy((char*)dataset + k * elem_size, (char*)left + i * elem_size, elem_size);
        i++;
        k++;
    }

    while (j < right_size) {
        memcpy((char*)dataset + k * elem_size, (char*)right + j * elem_size, elem_size);
        j++;
        k++;
    }

    free(left);
    free(right);
}

int int_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int float_compare(const void* a, const void* b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff < 0) ? -1 : (diff > 0);
}

int char_compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
