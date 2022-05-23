#include <stdio.h>
#include <stdlib.h>

// knapsack problem

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int Profit[5] = {0, 1, 2, 5, 6}; // first is dummy
    int Weight[5] = {0, 2, 3, 4, 5}; // first is dummy

    int capacity = 8; // total allowed weight of bag
    int n = 4; // Number of items (we use it for indexing)

    int M[4][9]; // table

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){

            if(j == 0 || i == 0){ // dummy item has neither profit nor weight
                M[i][j] = 0;
            }
            else if(Weight[i] <= j){
                M[i][j] = max(Profit[i] + M[i-1][j - Weight[i]], M[i-1][j]);
            }
            else{
                M[i][j] = M[i-1][j];
            }
        }
    }

    
    printf("\nKnapsack Matrix:\n\n");
    for(int i = 0; i <= n; i++){
        if(i != 0){
            printf("Object %d | Profit: %d | Weight: %d|   ", i, Profit[i], Weight[i]);
        }else{
            printf("                                    ");
        }
        for(int j = 0; j <= capacity; j++){
            printf("|%d|", M[i][j]);
        }
        printf("\n");
    }

    
}