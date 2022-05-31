int BFS(int graph[7][7], int v, int n){
    int visited[n+1];
    int i;

    // initialize visited array 0
    for (i = 0; i <= n; i++){
        visited[i] = 0;
    }
    node_t *head = NULL;
    enqueue(&head, v); // first vertex in Queue
    int node;
    
    while(!isEmpty(&head)){
        node = dequeue(&head);
        visited[node] = 1; // first vertex visited
        // explore all adj. vertices
        for(i = 1; i <= n; i++){
            if(graph[node][i] == 1 && visited[i] == 0){ // if vertex is adj. and not yet visited --> add to queue
                visited[i] = 1;
                enqueue(&head, i);
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(visited[i] == 0){
            return 0;
        }
    }
    return 1;
}