 #include<stdio.h>
 #include<conio.h>
 #define MAX 100

 void merge(int a[],int lb, int mid, int ub);

 void mergesort(int a[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid = (ub+lb)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
 }

void merge(int a[], int lb, int mid, int ub){

    int i= lb,j = mid+1, k= lb,b[MAX];
    while(i <= mid && j<= ub){
        if(a[i]<= a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else{
        while(i <= mid){
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for(i = lb; i<= ub; i++){
        a[i] = b[i];
    }

}
int main(){
    int a[MAX],i,lb=0,ub=0,n;
    printf("\nEnter number of element to be Sort: ");
    scanf("%d",&n);
    printf("\nEnter the elements to be sort: ");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray before sorting: \n");
    for(i=0 ; i< n ;i++){
        printf("%d  ",a[i]);
    }
    
    ub = n-1 ;
    mergesort(a,lb,ub);
    printf("\nArray after sorting: \n");
    for(i=0 ; i< n ;i++){
        printf("%d  ",a[i]);
    }

return 0;
}