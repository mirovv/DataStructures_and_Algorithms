#include <stdio.h>

#define N 10

int Q[N];
int h;
int t;

int dist[N];

int a[6][6] = {{0,1,0,1,1,0},
               {0,0,1,0,1,0},
               {1,0,0,0,0,0},
               {0,0,0,0,0,1},
               {0,0,0,0,0,0},
               {0,0,0,0,0,0}};

void enqueue(int v) {
	if (h == (t+1)%N) return;
	Q[t] = v;
	t = (t+1)%N;
}

int dequeue() {
	if (h == t) return -1;
	int i = h;
	h = (h+1)%N;
	return Q[i];
}

void khop(int n, int v, int k) {    
  for (int i = 0; i < n; i++) { dist[i] = -1; }
  h = 0; t = 0; dist[v] = 0;
	while (v != -1 && dist[v] < k) {
		for (int i = 0; i < n; i++){
			if (a[v][i] == 1 && dist[i] == -1) {
				dist[i] = dist[v] + 1;
        enqueue(i);
      }
    }
		v = dequeue();
  }
  while (v != -1 && dist[v] == k) {
    printf("%d ", v);
		v = dequeue();
  }
  printf("\n");
}

int main() {
  printf("%d-hop neighbors of %d are ", 2, 1);
	khop(6,0,2); 
}
  
/*

gcc khop.c -o khop; ./khop

*/
