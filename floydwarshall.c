#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<math.h>
#define MAX 100

int min(int a,int b){
    return a > b ? b : a;
}

int arr[MAX][MAX];

int main(){
    int n,i,j,k;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter matrix and if distance is infinity enter -1\n");
    for(i=0 ; i<n ; i++){
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==-1){
                arr[i][j]= 10000;
            }
            if(i==j){
                arr[i][j] = 0;
            }
        }
        
    }

    for(k=0;k<n;k++){

        for(i=0 ; i< n ; i++){
            for ( j = 0; j <n; j++)
            {
              if(i!=j && i!=k && j!=k) {
                arr[i][j] =   min(arr[i][j],arr[i][k]+arr[k][j]);
              }
                
            }
            
        }
    }

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}
