#include<stdio.h>
#include<conio.h>
#define MAX 100
void quicksort (int a[],int lb, int ub);
int partition(int a[],int lb,int ub);

void quicksort (int a[],int lb, int ub){
    int loc;
    if(lb<ub){
        loc = partition(a,lb,ub);
        quicksort(a,lb,(loc-1));
        quicksort(a,(loc+1),ub);

    }
}
int partition(int a[],int lb,int ub){
    int pivot,start, end, temp;
    pivot = a[lb];
    start = lb;
    end = ub;
    while(start < end){
        while(a[start]<=pivot)
            start ++;
        
        while(a[end]>pivot)
            end--;
        if(start<end){
            temp = a[start];
            a[start]= a[end];
            a[end] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
int main(){
    int a[MAX],i,ub,lb,n ;
    printf("\nEnter length of array: ");
    scanf("%d",&n);
    printf("\nEnter array of size %d:",n);
    for(i=0 ; i< n ;i++){
        scanf("%d",&a[i]);
    }
    printf("\nArray before sorting: \n");
    for(i=0 ; i< n ;i++){
        printf("%d  ",a[i]);
    }
    lb= 0;
    ub = n-1 ;
    quicksort(a,lb,ub);
    printf("\nArray after sorting: \n");
    for(i=0 ; i< n ;i++){
        printf("%d  ",a[i]);
    }

return 0;

}
