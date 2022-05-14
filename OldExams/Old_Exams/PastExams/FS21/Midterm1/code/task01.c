#include <stdio.h>

int d(int i) {
  int sum = i;
  while (i != 0) {
    sum = sum + i % 10;
    i = i / 10;
  }
  return sum;
}

void Dnumbers(int i, int n) {
  int k, d_i;
  for (k = 1; k <= n; k++) {
    i = d(i);
    printf("%d ", i);
  }
  printf("\n");
}

int main() {
  int i, n;
  printf("Please enter the integer i: ");
  scanf("%d", &i);
  printf("Please enter the integer n: ");
  scanf("%d", &n);
  Dnumbers(i, n);
}