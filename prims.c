#include<stdio.h>
#define MAX 100
#include<limits.h>

int min_key(int key[],int visited[],int n){

    int minimum = INT_MAX, min;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0 && key[i]<minimum){
            minimum= key[i];
            min = i;
        }
    }
    return min;

}

void prim(int G[][MAX],int n){
    int parent[n],key[n],visited[n],edge;
    
    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        visited[i]= 0;
    }
    key[0]= 0;
    parent[0] = -1;
    for(int k=0;k<n-1;k++){
        edge = min_key(key,visited,n);
        visited[edge]= 1;
        for(int v=0;v<n;v++){
            if(G[edge][v]>0 && visited[v]==0 && G[edge][v] < key[v]){
                key[v] = G[edge][v];
                parent[v] = edge;
            }
        }
    }
    printf("Vertex    Parent  Weight\n");
for(int i = 1; i < n; i++){
    printf("%d - %d  %d\n", i, parent[i], key[i]);

}
    }
int main(){
int n,G[MAX][MAX];
printf("Enter the number of nodes: ");
scanf("%d",&n);
for(int i=0; i<n; i++){
    for(int j=0;j<n;j++){
        scanf("%d",&G[i][j]);
    }
}
prim(G,n);



return 0;
}