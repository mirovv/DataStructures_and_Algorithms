#include <stdio.h>

// solution with auxiliary array
int sum(int a[], int b[], int n) {
  int c[n + 1];
  for (int i = n - 1; i >= 0; i--) {
    c[i] = (c[i + 1] + a[i] + b[i]) / 10;
    c[i+1] = (c[i+1] + a[i] + b[i]) % 10;
  }
  int sum = 0;
  for (int i = 0 ; i <= n; i++) {
    sum = 10 * sum + c[i];
  }
  return sum;
}

void main() {
  int A1[] = {1,2,3};
  int A2[] = {5,5,8};
  printf("sum of A1 and A2 is %d\n", sum(A1,A2,3));

  int A3[] = {7,2,3};
  int A4[] = {5,5,8};
  printf("sum of A3 and A4 is %d\n", sum(A3,A4,3));
}
	
/*

gcc task1.c -o task1; ./task1

*/
