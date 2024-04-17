/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:02:47 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/17 22:39:22 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_columns(int rows_checked, int **grid);

int check_leftrows(char clue, int *arr);

int check_rightrows(char clue, int *arr);

int permute_row(int *row, int clue, int start, char *clues);

void swap(int *a, int *b);

void print_grid(int **arr)
{
	int i;
	int j;
	char digit;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			digit = arr[i][j] + '0';
			write(1, &digit, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int **allocate_grid(void)
{
	int i;
	int **grid;

	grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (0);
	i = 0;
	while (i < 4)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
			return (0);
		i++;
	}
	return (grid);
}

void free_grid_mem(int **grid)
{
	int j;

	j = 0;
	while (j < 4)
	{
		free(grid[j]);
		j++;
	}
	free(grid);
}

int **initialise_grid(int **grid)
{
	int row;
	int col;
	int value;

	row = 0;
	while (row < 4)
	{
		col = 0;
		value = 1;
		while (col < 4)
		{
			grid[row][col] = value;
			value++;
			col++;
		}
		row++;
	}
	return (grid);
}

int main(int argc, char **argv)
{
	int **grid;
	int row;
	char clue;

	if (argc > 2)
		return (1);
	grid = allocate_grid();
	initialise_grid(grid);
	row = 0;
	while (row < 4)
	{
		clue = 16 + (2 * row);
		if (permute_row(grid[row], clue, 0, argv[1]) == 0 && check_columns(row, grid) == 0)
			row++;
		else
			row--;
		permute_row(grid[row], clue, 0, argv[1]);
	}
	print_grid(grid);
	free_grid_mem(grid);
}
