#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int random_num, num=0, count =0;
    srand(time(NULL));
    random_num = rand() % 101;
    printf("I have chosen a secret number between 1 and 100\n");
    
    do{
        scanf("%d", &num);
        printf("Your guess: %d\n", num);
        count ++;
        if (num>random_num){
            printf("Hint: Too High\n");
        }
        else if(num<random_num){
            printf("Hint: Too low\n");
        }
        else{
        printf("Hint: Just right!\n");
        printf("Congratulations! you guessed the number in %d tries\n", count);
        }
    }
    while(num!= random_num);
   
        
    return 0;
}



