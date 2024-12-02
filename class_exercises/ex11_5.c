#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    int A[5] = {1,3,6,7,5};
    int n = 5;

    // write the code to find the right position k
    // in the sub vector 0 ...i-1
    // where we can place A[i] so that we keep the order

    for (int i= 1; i<n; i++ ){
        int x = A[i];
        int j = i-1;
        while (j>=0 && A[j]>x){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = x;

    }

    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}