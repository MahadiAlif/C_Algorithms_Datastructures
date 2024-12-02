#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[10];
    char* name[] = {"roberto", "alessandro", "giulia"};
    char* numbers[] = {"989-454-3313", "989-478-4578", "879-789-1145"};

    printf("please enter a name for search in phonebook\n");
    fgets(word, 10, stdin);
    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i<(sizeof(name) /sizeof(name[0])); i++){
        if (strcmp(name[i], word) == 0){
            printf("found %s", numbers[i]);
            return 0;
        }
    }
    printf("not found");
    return 1;
    


}