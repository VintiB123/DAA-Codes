// Fruit 1: 10 2
// Fruit 2: 5 3
// Fruit 3: 15 5
// Fruit 4: 7 7
// Fruit 5: 6 1
// Fruit 6: 18 4
// Fruit 7: 3 1
// ans : 16.333334
#include <stdio.h>

int main() {
    int fruits, cap = 15;
    float answer = 0, temp;
    printf("Enter the number of fruits : ");
    scanf("%d", &fruits);
    int index[fruits];
    float fruit[fruits][2], solution[fruits], pw[fruits];
    printf("Enter the nutritional value and it's weight: \n");
    for(int i=0 ; i<fruits ; i++) {
        printf("Fruit %d: ", (i+1));
        for(int j=0 ; j<2 ; j++) {
            scanf("%f", &fruit[i][j]);
        }
        index[i] = i+1;
        solution[i] = 0;
    }
    
    printf("\n\nNutritional Value / Weight: ");
    for(int i=0 ; i<fruits ; i++) {
        pw[i] = fruit[i][0] / fruit[i][1];
        printf("\nFruit %d: %f", (i+1), pw[i]);
    }
    
    for(int i=0 ; i<fruits - 1 ; i++) {
        for(int j=0 ; j<fruits - i - 1 ; j++) {
            if(pw[j] < pw[j+1]) {
                temp = pw[j];
                pw[j] = pw[j+1];
                pw[j+1] = temp;
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
                temp = fruit[j][1];
                fruit[j][1] = fruit[j+1][1];
                fruit[j+1][1] = temp;
            }
        }
    }
    
    printf("\n\nSorted Nutritional Value / Weight: ");
    for(int i=0 ; i<fruits ; i++) {
        printf("\nFruit %d: %f", index[i], pw[i]);
    }

    int i=0;
    while(cap != 0) {
        if(cap >= fruit[i][1]) {
            cap -= fruit[i][1];
            solution[index[i] - 1] = 1;
        }
        else {
            solution[index[i] - 1] = (cap / fruit[i][1]);
            cap = 0;
        }
        i++;
    }

    
    for(int i=0 ; i<fruits ; i++) {
        answer += solution[i] * fruit[i][0];
    }
    
    printf("\nNutritional Value : %f", answer);
    return 0;
}