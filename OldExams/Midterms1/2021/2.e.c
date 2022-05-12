#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int adjacentMultiple(int n){
    int i, a, b;
    for (i = 1; i < n/2; i++){
        if (i * (i+1) == n){
            return 1;
        }
    }
    return -1;
    
}
int B_adjacentMultiple(int n){
    double x = pow(n, 0.5);
    int i = floor(x);
    if ((i+1) * i == n){
        return 1;
    }
    return -1;
}

int main(){
    int n = 25;


    printf("%d ---> %d\n", 25, adjacentMultiple(25));
    printf("%d ---> %d\n", 56, adjacentMultiple(56));
    printf("%d ---> %d\n", 25, B_adjacentMultiple(25));
    printf("%d ---> %d\n", 56, B_adjacentMultiple(56));


    return 1;
}