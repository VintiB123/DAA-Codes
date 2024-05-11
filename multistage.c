#include<stdio.h>
#include<math.h>
#define MAX 100

int main(){
    int n,min,i,j,k,stages;
    int c[MAX][MAX];
    int cost[MAX],d[MAX],path[MAX];
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the number of stages: ");
    scanf("%d",&stages);
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0){
                c[i][j] = 0;
            }
            else{
                scanf("%d",&c[i][j]);
            }
        }
    }
    cost[n] = 0;
    for(i=n-1 ; i>=1 ; i--){
        min = 5000;
        for(k = i+ 1;k<=n;k++){
            if(c[i][k]!=0 && c[i][k]+cost[k]< min){
                min = c[i][k] + cost[k];
                d[i] = min;
            }
        }
        cost[i] = min;
    }
path[1] = 1;
path[stages] = n;
for(i=2 ; i<stages; i++){
    path[i] = d[path[i-1]];
}
for(i=1;i<n;i++){
    printf("%d->",path[i]);
}

}