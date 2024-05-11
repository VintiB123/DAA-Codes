#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char pat[MAX],txt[MAX];


int main(){
    int n,m,i,j;
    printf("Enter the text: ");
    scanf("%99s",txt);
    printf("\nEnter pattern: ");
    scanf("%99s",pat);
    n = strlen(txt);
    m = strlen(pat);
    for(i=0;i<=n-m;i++){
        for( j=0;j<m;j++){
            if(txt[j+i] != pat[j]){
                break;
            }
        }
        if(j==m){
            printf("\nPattern found at index %d",i);

        }
    }
}