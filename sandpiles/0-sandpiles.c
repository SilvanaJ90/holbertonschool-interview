#include <stdio.h>
#include "sandpiles.h"

void print_grid(int grid[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void topple(int grid[3][3], int row, int col) {
    grid[row][col] -= 4;
    if (row - 1 >= 0)
        grid[row - 1][col] += 1;
    if (row + 1 < 3)
        grid[row + 1][col] += 1;
    if (col - 1 >= 0)
        grid[row][col - 1] += 1;
    if (col + 1 < 3)
        grid[row][col + 1] += 1;
}

void stabilize(int grid[3][3]) {
    int unstable = 1;
    while (unstable) {
        unstable = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 3) {
                    topple(grid, i, j);
                    unstable = 1;
                }
            }
        }
        if (unstable) {
            printf("=\n");
            print_grid(grid);
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    stabilize(grid1);
}

int main(void) {
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    printf("Original grids:\n");
    print_grid(grid1);
    printf("+\n");
    print_grid(grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return 0;
}