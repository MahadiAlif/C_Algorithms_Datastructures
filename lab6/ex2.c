#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n_columns;
    double *values;
} row;

typedef struct {
    int n_lines;
    int n_header;
    char *sep;
    row *matrix;
} csv;

void read_csv(csv *csv_data, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char line[1024];
    int row_count = 0;
    int col_count = 0;

    csv_data->matrix = malloc(sizeof(row) * 100);

    while (fgets(line, sizeof(line), file)) {
        if (row_count < csv_data->n_header) {
            row_count++;
            continue;
        }

        csv_data->matrix[row_count - csv_data->n_header].values = malloc(sizeof(double) * 100);
        csv_data->matrix[row_count - csv_data->n_header].n_columns = 0;

        char *token = strtok(line, csv_data->sep);
        while (token != NULL) {
            csv_data->matrix[row_count - csv_data->n_header].values[col_count++] = atof(token);
            token = strtok(NULL, csv_data->sep);
        }
        csv_data->matrix[row_count - csv_data->n_header].n_columns = col_count;
        col_count = 0;
        row_count++;
    }
    csv_data->n_lines = row_count - csv_data->n_header;
    fclose(file);
}

void increment_values(csv *csv_data) {
    for (int i = 0; i < csv_data->n_lines; i++) {
        for (int j = 0; j < csv_data->matrix[i].n_columns; j++) {
            csv_data->matrix[i].values[j] += 1.0;
        }
    }
}

void write_csv(csv *csv_data, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < csv_data->n_lines; i++) {
        for (int j = 0; j < csv_data->matrix[i].n_columns; j++) {
            fprintf(file, "%f", csv_data->matrix[i].values[j]);
            if (j < csv_data->matrix[i].n_columns - 1) {
                fprintf(file, "%s", csv_data->sep);
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input filename> <output filename> [separator] [header rows]\n", argv[0]);
        return 1;
    }

    csv csv_data;
    csv_data.sep = (argc > 3) ? argv[3] : ",";
    csv_data.n_header = (argc > 4) ? atoi(argv[4]) : 0;

    read_csv(&csv_data, argv[1]);
    increment_values(&csv_data);
    write_csv(&csv_data, argv[2]);

    for (int i = 0; i < csv_data.n_lines; i++) {
        free(csv_data.matrix[i].values);
    }
    free(csv_data.matrix);

    return 0;
}
