#include <stdio.h>

int search(int a[], int n) {   
  int l = 0;
  int r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] == a[l]) {
       if (a[l] < a[r]) { l++; }
       else { r--; }
    }
    else if (a[mid] > a[mid - 1]) { l = mid; }
    else { r = mid - 1; }
  }
  return a[l];
}

int search2(int a[], int n) {
  int l = 0;
  int r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (l == m && a[m] < a[m+1]) { l = r; }
    else if (l == m) { r = l; }
    else if (a[m-1] > a[m]) { r = m; }
    else { l = m; }
  }
  return a[l];
}

int main() {
  int B1[] = {6,3,2};
  printf("largest number is %d (%d)\n", search(B1,3), search2(B1,3));
  int B2[] = {6,13,25};
  printf("largest number is %d (%d)\n", search(B2,3), search2(B2,3));
  int B3[] = {1,6,3};
  printf("largest number is %d (%d)\n", search(B3,3), search2(B3,3));
  int B4[] = {6,2};
  printf("largest number is %d (%d)\n", search(B4,2), search2(B4,2));
  int B5[] = {6,25};
  printf("largest number is %d (%d)\n", search(B5,2), search2(B5,2));
  int B6[] = {3};
  printf("largest number is %d (%d)\n", search(B6,1), search2(B6,1));
  int B7[] = {0,7,6,3,1};                                           
  printf("largest number is %d (%d)\n", search(B7,5), search2(B7,5));
  int B8[] = {0,7,8,3,1};
  printf("largest number is %d (%d)\n", search(B8,5), search2(B8,5));
}
  
/*

gcc task2.c -o task2; ./task2

*/
