#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}

void printMatrix(int M[4][4], int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int calculate(char M[4][4], int x, int y){
    int V_l[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    int V_r[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    int V_u[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    int V_d[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };


    for (int i = 0; i < x; i++){
        // calculate V_l
        for (int j = 0; j < y; ++j) {
            int t = (j == 0 || M[i][j] == 'W') ? 0 : V_l[i][j - 1]; 
            V_l[i][j] = M[i][j] == 'B' ? t + 1 : t;
        }
        // for (int j = 0; j < y; j++){
        //     int t;
        //     if(j == 0 || M[i][j] == 'W'){
        //         t = 0;
        //     }else{
        //         t = V_l[i][j-1];
        //     }
        //     if(M[i][j] == 'B'){
        //         V_l[i][j] = t + 1;
        //     }else{
        //         V_l[i][j] = t;
        //     }
        // }
        // calculate V_r
        for (int j = y - 1; j >= 0; --j) {
            int t = (j == y - 1 || M[i][j] == 'W') ? 0 : V_r[i][j + 1];
            V_r[i][j] = M[i][j] == 'B' ? t + 1 : t;
        }
        // for (int j = y - 1; j >= 0; j--){
        //     int t;
        //     if(j == y - 1 || M[i][j] == 'W'){
        //         t = 0;
        //     }else{
        //         t = V_r[i][j+1];
        //     }
        //     if(M[i][j] == 'B'){
        //         V_r[i][j] = t + 1;
        //     }else{
        //         V_r[i][j] = t;
        //     }
        // }
    }
    for (int j = 0; j < y; j++){
        // calculate V_u
        for (int i = 0; i < x; ++i) {
            int t = (i == 0 || M[i][j] == 'W') ? 0 : V_u[i - 1][j];
            V_u[i][j] = M[i][j] == 'B' ? t + 1 : t;
        }
        // for (int i = 0; i < x; i++){
        //     int t;
        //     if(i == x - 1 || M[i][j] == 'W'){
        //         t = 0;
        //     }else{
        //         t = V_d[i+1][j];
        //     }
        //     if(M[i][j] == 'B'){
        //         V_d[i][j] = t + 1;
        //     }else{
        //         V_d[i][j] = t;
        //     }
        // }
        // calculate V_d
        for (int i = x - 1; i >= 0; i--){
            int t = (i == x - 1 || M[i][j] == 'W') ? 0 : V_d[i + 1][j];
            V_d[i][j] = M[i][j] == 'B' ? t + 1 : t;
        }
    }

    printf("V_l:\n");
    printMatrix(V_l, 4, 4);
    printf("V_r:\n");
    printMatrix(V_r, 4, 4);
    printf("V_d:\n");
    printMatrix(V_d, 4, 4);
    printf("V_u:\n");
    printMatrix(V_u, 4, 4);

    int res = 0;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (M[i][j] == '0'){
                res = max(res, V_l[i][j] + V_r[i][j] + V_d[i][j] + V_u[i][j]);
            }
        }
    }

    return res;
}


int main(){
    char M[4][4] = {
        {'0', '0', '0', 'B'},
        {'0', 'W', '0', 'o'},
        {'0', '0', 'W', '0'},
        {'B', 'B', '0', '0'}
    };
    int res = calculate(M, 4, 4);
    printf("The amount of killed Bugs is: %d", res);