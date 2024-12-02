#ifndef _ITEM
#define _ITEM

#include <stdio.h>

/* function prototypes */
int item_read(FILE *, void **);
void item_print(FILE *, void *);
int item_compare(void *, void *);
void item_free(void *);

#endif
