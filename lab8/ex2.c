#include <stdio.h>

int catalan(int n);

int main(){
    int n = 10;
    for (int i = 0; i < n; i++){
        printf("%dth catalan number is %d\n", i+1, catalan(i));
    }
    
    return 0;
}

int catalan(int n){
    
    if (n == 0){
        return 1;
    }
    int result = 0;
        for (int i = 0; i < n; i++){
            result += catalan(i) * catalan(n-i-1);
    
    }return result;

}