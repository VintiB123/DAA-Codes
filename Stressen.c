#include <stdio.h>

void printMatrix(int mul[2][2]) {
    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication(int array1[2][2], int array2[2][2]) {
    int mul[2][2];
    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            mul[i][j] = 0;
            for(int k=0 ; k<2 ; k++) {
                mul[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    printMatrix(mul);
}

void strassenMatrixMultiplication(int array1[2][2], int array2[2][2]) {
    int p1, p2, p3, p4, p5, p6, p7, mul[2][2];
    p1 = array1[0][0] * (array2[0][1] - array2[1][1]);
    p2 = array2[1][1] * (array1[0][0] + array1[0][1]);
    p3 = array2[0][0] * (array1[1][0] + array1[1][1]);
    p4 = array1[1][1] * (array2[1][0] - array2[0][0]);
    p5 = (array1[0][0] + array1[1][1]) * (array2[0][0]+ array2[1][1]);
    p6 = (array1[0][1] - array1[1][1]) * (array2[1][0] + array2[1][1]);
    p7 = (array1[0][0] - array1[1][0]) * (array2[0][0] + array2[0][1]);
    mul[0][0] = p4 + p5 + p6 - p2;
    mul[0][1] = p1 + p2;
    mul[1][0] = p3 + p4;
    mul[1][1] = p1 - p3 + p5 - p7;
    
    printMatrix(mul);
}

int main()
{
    int array1[2][2], array2[2][2];
    printf("Enter the first matrix: ");
    for(int i=0 ; i<2 ; i++) 
        for(int j=0 ; j<2 ; j++)    
            scanf("%d", &array1[i][j]);

    printf("Enter the second matrix: ");
    for(int i=0 ; i<2 ; i++) 
        for(int j=0 ; j<2 ; j++)    
            scanf("%d", &array2[i][j]);

    printf("\nMatrix A: \n");
    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            printf("%d ", array1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B: \n");
    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }

    printf("\nNormal Matrix Multiplication :\n");
    matrixMultiplication(array1, array2);
    
    printf("\nStrassen's Matrix Multiplication :\n");
    strassenMatrixMultiplication(array1, array2);

    return 0;
}