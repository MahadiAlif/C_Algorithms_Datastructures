#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid(int **square, int n, int row, int col, int num, int target_sum);
int solve_magic_square(int **square, int n, int target_sum, int num);
void save_to_file(int **square, int n, char *filename);

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Not enough parameters");
        return 1;
    }
    int n = atoi(argv[1]);
    char* filename = argv[2];
    int** square = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i<n; i++){
        square[i] = (int*) malloc(n*sizeof(int));
        for (int j = 0; j < n; j++) {
            square[i][j] = 0;
        }
    }

    int target_sum = n * (n * n + 1) / 2;
    if (solve_magic_square(square, n, target_sum, 1)) {
        save_to_file(square, n, filename);
    } else {
        printf("No solution found\n");
    }

    for (int i = 0; i <n; i++){
        free(square[i]);
    }
    free(square);

    return 0;
}

int is_valid(int **square, int n, int row, int col, int num, int target_sum) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (square[i][j] == num) return 0;
        }
    }

    int row_sum = 0, col_sum = 0, main_diag = 0, anti_diag = 0;
    for (int i = 0; i < n; i++) {
        row_sum += square[row][i];
        col_sum += square[i][col];
        main_diag += square[i][i];
        anti_diag += square[i][n - i - 1];
    }

    if (row_sum + num > target_sum || col_sum + num > target_sum) return 0;

    if (row == col) {
        if (main_diag + num > target_sum) return 0;
    }

    if (row + col == n - 1) {
        if (anti_diag + num > target_sum) return 0;
    }

    return 1;
}

int solve_magic_square(int **square, int n, int target_sum, int num) {
    if (num > n * n) return 1;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (square[row][col] == 0 && is_valid(square, n, row, col, num, target_sum)) {
                square[row][col] = num;
                if (solve_magic_square(square, n, target_sum, num + 1)) return 1;
                square[row][col] = 0;
            }
        }
    }
    return 0;
}

void save_to_file(int **square, int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%d ", square[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
