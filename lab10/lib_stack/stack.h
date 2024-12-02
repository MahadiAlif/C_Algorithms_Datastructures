#ifndef _STACK_PUBLIC
#define _STACK_PUBLIC

#include <stdio.h>

/* macro definition */
#define stack_empty(sp) (stack_count(sp) == 0)

/* type declarations */
typedef struct stack stack_t;

/* function prototypes */
stack_t * stack_new(int);
int stack_count(stack_t *);
int stack_push(stack_t *, void *);
int stack_pop(stack_t *, void **);
void stack_print(FILE *, stack_t *, void (* item_print)(FILE *, void *));
void stack_free(stack_t *, void (* item_free)(void *));

#endif
