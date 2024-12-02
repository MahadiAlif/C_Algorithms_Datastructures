#include <stdio.h>
#include <ctype.h>

#define num_length 10

int verification(char *number, int length);

int main(){

    char pass_num[num_length];
    printf("Please enter the passport number\n");

    fgets(pass_num, num_length, stdin);
    verification(pass_num, num_length);

    if (verification(pass_num, num_length) == -1){
        printf("The passport you entered is invalid\n");
    }
    else if (verification(pass_num, num_length) == 0){
        printf("The passport you enterd is %s\n", pass_num);
    }
    return 0;
}

int verification(char *number, int length) {
    for (int i = 0; i <2; i++){
        if (!isalpha(number[i])){
            return -1;
        }
    }
    for (int i =2; i < length-1; i++){
        if (!isdigit(number[i])){
            return -1;
        }
    }
    return 0;
}
