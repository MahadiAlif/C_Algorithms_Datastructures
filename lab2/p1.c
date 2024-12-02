#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define length_max 20

void filter(char* input, char* output);
void double_it(char* input, char* output);

int main(){

    char number[length_max];
    char filtered_number[length_max];
    char doubled[length_max];

    //take input
    printf("Enter the string: \n");
    fgets(number, length_max, stdin);
    filter(number, filtered_number);
    double_it(filtered_number, doubled);

    printf("filtered string: %s\n", doubled);
    return 0;


}

void filter(char* input, char* output){

    int j = 0;
    for (int i =0; i<strlen(input); i++){
        if (isdigit(input[i])){
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

}

void double_it(char* input, char* output){
    int length = strlen(input);
    int sum = 0;
    for (int i = 0; i < length; i++){

      int reverse_index = length - i -1;
      int digit = input[reverse_index] - '0';
      
      if (i%2 == 1){
        digit = digit * 2;
        if (digit > 9){
            digit = digit -9;
        }
      }
      output[reverse_index] = digit + '0';
      sum = sum + digit;
      

    }
    if (sum%10 == 0){
        printf("The number is valid %d\n", sum);
    }
    else{
        printf("The number is not valid %d\n", sum);
      }
    output[length] = '\0';

    
}