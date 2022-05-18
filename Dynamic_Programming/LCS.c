#include <stdio.h>
#include <stdlib.h>

int recursiveLCS(int i, int j, char X[], char Y[]){
    if (i == -1 || j == -1){
        return 0;
    }
    else if(X[i] == Y[j]){
        return 1 + recursiveLCS(i-1, j-1, X, Y);
    }else{
        if (recursiveLCS(i-1, j, X, Y) <= recursiveLCS(i, j-1, X, Y)){
            return recursiveLCS(i, j-1, X, Y);
        }else{
            return recursiveLCS(i-1, j, X, Y);
        }
    }
}

int memoLCS(int i, int j, int C[i][j], char X[], char Y[]){
    printf("i: %d, j: %d\n", i,j);
    if (i == -1 || j == -1){
        printf("i or j is -1  i: %d   j:%d\n", i, j);
        return 0;
    }
    else if (C[i][j] != -1){
        printf("already in lookup  i: %d   j:%d\n", i, j);
        return C[i][j];
    }
    else if (X[i] == Y[j]){
        printf("Match i: %d   j:%d\n", i, j);
        C[i][j] = memoLCS(i-1, j-1, C, X, Y) + 1;
        return C[i][j];
    }else{
        int left = memoLCS(i, j-1, C, X, Y);
        int up = memoLCS(i-1, j, C, X, Y);
        if(left <= up){
            C[i][j] = up;
        }else{
            C[i][j] = left;
        }
        return C[i][j];
    }
}

int main(){
    // recursion
    char X[] = {'G', 'T', 'A', 'T', 'C', 'T'};
    char Y[] = {'G', 'G', 'T', 'T', 'C', 'A', 'T'};
    int size_x = sizeof(X) / sizeof(char);
    int size_y = sizeof(Y) / sizeof(char);
    int n = recursiveLCS(size_x, size_y, X, Y);
    printf("Recursive: %d\n", n);

    // memoization
    printf("Size X: %d, Size Y: %d\n", size_x, size_y);
    int C[size_x][size_y];
    // init C Matrix with dummy values
    for (int i = 0; i < size_x; i++){
        for (int j = 0; j < size_y; j++){
            C[i][j] = -1;
        }
    }
    int max = memoLCS(size_x-1, size_y-1, C, X, Y);
    printf("Memoization: %d\n", max);


    for (int i = 0; i < size_x; i++){
        for (int j = 0; j < size_y; j++){
            printf("| %d |", C[i][j]);
        }
        printf("\n");
    }
    return 1;
}