#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid to the console.
 *
 * @grid: The 3x3 grid to be printed.
 */

void print_grid(int grid[3][3])
{

    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Performs the sandpiles sum operation on two 3x3 grids.
 *
 * @grid1: The first 3x3 grid.
 * @grid2: The second 3x3 grid to be added to the first grid.
 *
 * This function takes two 3x3 grids as input and adds their corresponding elements.
 * If any element in the resulting grid is greater than 3, it performs stabilization
 * by redistributing the excess grains to neighboring cells until the grid becomes stable.
 * It prints the intermediate grids during the stabilization process only if the grid is unstable.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable;
	int tmp[3][3];

	/* Perform grid addition */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Stabilize the grid until it becomes stable */
	do {
		unstable = 0;

		/* Copy the current state of the grid for comparison */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				tmp[i][j] = grid1[i][j];
			}
		}

		/* Check for instability in the grid */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (tmp[i][j] > 3)
				{
					unstable = 1;
				}
			}
		}

		/* Print the grid if it is unstable */
		if (unstable)
		{
			printf("=\n");
			print_grid(grid1);
		}

		/* Redistribute excess grains to stabilize the grid */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (tmp[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i > 0)
						grid1[i - 1][j] += 1;
					if (i < 2)
						grid1[i + 1][j] += 1;
					if (j > 0)
						grid1[i][j - 1] += 1;
					if (j < 2)
						grid1[i][j + 1] += 1;
				}
			}
		}
	} while (unstable);
}