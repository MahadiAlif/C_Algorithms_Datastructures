#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_rows 10
#define N_cols 100
#define Max_size 20+1

typedef struct
{
    int id;
    // char name[Max_size];
    char  *name;
    // char family_name[Max_size];
    char *family_name;
} student_t;


int main(){
    student_t **matrix = NULL;  // pointer to pointer, vector of vectors
    size_t index, col_index;
    
    matrix = (student_t **) malloc(N_rows * sizeof(student_t *));  // allocate memory for the rows
    if (matrix == NULL){
        fprintf(stderr, "Error allocating memory\n");
        return -1;
    }

    // now allocate memory for the columns
    for (index =0; index < N_rows; index++){
        matrix[index] = (student_t *) malloc(N_cols * sizeof(student_t));
        if (matrix[index] == NULL){
            fprintf(stderr, "Cannot allocate %ld-th row\n", index);
            for (col_index = 0; col_index < index; col_index++){
                free(matrix[col_index]);
            }
            return -2;
        }   for (col_index = 0; col_index < N_cols; col_index++){
            matrix[index][col_index].name = (char *) malloc(Max_size * sizeof(char));
            matrix[index][col_index].family_name = (char *) malloc(Max_size* sizeof(char));
        }
    }
    for (index = 0; index < N_rows; index++){
        for (col_index = 0; col_index < N_cols; col_index++){
            matrix[index][col_index].id = (int)col_index - 1;
            strcpy(matrix[index][col_index].name, "Name of student");
                matrix[index][col_index].family_name[0] = '\0';
        }
    }

    for (index = 0; index < N_rows; index++){
        for (col_index = 0; col_index < N_cols; col_index++){
           fprintf(stdout, "%d %s %s\n", matrix[index][col_index].id, matrix[index][col_index].name, matrix[index][col_index].family_name);
        }
        fprintf(stdout, "\n");
    }

    // free the memory
    for (index = 0; index < N_rows; index++){ // need to free the memory allocated for the columns
        free(matrix[index]);
    }
    free(matrix);
}