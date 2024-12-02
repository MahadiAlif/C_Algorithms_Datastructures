#include <stdio.h>

int is_prime(int_n)
int check_prime(int v[N], int size_of_V)

int main() {
  int prime;

  int divisor;

  printf("Enter a alegedly prime number: ");
  scanf("%d", &prime);

  if (prime <= 1) {
    printf("The number %d is not a valid number\n", prime);
    return -1;
  }

  divisor = 2;

  while ((prime % divisor != 0) && (divisor < prime / 2)) {
    divisor++; // => divisor = divisor + 1  ///// => divisor += 1
  }

  if (prime % divisor == 0) {
    printf("%d is not a prime number!\n", prime);
  } else {
    printf("%d is a prime number!\n", prime);
  }

  return 0;
}
