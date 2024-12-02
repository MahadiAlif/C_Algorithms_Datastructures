#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_CITIZENS 5

typedef struct {
    char name[MAX_LENGTH];
    char id[10];
    char birth_place[MAX_LENGTH];
    char birth_date[11];
    char issuing[11];
} citizens_t;

void add_citizen(citizens_t* citizen);
void list_database(citizens_t** citizens, int count);
void id_search(citizens_t** citizens, int count);


int main(){
    citizens_t* citizens[MAX_CITIZENS];      
    int count = 0;

    for (int i = 0; i < MAX_CITIZENS; i++) {
        citizens[i] = (citizens_t*) malloc(sizeof(citizens_t));
        if (citizens[i] == NULL) {
            printf("Error allocating memory\n");
            return 1;
        }
    }

    int task;
    printf("Welcome to the National ID System\n");

    while (1) {
        printf("\n1. Add a new citizen\n2. Search by ID\n3. List database\n4. Exit\n");
        scanf("%d", &task);
        while (getchar() != '\n'); 

        switch (task) {
            case 1:
                if (count < MAX_CITIZENS) {
                    add_citizen(citizens[count]);
                    count++;
                } else {
                    printf("Database is full! Cannot add more citizens.\n");
                }
                break;
            case 2:
                id_search(citizens, count);
                break;
            case 3:
                list_database(citizens, count);
                break;
            case 4:
                for (int i = 0; i < MAX_CITIZENS; i++) {
                    free(citizens[i]);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

void add_citizen(citizens_t* citizen) {
    printf("Enter the name: \n");
    fgets(citizen->name, MAX_LENGTH, stdin);
    citizen->name[strcspn(citizen->name, "\n")] = 0; // Remove newline
    
    printf("Enter ID: \n");
    fgets(citizen->id, 10, stdin);
    citizen->id[strcspn(citizen->id, "\n")] = 0;

    printf("Enter birth place: \n");
    fgets(citizen->birth_place, MAX_LENGTH, stdin);
    citizen->birth_place[strcspn(citizen->birth_place, "\n")] = 0;

    printf("Enter birth date (DD/MM/YYYY): \n");
    fgets(citizen->birth_date, 11, stdin);
    citizen->birth_date[strcspn(citizen->birth_date, "\n")] = 0;

    printf("Enter issuing date (DD/MM/YYYY): \n");
    fgets(citizen->issuing, 11, stdin);
    citizen->issuing[strcspn(citizen->issuing, "\n")] = 0;
    printf("Citizen added successfully !");
}

void list_database(citizens_t** citizens, int count) {
    if (count == 0) {
        printf("No citizens in the database.\n");
        return;
    }

    printf("\n--- Citizen Database ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nCitizen %d:\n", i + 1);
        printf("Name: %s\n", citizens[i]->name);
        printf("ID: %s\n", citizens[i]->id);
        printf("Birth Place: %s\n", citizens[i]->birth_place);
        printf("Birth Date: %s\n", citizens[i]->birth_date);
        printf("Issuing Date: %s\n", citizens[i]->issuing);
    }
}

void id_search(citizens_t** citizens, int count){
    char id[10];
    int found = 0;
    printf("Please enter the id: \n");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = 0;
    for (int i = 0; i < count && found == 0; i++){
        if (strcmp(citizens[i]->id, id) == 0){
        printf("\nCitizen %d:\n", i + 1);
        printf("Name: %s\n", citizens[i]->name);
        printf("ID: %s\n", citizens[i]->id);
        printf("Birth Place: %s\n", citizens[i]->birth_place);
        printf("Birth Date: %s\n", citizens[i]->birth_date);
        printf("Issuing Date: %s\n", citizens[i]->issuing);
        found = 1;

        }
       
    }
    if (found == 0){
        printf("The id is not in database \n");
    }
}
