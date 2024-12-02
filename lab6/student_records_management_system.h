#ifndef STUDENT_RECORDS_MANAGEMENT_SYSTEM_H
#define STUDENT_RECORDS_MANAGEMENT_SYSTEM_H

// Define the struct and typedef in one go to ensure consistency
typedef struct student_s {
    int studentID;
    char name[100];
    char major[50];
    int year;
    float gpa;
    struct student_s* next;
} *student_t;

student_t student_new(int* currentID);
void student_free(student_t student);
void student_add(student_t* head, int* currentID, char* name, char* major, int year, float gpa);
void student_delete(student_t* head, int id);
student_t student_search(student_t head, int id);
void students_display(student_t head);
void free_all_students(student_t head);

#endif
