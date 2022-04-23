#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

void neighbors(int edges[7][2], int m, int n, int v, int k){    

  int graph[n + 1][n + 1];

  for(int i = 0; i < m; i++) {
    graph[edges[i][0]][edges[i][1]] += 1;
  }

  int distance[n + 1];   // visited[i] means minimum distance from v to i .
  node_t *head = NULL;
  
  enqueue(&head, v);
  distance[v] = -1;

  int steps =  1; 
  // k times BFS
  while(steps <= k) {
    node_t *new_head = NULL;
    int node;
    while ((node=dequeue(&head)) > 0) {
      for(int i = 1; i <= n; i++){
        if(graph[node][i] > 0 && distance[i] == 0) {
           distance[i] = steps; // update minimum distance.
           enqueue(&new_head, i);
        }
      }
    }
    head = new_head;
    steps += 1;
  }
  printf("%d-hop neighbors of node %d is: \n", k, v);
  for(int i = 1; i <=n ; i++) {
    if(distance[i] == k) {
      printf("node %d \n", i);
    }
  }
}

int main() {
  int v = 1; 
  int n = 7;
  int m = 7;
  int k = 2;
  int edges[][2] = {{1,2},{1,4},{1,5},{2,3},{2,5},{3,1},{4,6}};
 
  neighbors(edges, m, n, v, k);
  
  return 0;
}
  
/*

gcc graph.c -o graph; ./graph

*/
