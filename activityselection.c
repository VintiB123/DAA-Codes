#include<stdio.h>
#define MAX 100

int st[MAX],et[MAX],act[MAX];

int main(){
    int i,j,temp,n;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        act[i] = i+1;
        printf("\nActivity %d",i+1);
        printf("\nStart Time:");
        scanf("%d",&st[i]);
        printf("\nEnd Time:");
        scanf("%d",&et[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(et[j]>et[j+1]){
                
                temp = act[j];
                act[j] = act[j+1];
                act[j+1] = temp;
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
                temp = et[j];
                et[j] = et[j+1];
                et[j+1] = temp;
            }
        }
    }
    printf("\nIndex: ");
    for(i= 0 ;i<n;i++){
        printf("%d ",act[i]);
    }
    printf("\nActivity order : A%d-\t",act[0]);
    j = 0;
    for(i=1;i<n;i++){
        if(st[i]>=et[j]){
            printf("A%d-\t",act[i]);
            j = i;
        }
    }


    return 0;
}