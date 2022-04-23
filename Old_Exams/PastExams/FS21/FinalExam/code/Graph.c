#include <stdio.h>

#define N 5

int Q[N];
int h=0;
int t=0;

int dist[N];
int color[N]; // W=0, G=1,B=2
int pred[N];

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

int isEmpty(){
	if(h==t) return 1;
	return 0;
}

void BiQuad(int graph[N][N],int s) { 
  int i=0,u=0,k=0,q=0, neighbors[N],tmpN=-1;
  for (i = 0; i < N; i++) { dist[i] = -1;color[i]=0;pred[i]=-1;neighbors[i]=-1;}
  dist[s] = 0; color[s] = 1;
  enqueue(s);
  while(!isEmpty()){
  	int v = dequeue();
  	int count = 0,tmpN=-1;
	for(u=0;u<N;u++){
  		if(graph[v][u]==1){
		  	if(color[u] == 0){
		  		color[u]=1; dist[u] = dist[v]+1; pred[u]=v;
	  			enqueue(u); 
			}else if(color[u]==2 && dist[u]<=dist[v]){
				neighbors[u]=1;
				count=count + 1;
				tmpN=u;
			}
		}
	}
	if(count>1){
		for(u=0;u<N;u++){
			for(q=u+1;q<N;q++){
				if(neighbors[u]==1 && neighbors[q]==1){
					int fourthVertex = -1, distDiff = dist[q]-dist[u];
					if(distDiff==0 || distDiff==1 || distDiff==-1){
						if(graph[u][pred[q]]==1){
							fourthVertex = pred[q];
						}else if(graph[q][pred[u]]==1){
							fourthVertex = pred[u];
						}
					}
					if(fourthVertex!=-1){
						printf("BiQuad Subgraph: %d, %d, %d, %d \n",fourthVertex,q,v,u);
					}
					if(distDiff == 0){
						for(k=0;k<N;k++){
							if(k!=pred[q] && color[k]==2 && graph[q][k]==1 && graph[u][k]==1){
								printf("BiQuad Subgraph: %d, %d, %d, %d \n",k,q,v,u); 
							} 
						}
					}		
				}
			}
			neighbors[u]=-1;
		}
	}else if(count == 1){
		 neighbors[tmpN] = -1;
	}
	color[v]=2;	  
  }
}


int main() {
  //int numVertices = 8; 
int graph[N][N] = {{0,1,1,0,0},
	{1,0,1,1,0},
	{1,1,0,0,1},
	{0,1,0,0,1},
    {0,0,1,1,0}};
   
  /*int graph[N][N] = {{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
    {0,1,1,1,0}};*/

	/*int graph[N][N] = {{0,1,1,1,1,1,1,0},
               {1,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,1},
			   {1,0,0,0,0,0,0,1},
               {0,1,1,1,1,1,1,0}};*/

  /*int graph[N][N] = {{0,1,1,0,0,0,0,0},
               {1,0,0,1,0,0,0,0},
               {1,0,0,1,1,0,0,0},
               {0,1,1,0,0,1,0,0},
               {0,0,1,0,0,1,1,1},
               {0,0,0,1,1,0,0,1},
			   {0,0,0,0,1,0,0,1},
               {0,0,0,0,1,1,1,0}};*/
    int i;
	for(i=0;i<N;i++){
		printf("Starting Node: %d \n",i);
		BiQuad(graph,i); 
	}           

}
