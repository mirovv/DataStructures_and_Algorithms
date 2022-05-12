#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// void DNumbersl(int i, int n){
//     int dNum = i;
//     if (n == 0){
//         return;
//     }
//     int count = 0;
//     int stellen = 1;
//     while(stellen < i){
//         stellen = stellen * 10;
//         count++;
//     }
//     double f = pow(10, count-1);
//     int t = floor(f);

//     dNum += dNum % 10;

//     for (int j = 1; j < count; j++){
//         double k = pow(10, count-1);
//         int p = floor(f);
//         dNum += dNum / p;
//     }

//     printf("D-Number %d ---> %d\n", i, dNum);
//     n--;
//     DNumbersl(dNum, n);

// }
int d(int i) {
    int sum = i; 
    while (i != 0) {
        sum = sum + i % 10; 
        i = i / 10;
    }
    return sum;
}

void DNumbers(int i, int n) {
    int k;
    for (k = 1; k <= n; k++) { 
        i = d(i);
        printf("%d ", i);
    }
    printf("\n");
}

int main(){
    int i = 81;
    int n = 4;

    DNumbers(i, n);

    return 1;
}