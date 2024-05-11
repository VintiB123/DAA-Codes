#include <stdio.h>
#include <stdlib.h>

int board[20], count = 0;

void print_board(int n) {
    int i, j;
    printf("\nSolution %d:\n", ++count);

    for (i = 1; i <= n; ++i) {
        printf("\n");
        for (j = 1; j <= n; ++j) {
            if (board[i] == j)
                printf("\tQ"); // queen at i,j position
            else
                printf("\t-"); // empty slot
        }
    }
}

int place(int row, int column) {
    int i;
    for (i = 1; i <= row - 1; ++i) {
        // checking for column and diagonal conflicts
        if (board[i] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    // no conflicts hence Queen can be placed
    return 1;
}

void Queen(int row, int n) {
    int column;
    for (column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column; // no conflict so place queen
            if (row == n) // dead end
                print_board(n); // printing the board configuration
            else // try next queen with next position
                Queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 20) {
        printf("Invalid input. Please enter a number between 1 and 19.\n");
        return 1;
    }

    Queen(1, n);

    if (count == 0)
        printf("No solutions found for %d queens.\n", n);

    return 0;
}