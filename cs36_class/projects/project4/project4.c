#include <stdio.h>

int isValid(int grid[3][3]) {
    // Check multiplication condition
    if (grid[0][0] * grid[0][1] != grid[0][2]) return 0;
    // Check addition condition
    if (grid[1][0] + grid[1][1] != grid[1][2]) return 0;
    return 1;
}

void printGrid(int grid[3][3]) {
    printf("%d * %d = %d\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("%d + %d = %d\n", grid[1][0], grid[1][1], grid[1][2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int used[10] = {0};

int solve(int grid[3][3], int row, int col) {
    if (row == 3) return isValid(grid);
    if (col == 3) return solve(grid, row + 1, 0);

    for (int num = 1; num <= 9; num++) {
        if (!used[num]) {
            grid[row][col] = num;
            used[num] = 1;
            if (solve(grid, row, col + 1)) return 1;
            used[num] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[3][3] = {0};
    if (solve(grid, 0, 0)) {
        printGrid(grid);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}
