#include <limits.h>
#include <stdio.h>

#define num_element 10

int main(){

    int ar_new[num_element], smallest = INT_MAX, biggest = INT_MIN;
    char message[100];

    printf("Enter a message of your choice\n");
    scanf("%[^\n]s", message);


    for (int i = 0; i<10 ; i++ ){
        printf("Please enter a number\n");
        scanf("%d", &ar_new[i]);

        if (ar_new[i]>= biggest){
            biggest = ar_new[i];
        }
        else{
            if (ar_new[i]<= smallest){
            smallest = ar_new[i];
        }
        }
    }

    printf("%s\n", message);
    printf("The biggest number is %d\n", biggest);
    printf("The smallest number is %d\n", smallest);
    return 0;
}