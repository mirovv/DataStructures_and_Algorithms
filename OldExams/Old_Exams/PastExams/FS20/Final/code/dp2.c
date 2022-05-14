#include <stdio.h>
#include <string.h>

int max(int x, int y) { if (x > y) return x; else return y; }
int min(int x, int y) { if (x < y) return x; else return y; }

int M[6][6];
int S[6][6];

int maxLen(int m) {
	int maxSize = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) { 
      if (i == 0 || j == 0) {
        if (M[i][j] < 0) { 
          S[i][j] = 1;
          maxSize = 1; 
        }
        else { S[i][j] = 0; }
      } else {
        if (M[i][j] < 0) {                
          S[i][j] = 1 + min( min(S[i-1][j-1], S[i][j-1]),
												     S[i-1][j] );                  
          maxSize = max(maxSize, S[i][j]);                
        }  
      }                          
    }
  }
  return maxSize;
}

int main() {
  int A1[6][6] = {{-1, 1,-2, 0,-4, -2},
                  {-9, 0,-1,-3,-5, 9},
                  {-4,-7,-1, 1,-6, 2},
                  {-6,-5,-4, 3, 4, 1},
                  {-1,-1,-1,-1,-1, -1},
                  { 0, 0, 0, 0, 0, 0}};
  memcpy(M, A1, sizeof(M));
	printf("length of max square of A1 is %d\n", maxLen(6));

  int A2[6][6] = {{ 0, 0,-1, 0, 0,0},
                  {-1,-1,-1,-1, 0,0},
                  {0, -1,-1,-1, 0,0},
                  {0, -1, 0,-1,-1,0},
                  {0, -1,-1,-1,-1,0},
                  {0, -1,-1,-1,-1,0}};
  memcpy(M, A2, sizeof(M));
  printf("length of max square of A2 is %d\n", maxLen(6));

  int A3[6][6] = {{-1, 0,-1, 0,-1, 0},
                  { 0,-1, 0,-1, 0,-1},
                  {-1, 0,-1, 0,-1, 0},
                  { 0,-1, 0,-1, 0,-1},
                  {-1, 0,-1, 0,-1, 0},
                  {0, -1, 0,-1, 0,-1}};
  memcpy(M, A3, sizeof(M));
  printf("length of max square of A3 is %d\n", maxLen(6));

}
	
/*

gcc dp2.c -o dp2; ./dp2

*/
