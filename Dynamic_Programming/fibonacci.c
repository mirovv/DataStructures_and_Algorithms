#include <stdio.h>
#include <stdlib.h>

// O(n^2)

int recursiveFibonacci(int n){
    if (n < 2){
        return n;
    }else{
        return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
}

// O(n) (uses much space)

int linearFibonacci(int n){
    int A[n+1];
    A[0] = 0;
    A[1] = 1;
    for (int i = 2; i <= n; i++){
        A[i] = A[i-1] + A[i-2];
    }
    return A[n];
}

// O(n) (uses less space)

int smoothFibonacci(int n){
    int s = 0;
    int t = 1;
    for(int i = 1; i < n; i++){
        int r = t;
        t = s + t;
        s = r;
    }
    return t;
}

int main(){
    printf("%d\n", recursiveFibonacci(11));
    printf("%d\n", linearFibonacci(11));
    printf("%d\n", smoothFibonacci(11));
}