#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char id[5];
    float x1, y1;
    float x2, y2;
    float area;
    float perimeter;
} rectangle_t;

void readfile_storeit(char* filename, rectangle_t** rectangles, int* num_rectangles);
void calculate_dimensions(rectangle_t* rect);
void sort_by_area(rectangle_t* rectangles, int num_rectangles);
void sort_by_perimeter(rectangle_t* rectangles, int num_rectangles);
void write_sorted(char* filename, rectangle_t* rectangles, int num_rectangles, int sort_by_area);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> <area output file> <perimeter output file>\n", argv[0]);
        return 1;
    }

    rectangle_t* rectangles = NULL;
    int num_rectangles = 0;

    readfile_storeit(argv[1], &rectangles, &num_rectangles);


    sort_by_area(rectangles, num_rectangles);
    write_sorted(argv[2], rectangles, num_rectangles, 1);
    sort_by_perimeter(rectangles, num_rectangles);
    write_sorted(argv[3], rectangles, num_rectangles, 0);
    free(rectangles);

    return 0;
}

void readfile_storeit(char* filename, rectangle_t** rectangles, int* num_rectangles) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char id[5];
    float x, y;
    while (fscanf(file, "%4s %f %f", id, &x, &y) == 3) {
        int found = 0;
        for (int i = 0; i < *num_rectangles; i++) {
            if (strcmp((*rectangles)[i].id, id) == 0) {
                (*rectangles)[i].x2 = x;
                (*rectangles)[i].y2 = y;
                calculate_dimensions(&(*rectangles)[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            *num_rectangles += 1;
            *rectangles = realloc(*rectangles, *num_rectangles * sizeof(rectangle_t));
            if (*rectangles == NULL) {
                printf("Memory allocation error\n");
                fclose(file);
                return;
            }
            strcpy((*rectangles)[*num_rectangles - 1].id, id);
            (*rectangles)[*num_rectangles - 1].x1 = x;
            (*rectangles)[*num_rectangles - 1].y1 = y;
            (*rectangles)[*num_rectangles - 1].area = 0.0;
            (*rectangles)[*num_rectangles - 1].perimeter = 0.0;
        }
    }
    fclose(file);
}

void calculate_dimensions(rectangle_t* rect) {
    float width = fabs(rect->x2 - rect->x1);
    float height = fabs(rect->y2 - rect->y1);
    rect->area = width * height;
    rect->perimeter = 2 * (width + height);
}

void sort_by_area(rectangle_t* rectangles, int num_rectangles) {
    for (int i = 0; i < num_rectangles - 1; i++) {
        for (int j = i + 1; j < num_rectangles; j++) {
            if (rectangles[i].area < rectangles[j].area) {
                rectangle_t temp = rectangles[i];
                rectangles[i] = rectangles[j];
                rectangles[j] = temp;
            }
        }
    }
}

void sort_by_perimeter(rectangle_t* rectangles, int num_rectangles) {
    for (int i = 0; i < num_rectangles - 1; i++) {
        for (int j = i + 1; j < num_rectangles; j++) {
            if (rectangles[i].perimeter < rectangles[j].perimeter) {
                rectangle_t temp = rectangles[i];
                rectangles[i] = rectangles[j];
                rectangles[j] = temp;
            }
        }
    }
}

void write_sorted(char* filename, rectangle_t* rectangles, int num_rectangles, int sort_by_area) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_rectangles; i++) {
        fprintf(file, "%s\n", rectangles[i].id);
    }
    fclose(file);
}
