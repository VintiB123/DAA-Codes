#include <stdio.h>
#define MAX 100
int array[MAX];

void Min_Max(int i, int j, int *max, int *min) {
    if(i == j) {
        *max = *min = array[i];
    } 
    else if(i == j-1) {
        if(array[i] < array[j]) {
            *max = array[j];
            *min = array[i];
        }
        else {
            *min = array[j];
            *max = array[i];
        }
    }
    else {
        int mid = (i + j)/2;
        int leftMax, leftMin, rightMax, rightMin;
        Min_Max(i, mid, &leftMax, &leftMin);
        Min_Max(mid + 1, j, &rightMax, &rightMin);
        if(leftMax > rightMax)
            *max = leftMax;
        else
            *max = rightMax;
        
        if(leftMin < rightMin)
            *min = leftMin;
        else
            *min = rightMin;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) 
        scanf("%d", &array[i]);
    
    int max, min;
    Min_Max(0, n-1, &max, &min);
    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}
