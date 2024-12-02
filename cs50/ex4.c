#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char* name;
    char* numbers;
}person;


int main(){
    char word[10];

    person people[3];

    people[0].name  = "alex";
    people[0].numbers = "989-456-1122";
    
    people[1].name = "jones";
    people[1].numbers = "989-411-5565";

    printf("please enter a name for search in phonebook\n");
    fgets(word, 10, stdin);
    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i<2; i++){
        if (strcmp(people[i].name, word) == 0){
            printf("found %s", people[i].numbers);
            return 0;
        }
    }
    printf("not found");
    return 1;
    


}