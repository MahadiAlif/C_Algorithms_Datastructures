#include <stdio.h>
#include <stdlib.h>
#include "student_records_management_system.h"




student_t student_new(int* currentID) {
    student_t new_student = (student_t) malloc(sizeof(struct student_s));
    if (new_student == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    new_student->studentID = (*currentID)++;
    new_student->next = NULL;
    return new_student;
}

void student_free(student_t student){
   free(student);
}

void student_add(student_t* head, int* currentId, char* name, char* major, int year, float gpa){
   student_t new_student = student_new(currentId);
   if (new_student == NULL){
      return;
   }
   strcpy(new_student->name, name);
   strcpy(new_student->major, major);
   new_student->year = year;
   new_student->gpa = gpa;

   new_student->next =*head;
   *head = new_student;
}

void student_delete(student_t* head, int id){
   student_t temp = *head;
   student_t prev = NULL;

   while (temp!= NULL && temp->studentID != id){
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL){
      printf("Student not found\n");
      return;
   }
   if (prev == NULL){
      *head = temp->next;
   }
   else{
      prev->next = temp->next;
   }
   student_free(temp);
}

student_t student_search(student_t head, int id){
   student_t current = head;
   while (current != NULL){
      if (current->studentID == id){
         return current;
      }
      current = current->next;
   }
   return NULL;
}

void students_display(student_t head){
   student_t current = head;
   while (current != NULL){
      printf("ID: %d, Name: %s, Major: %s, Year: %d, GPA: %.2f\n", 
               current->studentID, current->name, current->major, 
               current->year, current->gpa);
        current = current->next;
   }
}

void free_all_students(student_t head) {
    student_t temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}