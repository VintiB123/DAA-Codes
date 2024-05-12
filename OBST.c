//* Optimal Binary Search Tree
//? c[i][j] = min(c[i][k-1] + c[k][j]) + w[i][j]
//? w[i][j] = w[i][j-1] + P[j] + Q[j]

#include<stdio.h>

int key[100];
int P[100];
int Q[100];
int w[100][100];
int c[100][100];
int r[100][100];
int i,j;

void OBST(int n) {
    int k, l;

    for (i = 0; i <= n; i++) {
        w[i][i] = Q[i];
        c[i][i] = 0;
        r[i][i] = 0; 
    }

    for (l = 1; l <= n; l++) {
        for (i = 0; i <= n - l; i++) {
            j = i + l;
            w[i][j] = w[i][j - 1] + P[j] + Q[j];
            c[i][j] = 999; // Initialize c[i][j] to a large value
            for (k = i + 1; k <= j; k++) {
                int cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;         //
                    r[i][j] = k;
                }
            }
        }
    }
}

int main(){
    int n, m;
    P[0] = 0;
    printf("Enter number of keys: ");
    scanf("%d",&n);
    printf("Enter the keys: ");
    for(i=1;i<=n;i++)
        scanf("%d",&key[i]);
    printf("Enter values of P: ");
    for(i=1;i<=n;i++)
        scanf("%d",&P[i]);
    printf("Enter values of Q: ");
    for(i=0;i<=n;i++)
        scanf("%d",&Q[i]);
    
    OBST(n);
    printf("matrix W: \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            if(j<i)
                printf("_ ");
            else 
                printf("%d ",w[i][j]);
        printf("\n");
    }
    printf("matrix C: \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            if(j<i)
                printf("_ ");
            else 
                printf("%d ",c[i][j]);
        printf("\n");
    }
    printf("matrix R: \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            if(j<i)
                printf("_ ");
            else 
                printf("%d ",r[i][j]);
        printf("\n");
    }
    
    printf("\nRoot is: %d",key[r[0][n]]);
    printf("\nMinimum Cost: %d",c[0][n]);
    return 0;
}


