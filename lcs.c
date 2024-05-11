#include<stdio.h>
#include<string.h>

#define MAX 100

char txt1[100],txt2[100];

int max(int a, int b){

    return(a>b?a:b);
}

void LCS(){
int i,j,LCS[MAX][MAX];
char sol[MAX];
int N = strlen(txt1);
int M = strlen(txt2);
for(i=0;i<=M;i++){
    for(j=0;j<=N;j++){
        if(i==0 || j==0){
            LCS[i][j] = 0;
        }
    }
}
for(i=1;i<=M;i++){
    for(j=1;j<=N;j++){
       if(txt2[i-1] == txt1[j-1]){
        LCS[i][j] = 1+ LCS[i-1][j-1];
       }
       else{
         LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
       }
    }
}
    i =M;
    j = N;
    int counter =0;
    while(j>0 && i>0){
        if(LCS[i][j] != LCS[i][j-1] ){
            sol[counter] = txt2[i-1];
            counter++;
            j--;
            i --;
        }
        else{
            j--;
        }
    }
    printf("\n");
    for(i=counter-1;i>=0;i--){
        printf("%c ",sol[i]);
    }



}

int main(){
    int i,j;


    printf("Enter the text: ");
    scanf("%99s",txt1);
    printf("\nEnter the second text: ");
    scanf("%99s",txt2);
    LCS();


    return 0;
}