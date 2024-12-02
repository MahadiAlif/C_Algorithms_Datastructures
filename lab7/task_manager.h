#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int priority;
    char description[100];
    int duration;
} task_t;

typedef struct node {
    task_t *task;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t* list_new();
void list_free(list_t *list);
void add_task(list_t *list, task_t *task);
task_t* find_task(list_t *list, int id);
void remove_task(list_t *list, int id);
void display_tasks(list_t *list);
void modify_task_priority(list_t *list, int id, int new_priority);

#endif
