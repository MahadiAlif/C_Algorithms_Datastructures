#include "item.h"
#include <stdlib.h>

#define MAX 100

// read an item from file
int item_read(FILE * fp, void **data) {
    int * p = (int *)malloc(sizeof(int));
    if(p == NULL){
        printf("Memory allocation error.\n");
        return -1;
    }
    if (fscanf(fp, "%d", p) == EOF) {
        return EOF;
    }
    *data = p;
    return 1;
}


// print an item on file
void item_print(FILE * fp, void * data) {
    if(fp == NULL) return;
    fprintf(fp, "%d ", *(int *)data);
}

// compare two items
int item_compare(void * d1, void * d2) {
  return *(int *)d1 - *(int *)d2;
}

// free an item
void item_free(void * d) {
  free(d);
  d = NULL;
}
