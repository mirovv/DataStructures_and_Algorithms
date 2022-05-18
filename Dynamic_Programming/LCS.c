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

int main(){
    char X[] = {'A', 'Q', 'H', 'T', '\0'};
    char Y[] = {'W', 'R', 'P', 'L', '\0'};
    int n = recursiveLCS(3,3,X,Y);
    printf("%d", n);

    return 1;
}