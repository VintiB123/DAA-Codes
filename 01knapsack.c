#include<stdio.h>
#define MAX 100
#include<math.h>
int max(int a, int b){
    return(a>b? a:b);
}
int main(){
    int w, n,W[MAX][MAX],v[MAX],p[MAX];
    printf("Enter the capacity of the Knapsack: ");
    scanf("%d",&w);
    printf("\nEnter the size of Knapsack weights:");
    scanf("%d",&n);
    // v[0] = 0;
    printf("\nEnter weights along with profits:\n");

    for(int j=1;j<=n;j++){
        scanf("%d %d",&v[j],&p[j]);
    }
    for(int i=0; i<=w;i++){
        W[0][i] = 0;
    }
    for(int j=0 ;j<=n;j++){
            W[j][0] = 0;
        }

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i] > j) {
                W[i][j] = W[i - 1][j];
            } else {
                int temp = p[i] + W[i - 1][j - v[i]];
                W[i][j] = max(W[i-1][j],temp);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

    return 0;
}