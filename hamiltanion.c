#include<stdio.h>
#define MAX 100
#include<stdbool.h>

bool G[MAX][MAX];
int x[MAX]= {0},n;
void print(int x[],int n){
    for(int i= 1 ; i<=n;i++){
        printf("%d->",x[i]);
    }
    printf("\n");
}
void Hamiltonion(int k,int n){
    do{
        NextVertex(k);
        if(x[k]==0)
            return 0;
        if(k==n)
            print(x,n);

        else
            Hamiltonion(k+1,n);
    }while(true);
    
}
void NextVertex(int k){
    int j;
    do
    {
        x[k] = (x[k] + 1) % (n+1);
        if(x[k]==0){
            return;
        }
        if(G[x[k-1]][x[k]] != 0){
            for( j=1 ; j<= k-1;j++){
                if(x[j]==x[k])
                    break;
            }
            if(j==k){
                if(k<n || ((k==n) && G[x[n]][x[1]]!=0))
                    return;
            }
        }
    } while (true);

}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix: ");
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++){
            scanf("%d",&G[i][j]);
        }

    }
    x[1] = 1;
    Hamiltonion(2,n);
return 0;
}