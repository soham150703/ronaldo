    while(!isempty()){
        int node = pop();
        printf("%d \n", node);
        
        for(int  i = 0 ; i < numvertice ; i++){
            if(graph[node][i] == 1 && visited[i] == 0){
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int numvertice , startvertex;
    int graph[MAX][MAX], visited[MAX];
    
    for(int i = 0 ; i < MAX ; i++){
        visited[i] = 0 ;
    }
    printf("Enter the number of vertices: ");
    scanf("%d", &numvertice);
    
    printf("Enter the adjacency matrix for the followiin graph: \n");
        for(int i = 0 ; i <numvertice; i++){
            for(int j = 0 ; j < numvertice; j++){
                scanf("%d",&graph[i][j]);
            }
        }
        
    printf("Enter the starting vertex for the graph:- ");
    scanf("%d",&startvertex);
    
    DFS(graph, visited, startvertex, numvertice);
}
