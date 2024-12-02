#include "task_manager.h"

// Create a new list
list_t* list_new() {
    list_t *list = (list_t*) malloc(sizeof(list_t));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

// Free the list and its elements
void list_free(list_t *list) {
    node_t *current = list->head;
    while (current) {
        node_t *next = current->next;
        free(current->task);
        free(current);
        current = next;
    }
    free(list);
}

// Add task in sorted order based on priority
void add_task(list_t *list, task_t *task) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->task = task;
    new_node->next = new_node->prev = NULL;

    if (!list->head || task->priority < list->head->task->priority) {
        new_node->next = list->head;
        if (list->head) list->head->prev = new_node;
        list->head = new_node;
        if (!list->tail) list->tail = new_node;
    } else {
        node_t *current = list->head;
        while (current->next && current->next->task->priority <= task->priority)
            current = current->next;

        new_node->next = current->next;
        new_node->prev = current;
        if (current->next) current->next->prev = new_node;
        current->next = new_node;
        if (!new_node->next) list->tail = new_node;
    }
    list->size++;
}

// Find task by ID
task_t* find_task(list_t *list, int id) {
    node_t *current = list->head;
    while (current) {
        if (current->task->id == id) return current->task;
        current = current->next;
    }
    return NULL;
}

// Remove task by ID
void remove_task(list_t *list, int id) {
    node_t *current = list->head;
    while (current && current->task->id != id)
        current = current->next;

    if (current) {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == list->head) list->head = current->next;
        if (current == list->tail) list->tail = current->prev;
        free(current->task);
        free(current);
        list->size--;
    }
}

// Display tasks
void display_tasks(list_t *list) {
    node_t *current = list->head;
    while (current) {
        printf("ID: %d, Priority: %d, Description: %s, Duration: %d\n",
               current->task->id, current->task->priority,
               current->task->description, current->task->duration);
        current = current->next;
    }
}

// Modify priority of a task
void modify_task_priority(list_t *list, int id, int new_priority) {
    task_t *task = find_task(list, id);
    if (task) {
        remove_task(list, id);
        task->priority = new_priority;
        add_task(list, task);
    }
}
