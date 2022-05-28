#include <stdio.h>
#include <stdlib.h>

#define m 4

int A[m][m] ={
    {-1, 0, -1, 0},
    {-1, 0, -1, -1},
    {-1, -1, -1, 0},
    {-1, -1, -1, 0}
};

int min(int a, int b){
    return a<b?a:b;
}

int maxLen(){
    int X[m][m];
    for(int i = 0; i<m; i++){
        for(int j=0; j<m; j++){
            if(j == 0 || i == 0){
                if(A[i][j] < 0){
                    X[i][j] = 1;
                }else{
                    X[i][j] = 0;
                }
            }else{
                if(A[i][j] >= 0){
                    X[i][j] = 0;
                }else{
                    X[i][j] = 1 + min(min(X[i-1][j-1], X[i][j-1]), X[i-1][j]);
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            if(X[i][j]>res){
                res = X[i][j];
            }
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            printf("%d ", X[i][j]);
        }
        printf("\n");
    }
    return res;
}

int main(){
    printf("Max: %d", maxLen());
    
}