#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process_string(char* s);
int is_palindrome(char* s, int start, int end);


int main(){
    char s[100];
    printf("please enter a string to check\n");
    fgets(s, 100, stdin);
    s[strcspn(s,"\n")] = '\0';
    process_string(s);
    int result = is_palindrome(s, 0, strlen(s)-1);

    if (result){
        printf("the string is a palindrome");
    }
    else{
        printf("the string is not a palindrome");
    }

    return 0;
}

void process_string(char* s){
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (isalnum(s[i])){
            s[j] = tolower(s[i]);
            j++;
        }
    }
    s[j] = '\0';
}

int is_palindrome(char* s, int start, int end){
    if (start >= end){
        return 1;
    }
    else if (s[start] != s[end]){
        return 0;
    }
    return is_palindrome(s, start+1, end-1);
}