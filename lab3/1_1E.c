#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char response = 'Y';
    while (response != 'N'){
        printf("Digit (Y) to continue and (N) to quit: \n");
        scanf(" %c", &response);
        response = toupper(response);
        if (response == 'Y'){
            printf("Continuing the application..\n");
        }
        else{
            printf("Quitting...\n");
        }
    }
    return 0;
}