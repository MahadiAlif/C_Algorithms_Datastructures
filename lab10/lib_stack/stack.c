#include <stdio.h>
#include <stdlib.h>
#include "stack_private.h"

// create a new empty stack
stack_t * stack_new(int size){
    stack_t * sp = (stack_t *)malloc(sizeof(stack_t));
    if(sp == NULL){
        printf("Memory allocation error.\n");
        return NULL;
    }
    sp->head = NULL;
    sp->num = 0;
    return sp;
}

// return the number of elements stored in the stack
int stack_count(stack_t * sp){
    return (sp!=NULL) ? sp->num : 0;
}

// store a new value in the stack (LIFO policy)
int stack_push(stack_t * sp, void * data) {
    if (sp == NULL) {
        return 0;
    }
    node_t * node = (node_t *)malloc(sizeof(node_t));
    if(node == NULL){
        printf("Memory allocation error.\n");
        return -1;
    }
    node->data = data;
    node->next = sp->head;
    sp->head = node;
    sp->num++;
    return 1;
}

// extract a value from the stack (LIFO policy)
int stack_pop(stack_t *sp, void **data){
    if (sp==NULL || sp->head==NULL) {
        return -1;
    }
    node_t * node = sp->head;
    *data = node->data;
    sp->head = node->next;
    free(node);
    sp->num--;
    return 1;
}

// print all the stack elements (LIFO policy)
void stack_print(FILE *fp, stack_t *sp, void (* item_print)(FILE *, void *)){
    node_t *node;
    if (sp != NULL) {
        node = sp->head;
        while (node != NULL) {
            item_print(fp, node->data);
            node = node->next;
            fprintf(fp, "\n");
        }
    }
}

// deallocate all the memory associated to the stack
void stack_free(stack_t *sp, void (* item_free)(void *)){
    node_t *node;

    if (sp != NULL) {
        while (sp->head != NULL) {
            node = sp->head;
            sp->head = node->next;
            if (item_free != NULL) {
                item_free(node->data);
            }
            free(node);
        }
        free(sp);
    }
}
