#include<stdio.h>
#define MAX 100
int n,d[MAX],profits[MAX],job[MAX],seq[MAX];

int sort(){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(profits[i]>profits[j]){
                temp = profits[i];
                profits[i]= profits[j];
                profits[j] = temp;
                 temp = d[i];
                d[i]= d[j];
                d[j] = temp;
                 temp = job[i];
                job[i]= job[j];
                job[j] = temp;
            }
        }
    }
}
int main(){
    int maxd=0;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    printf("Enter the job profits with deadline: \n");
    for(int i = 0 ; i<n;i++){
        scanf("%d %d",&profits[i],&d[i]);
        job[i] = i+1;
        if(d[i]> maxd)
            maxd= d[i];
    }
    for(int i=0;i<maxd;i++){
        seq[i] = 0;
    }
    
    sort();
    for(int i=0;i<n;i++){
        for(int j=d[i]-1;j>=0;j--){
            if(seq[j]==0){
                seq[j] = job[i];
                break;
            }
            
        }
        
    }

    for(int i=0;i<maxd;i++){
        if(seq[i]!=0){
        printf("J%d->",seq[i]);    
        }
        
    }

}