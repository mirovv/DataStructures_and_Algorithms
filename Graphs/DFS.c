void DFS_tree(int graph[7][7], int v, int n, int visited[]){
    visited[v] = 1;
    int i;
    for(i = 1; i <= n; i++){
        if(graph[v][i] == 1 && visited[i] == 0){
            DFS_tree(graph, i, n, visited); // Explore further 
        }
    }
}

// DFS
int DFS(int graph[7][7], int v, int n){
    int i;
    int visited[n+1]; // array to keep track of visited

    // initialize array to 0
    for(i = 0 ; i <= n; i++){
        visited[i]=0;
    }

    DFS_tree(graph, v, n, visited); // explore vertices

    for(i = 1; i <= n; i++){ // iterate over all vertices
        if(visited[i] == 0){ // this vertex cannot be root
            return 0; 
        }
    }
    return 1;
}