#include <stdio.h>
#include <string.h>

int M[4][4];
int S[4][4];

void computeS(int m, int n) {
  if(M[0][0] == 0) {
    S[0][0] = 1;
  }
  for (int i = 1; i < n; i++) {
    if(M[0][i] == 0) {
      S[0][i] = S[0][i - 1] + 1;
    } else{
       S[0][i] = S[0][i - 1];
    }
  }
  for (int i = 1; i < m; i++) {
    if (M[i][0] == 0) {
      S[i][0] = S[i - 1][0] + 1;
    } else {
       S[i][0] = S[i - 1][0];
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) { 
      if (M[i][j] == 0) {
        S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + 1;
      } else {
        S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
      }
    }
  }
}

void printMatrix(int m, int n){
  for (int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", S[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int A1[4][4] = {{12, 0, 4, -5},
                  {11, 9, 0, 3},
                  {0 ,-4, 0, 8},
                  {11, 9, 0, 3}};
  memcpy(M, A1, sizeof(M));
	computeS(4, 4);
  printMatrix(4, 4);

}
	
/*

gcc dp.c -o dp; ./dp

*/
