#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_records_management_system.h"

int main() {
   student_t head = NULL;
   int currentID = 1, choice, year, id;
   char name[100], major[50];
   float gpa;
   int found = 1;
   
   while (found == 1) {
      printf("\n1. Add Student\n2. Delete Student\n3. Search Student\n4. Display All\n5. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
                printf("Enter name, major, year, GPA: ");
                scanf("%s %s %d %f", name, major, &year, &gpa);
                student_add(&head, &currentID, name, major, year, gpa);
                break;
         case 2:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                student_delete(&head, id);
                break;
         case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                student_t s = student_search(head, id);
                if (s) printf("Found: ID: %d, Name: %s, Major: %s, Year: %d, GPA: %.2f\n", s->studentID, s->name, s->major, s->year, s->gpa);
                else printf("Student not found\n");
                break;
         case 4:
                students_display(head);
                break;
         case 5:
                found = 0;
                break;
         default:
                printf("Invalid choice\n");
        }
    }

    free_all_students(head);
    return 0;
}
