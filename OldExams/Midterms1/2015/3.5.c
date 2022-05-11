#include <stdlib.h>
#include <stdio.h>


int ternarySearch(int A[], int l, int r, int x){
    int m1 = (l + r)/3;
    int m2 = m1 * 2;
    if (l <= r){
        if (l == r){
            if (A[l] == x){
                return l;
            }else{
                return -1;
            }
        }
        if (A[m1] >= x){
            return ternarySearch(A, l, m1, x);
        }
        if (A[m2] >= x){
            return ternarySearch(A, m1+1, m2, x);
        }else{
            return ternarySearch(A, m2+1, r-1, x);
        }
    }
    return -1;
}

int main(){
    int A[] = {14,21,35,42,56,57,73,81,90};
    int n = 9;

    printf("%d", ternarySearch(A, 0, n, 35));


    return 1;
}