#include <stdio.h>
#include <stdlib.h>

int recursiveLCS(int i, int j, char X[], char Y[]){
    if (i == 0 || j == 0){
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
    if (i == 0 || j == 0){
        return 0;
    }
    else if (C[i][j] != -1){
        return C[i][j];
    }
    else if (X[i] == Y[j]){
        C[i][j] = memoLCS(i-1, j-1, C, X, Y) + 1;
        return C[i][j];
    }else{
        if(memoLCS(i-1, j, C, X, Y) <= memoLCS(i, j-1, C, X, Y)){
            C[i][j] = memoLCS(i, j-1, C, X, Y);
        }else{
            C[i][j] = memoLCS(i-1, j, C, X, Y);
        }
        return C[i][j];
    }
}

int main(){
    // recursion
    char X[] = {'G', 'T', 'A', 'T', 'C', 'T', '\0'};
    char Y[] = {'G', 'G', 'T', 'T', 'C', 'A', 'T', '\0'};
    int n = recursiveLCS(5, 6, X, Y);
    printf("Recursive: %d\n", n);

    // memoization
    int x = sizeof(X) / sizeof(char) -1;
    int y = sizeof(Y) / sizeof(char) -1;
    int C[x][y];
    // init C Matrix with dummy values
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            C[i][j] = -1;
        }
    }
    int max = memoLCS(x-1, y-1, C, X, Y);
    printf("Memoization: %d\n", max);


    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("| %d |", C[i][j]);
        }
        printf("\n");
    }


    return 1;
}