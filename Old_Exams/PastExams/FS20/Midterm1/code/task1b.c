#include <stdio.h>
#include <math.h>

int sum(int a[], int b[], int n) {
  int s = 0;
	int o = 0;
  for (int i = n - 1; i >= 0; i--) {
    s = s + ((a[i] + b[i] + o) % 10) * (int)pow(10,n-1-i);
    o = (a[i] + b[i] + o) / 10 ;
  }
  return s + o * (int)pow(10,n);
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

gcc task1b.c -o task1b -lm; ./task1b

*/
