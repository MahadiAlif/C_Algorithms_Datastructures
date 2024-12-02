#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

    //matrix_size
    //allocate_memory
    //read_file_storeit
    //print
    //free

void matrix_size(char* name, int* cols, int* rows);
void allocate_memory(int*** matrix, int rows, int cols);
void readfile_storeit(char* name, int** matrix, int rows, int cols);
void print_matrix(int** matrix, int rows, int cols);
void free_memory(int** matrix, int rows);


int main(){

    int cols = 0;
    int rows = 0;
    int** matrix = NULL;
    char name[10];
    printf("enter the filename\n");
    fgets(name, 10, stdin);
    name[strcspn(name, "\n")] = 0;
    matrix_size(name, &cols, &rows);
    allocate_memory(&matrix, rows, cols);    
    readfile_storeit(name, matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    free_memory(matrix , rows);


    return 0;
}

void matrix_size(char* name, int* cols, int* rows){
    FILE* file = fopen(name, "r");
    if(file == NULL){
        printf("error opening file");
        return;
    }

    char ch;
    *cols = 0;
    *rows = 0;

    while((ch = fgetc(file)) != '\n' && ch != EOF){
        if(ch == '\t'){
            (*cols)++;
        }
       
    }
    rewind(file);
    
    while( (ch = fgetc(file)) != EOF){
        if (ch == '\n'){
            (*rows)++;
        }
    }

    (*cols)++;
    (*rows)++;


    fclose(file);
}

void allocate_memory(int*** matrix, int rows, int cols){
    *matrix = (int**) malloc(rows*sizeof(int*));
    if (*matrix == NULL){
        printf("memory allocation failed for rows\n");
        return;
    }
    for (int i = 0;i<rows; i++){
        (*matrix)[i] = (int*) malloc(cols*sizeof(int));
        if ((*matrix)[i] == NULL){
            printf("memory allocation failed for cols\n");
            return;
        }
    }
    
}

void readfile_storeit(char* name, int** matrix, int rows, int cols){

    FILE* file = fopen(name, "r");
    if (file == NULL){
        printf("error opening file\n");
        return;
    }
    for (int i=0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
}

void print_matrix(int** matrix, int rows, int cols){
    printf("Reading matrix %d X %d\n", rows, cols);
    for (int i =0; i<rows; i++){
        for (int j =0; j<cols; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int** matrix, int rows){
    for (int i = 0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}
