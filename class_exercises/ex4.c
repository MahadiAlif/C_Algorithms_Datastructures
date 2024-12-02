#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void matrixSize(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // First pass: determine dimensions
    int temp;
    char ch;
    *cols = 0;
    *rows = 0;
    while (fscanf(file, "%d", &temp) != EOF) {
        if (*cols == 0) {
            // Count columns in the first row
            rewind(file);
            while ((ch = fgetc(file)) != '\n' && ch != EOF) {
                if (ch == ' ' || ch == '\t')+
                (*cols)++;
            }
            (*cols)++; (*rows)++;
        }
        // Count rows
        while (fgetc(file) != '\n' && !feof(file));
        (*rows)++;
    }
    fclose(file);
    return;
}

void writeMatrix(const char *filename, int **matrix, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void manipulateMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int exponent = i + j;
            matrix[i][j] = pow(matrix[i][j], exponent);
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int rows = 0, cols = 0;
    matrixSize(argv[1], &rows, &cols);

    // Allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }
    // Second pass: read data into the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    
    manipulateMatrix(matrix, rows, cols);
    writeMatrix(argv[2], matrix, rows, cols);
    freeMatrix(matrix, rows);
    
    return 0;
}
