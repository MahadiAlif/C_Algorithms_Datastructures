#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define num_length 20


int main(){

    char pass_num[num_length];
    printf("Please enter the passport number\n");

    fgets(pass_num, num_length, stdin);

    pass_num[strcspn(pass_num, "\n")] = 0;

    int length = strlen(pass_num);  

    if (length != 9){
        printf("The passport you entered is invalid\n");
    }
    else{
        printf("The passport you entered is %s\n", pass_num);
    }

    



}


