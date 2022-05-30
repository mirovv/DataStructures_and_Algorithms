#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}

int LPS(char W[], int n){
    int R[n-1][n-1];
    int i, j, k;

    // Diagonale ist immer 1 (einzelner Buchstabe automatisch palindrom)
    for(i=0;i<n;i++){
        for(j=0; j<n;j++){
            if(j == i){
                R[i][i] = 1;
            }else{
                R[i][j] = 0;
            }
        }
    }
    for(k=2;k<=n;k++){
        for(i=0;i<n-k+1;i++){
            j = i + k - 1;
            if(W[i]==W[j] && k == 2){
                R[i][j] = 2;
            }else if(W[i]==W[j]){
                R[i][j] = 2 + R[i+1][j-1];
            }else{
                R[i][j] = max(R[i+1][j], R[i][j-1]);
            }
        }
    }
    return R[0][n-1];
}

int main(){
    char W[] = "beste";
    int n = 6;
    printf("Max: %d", LPS(W,n));
}