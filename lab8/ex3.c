#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int count_space(char* s);

int main(){
    char s[100];
    printf("please enter a string\n");
    fgets(s, 100, stdin);
    s[strcspn(s,"\n")] = '\0';
    printf("the number of spaces is %d\n", count_space(s));

    return 0;
}

int count_space(char* s){
    if (s[0] == '\0'){
        return 0;
    }
    else if  (isspace(s[0])){
        return 1 + count_space(s+1);
    }
    else{
        return count_space(s+1);
    }

}