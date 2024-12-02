#include <stdio.h>
#include <stdlib.h>
#include "task_manager.h"

void menu() {
    printf("\nTask Manager Menu:\n");
    printf("1. Add Task\n");
    printf("2. Find Task by ID\n");
    printf("3. Remove Task by ID\n");
    printf("4. Display All Tasks\n");
    printf("5. Modify Task Priority\n");
    printf("6. Exit\n");
}

task_t* create_task() {
    task_t *task = (task_t*) malloc(sizeof(task_t));
    printf("Enter Task ID: ");
    scanf("%d", &task->id);
    printf("Enter Task Priority (0-139): ");
    scanf("%d", &task->priority);
    printf("Enter Task Description: ");
    scanf(" %[^\n]", task->description);
    printf("Enter Task Duration: ");
    scanf("%d", &task->duration);
    return task;
}

int main() {
    list_t *task_list = list_new();
    int choice, id, new_priority;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                task_t *task = create_task();
                add_task(task_list, task);
                printf("Task added successfully.\n");
                break;
            }
            case 2: {
                printf("Enter Task ID to find: ");
                scanf("%d", &id);
                task_t *task = find_task(task_list, id);
                if (task) {
                    printf("Task Found - ID: %d, Priority: %d, Description: %s, Duration: %d\n",
                           task->id, task->priority, task->description, task->duration);
                } else {
                    printf("Task not found.\n");
                }
                break;
            }
            case 3: {
                printf("Enter Task ID to remove: ");
                scanf("%d", &id);
                remove_task(task_list, id);
                printf("Task removed successfully.\n");
                break;
            }
            case 4:
                display_tasks(task_list);
                break;
            case 5: {
                printf("Enter Task ID to modify priority: ");
                scanf("%d", &id);
                printf("Enter new priority: ");
                scanf("%d", &new_priority);
                modify_task_priority(task_list, id, new_priority);
                printf("Task priority modified.\n");
                break;
            }
            case 6:
                list_free(task_list);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
