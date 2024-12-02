#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

// Define the student structure
typedef struct student {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int slot;
    struct student *next;
    struct student *prev;
} student_t;

// Define the list structure
typedef struct {
    student_t *head;
    student_t *tail;
    int size;
} students_list_s;

// Function declarations
void load_data(char* filename, students_list_s *students);
void insertion_sort(students_list_s *students);
void selection_sort(students_list_s *students);
void bubble_sort(students_list_s *students);
int assign_slots(students_list_s *students, int m);
void display_slots(students_list_s *students);

// Function to create a new student node
student_t* create_student(char* name, char* surname, char* id) {
    student_t *new_student = (student_t*) malloc(sizeof(student_t));
    strcpy(new_student->name, name);
    strcpy(new_student->surname, surname);
    strcpy(new_student->id, id);
    new_student->slot = 0;
    new_student->next = new_student->prev = NULL;
    return new_student;
}

// Load data from file
void load_data(char* filename, students_list_s *students) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH], id[MAX_ID_LENGTH];
    while (fscanf(file, "%s %s %s", name, surname, id) == 3) {
        student_t *new_student = create_student(name, surname, id);
        
        if (students->tail) {
            students->tail->next = new_student;
            new_student->prev = students->tail;
            students->tail = new_student;
        } else {
            students->head = students->tail = new_student;
        }
        students->size++;
    }
    fclose(file);
}

// Insertion sort
void insertion_sort(students_list_s *students) {
    if (!students->head) return;
    
    student_t *sorted = NULL;
    student_t *current = students->head;
    
    while (current) {
        student_t *next = current->next;
        current->prev = current->next = NULL;
        
        if (!sorted || strcmp(current->surname, sorted->surname) < 0) {
            current->next = sorted;
            if (sorted) sorted->prev = current;
            sorted = current;
        } else {
            student_t *temp = sorted;
            while (temp->next && strcmp(temp->next->surname, current->surname) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next) temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }
    students->head = sorted;
    students->tail = sorted;
    while (students->tail && students->tail->next) {
        students->tail = students->tail->next;
    }
}

// Selection sort
void selection_sort(students_list_s *students) {
    for (student_t *i = students->head; i && i->next; i = i->next) {
        student_t *min = i;
        for (student_t *j = i->next; j; j = j->next) {
            if (strcmp(j->surname, min->surname) < 0) {
                min = j;
            }
        }
        if (min != i) {
            // Swap nodes
            char temp_name[MAX_NAME_LENGTH], temp_surname[MAX_NAME_LENGTH], temp_id[MAX_ID_LENGTH];
            strcpy(temp_name, i->name);
            strcpy(temp_surname, i->surname);
            strcpy(temp_id, i->id);

            strcpy(i->name, min->name);
            strcpy(i->surname, min->surname);
            strcpy(i->id, min->id);

            strcpy(min->name, temp_name);
            strcpy(min->surname, temp_surname);
            strcpy(min->id, temp_id);
        }
    }
}

// Bubble sort
void bubble_sort(students_list_s *students) {
    if (!students->head) return;

    int swapped;
    do {
        swapped = 0;
        student_t *current = students->head;
        while (current->next) {
            if (strcmp(current->surname, current->next->surname) > 0) {
                // Swap names, surnames, and IDs
                char temp_name[MAX_NAME_LENGTH], temp_surname[MAX_NAME_LENGTH], temp_id[MAX_ID_LENGTH];
                strcpy(temp_name, current->name);
                strcpy(temp_surname, current->surname);
                strcpy(temp_id, current->id);

                strcpy(current->name, current->next->name);
                strcpy(current->surname, current->next->surname);
                strcpy(current->id, current->next->id);

                strcpy(current->next->name, temp_name);
                strcpy(current->next->surname, temp_surname);
                strcpy(current->next->id, temp_id);

                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Assign slots to students
int assign_slots(students_list_s *students, int m) {
    int slot = 1, count = 0;
    student_t *current = students->head;
    while (current) {
        current->slot = slot;
        count++;
        if (count == m) {
            slot++;
            count = 0;
        }
        current = current->next;
    }
    return slot;
}

// Display slots
void display_slots(students_list_s *students) {
    int current_slot = 1;
    student_t *current = students->head;
    printf("The number of assigned slots is %d!\n", students->size / current_slot + 1);
    while (current) {
        if (current->slot != current_slot) {
            current_slot = current->slot;
            printf("\nSlot %d:\n", current_slot);
        }
        printf("%s %s %s\n", current->name, current->surname, current->id);
        current = current->next;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <filename> <-I/-S/-B> -M <max_per_slot>\n", argv[0]);
        return EXIT_FAILURE;
    }

    students_list_s students = { NULL, NULL, 0 };
    load_data(argv[1], &students);

    if (strcmp(argv[2], "-I") == 0) {
        insertion_sort(&students);
    } else if (strcmp(argv[2], "-S") == 0) {
        selection_sort(&students);
    } else if (strcmp(argv[2], "-B") == 0) {
        bubble_sort(&students);
    } else {
        fprintf(stderr, "Invalid sorting option\n");
        return EXIT_FAILURE;
    }

    int max_per_slot = atoi(argv[4]);
    int num_slots = assign_slots(&students, max_per_slot);
    display_slots(&students);

    return EXIT_SUCCESS;
}
