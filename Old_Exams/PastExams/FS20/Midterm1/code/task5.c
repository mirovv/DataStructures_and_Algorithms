#include <stdio.h> 
	
int countElem(int A[], int num, int l, int r) {
  int count = 0;
  int i = 0;
  for (i=l; i<=r; i++) {
    if (A[i] == num) { count++; }
  }
  return count;
}

int halfElement(int A[], int l, int r) {
  if (l == r) { return A[l]; }
  int mid = (l+r)/2;
  int left = halfElement(A, l, mid);
  int right = halfElement(A, mid+1, r);
  if (left == right) { return left; }
  int leftCount = countElem(A, left, l, r);
  int rightCount = countElem(A, right, l, r);
  if (leftCount>=rightCount) { return left; }
  return right;
}
    
void main(){
  int A[] = {4,4,5,6,4,4,3,4,4};
  int idx = halfElement(A,0,9);
  printf("Half Element is: %d", idx);
	int A[] = {2,1,2,3,2,4,2,5,2,6,2,7};
  idx = halfElement(A,0,9);
  printf("Half Element is: %d", idx);
}
