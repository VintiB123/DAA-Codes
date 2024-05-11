// cost[i,j] = min{cost[i,k]+cost[k+1,j]} + di-1*dk*dj
//for(int diag=1; diag<=n-1;diag++){
    //    for(i=1;i<=n-diag;i++){
      //      j = diag +i;
#include<stdio.h>
#define MAX 100

int main(){
    int i,j,p[MAX],M[MAX][MAX],n,r[MAX][MAX];
    printf("Enter the number of Matrices ");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++){
        M[i][i] = 0;
    }
    for(int diag=1; diag<=n-1;diag++){
        for(i=1;i<=n-diag;i++){
            j = diag +i;
            M[i][j] = 10000;
            for(int k=1;k<j;k++){
                if(M[i][j]> (M[i][k]+ M[k+1][j]+ (p[i-1]*p[k]*p[j]))){
                    M[i][j] = M[i][k]+ M[k+1][j]+ p[i-1]*p[k]*p[j];
                    r[i][j] = k;
                }
                else{
                    M[i][j] = M[i][j];
                    r[i][j] =k;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
return 0;
}