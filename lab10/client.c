#include <stdio.h>
#include <ctype.h>
#include "lib_stack/stack.h"
#include "item.h"

#define SIZE 50
#define MAX  20

int main(void){
    char command[MAX];
    stack_t * sp = NULL;
    void * data;
    int stop = 0;

    do{
        fprintf(stdout, "\nAvailable commands:\n");
        fprintf(stdout, "  (N)ew\n  (I)nsert\n");
        fprintf(stdout, "  (E)xtract\n  (D)isplay\n");
        fprintf(stdout, "  (S)top\nChoice: ");
        scanf("%s", command);

        switch (tolower(command[0])) {
            case 'n':
                stack_free(sp, item_free);
                sp = stack_new(SIZE);
                fprintf(stdout, "New stack correctly created.\n");
                break;
            case 'i':
                fprintf(stdout, "Input data: ");
                item_read(stdin, (void **)&data);
                if (!stack_push(sp, (void *)data)) {
                    fprintf(stderr, "Error in push!\n");
                }
                else {
                fprintf(stdout, "Data correctly inserted.\n");
                }
                break;
            case 'e':
                if (!stack_pop(sp, (void **)&data)) {
                    fprintf(stderr, "Error in pop!\n");
                }
                else {
                    fprintf(stdout, "Extracted data: ");
                    item_print(stdout, (void *)data);
                    fprintf(stdout, "\n");
                    item_free(data);
                }
                break;
            case 'd':
                stack_print(stdout, sp, item_print);
                break;
            case 's':
                stop = 1;
                break;
            default:
                fprintf(stderr, "Unknown command!\n");
                break;
        }
    } while (!stop);

    stack_free(sp, item_free);
    return 0;
}
