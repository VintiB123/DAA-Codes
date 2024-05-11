#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define d 256

char pat[MAX],txt[MAX];
void rabinkarp(int q){
    int N = strlen(txt);
    int M = strlen(pat);
    int i,j;
    int p=0,t=0,h=1;
    for(i=1;i<=M-1;i++){
        h = (h*d)%q;
    }
    for(i=0;i<M;i++){
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i]) %q;
        
    }
    // printf("%d %d",p,t);
    for(i=0;i<=N-M;i++){
        if(p==t){
            for(j=0;j<M;j++){
                if(txt[i+j]!= pat[j]){
                    break;
                }
            }
            if(j==M){
                printf("\nPatter found at index %d",i);
            }
            else{
                printf("\nSpurious hit!");
            }
        }
        if(i<N-M){
            t = (d*(t-txt[i]*h) + txt[i+M])%q;
            if(t<0){
                t = (t+q)%q;
            }
            // printf("\n%d ",t);
        }
    }
}


int main(){
    
    printf("\nEnter the text:");
    scanf("%99s",txt);
    printf("\nEnter pattern: ");
    scanf("%99s",pat);
    rabinkarp(101);
    return 0;
    
   
}