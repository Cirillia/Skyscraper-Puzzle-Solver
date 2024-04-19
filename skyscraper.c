/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:02:47 by ruwang            #+#    #+#             */
/*   Updated: 2024/04/19 22:39:22 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_columns(int rows_checked, int **grid);
int check_leftrows(char clue, int *arr);
int check_rightrows(char clue, int *arr);
int permute_row(int *row, int clue, int start, char *clues, int **grid, int current_row, int total_rows);
void swap(int *a, int *b);

void print_grid(int **arr)
{
    int i, j;
    char digit;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            digit = arr[i][j] + '0';
            write(1, &digit, 1);
            write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}

int **allocate_grid(void)
{
    int i;
    int **grid = malloc(sizeof(int *) * 4);
    if (!grid)
        return NULL;

    for (i = 0; i < 4; i++)
    {
        grid[i] = malloc(sizeof(int) * 4);
        if (!grid[i])
        {
            while (--i >= 0) // Free previously allocated memory
                free(grid[i]);
            free(grid);
            return NULL;
        }
    }
    return grid;
}

void free_grid_mem(int **grid)
{
    if (!grid)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (grid[i])
            free(grid[i]);
    }
    free(grid);
}

int **initialise_grid(int **grid)
{
    if (!grid)
        return NULL;

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            grid[row][col] = col + 1;
        }
    }
    return grid;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <clues>\n", argv[0]);
        return 1;
    }

    int **grid = allocate_grid();
    if (!grid)
    {
        fprintf(stderr, "Failed to allocate memory for grid.\n");
        return 1;
    }

    grid = initialise_grid(grid);
    int row = 0;
    while (row < 4)
    {
        int clue = 16 + (2 * row);
        if (permute_row(grid[row], clue, 0, argv[1], grid, row, 4) == 1)
        {
            row++;
        }
        else
        {
            if (row > 0)
            {
                row--;
            }
            else
            {
                printf("no valid permutations\n");
                break;
            }
        }
    }

    print_grid(grid);
    free_grid_mem(grid);

    return 0;
}
