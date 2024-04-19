/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:55:30 by ruwang            #+#    #+#             */
/*   Updated: 2024/04/19 22:52:11 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_columns(int rows_checked, int **grid)
{
    int list[4];
    int i;
    int col;
    int k;

    i = 0;
    while (i < rows_checked)
    {
        col = 0;
        while (col < 4)
        {
            k = 0;
            while (k < i)
            {
                if (list[k] == grid[i][col])
                    return (1);
                k++;
            }
            list[col] = grid[i][col];
            col++;
        }
        i++;
    }
    return (0);
}

int check_leftrows(char clue, int *arr)
{
    int counter = 1;
    int highest = arr[0];
    for (int col = 1; col < 4; col++)
    {
        if (arr[col] > highest)
        {
            counter++;
            highest = arr[col];
        }
    }
    return counter == (clue - '0') ? 1 : 0;
}

int check_rightrows(char clue, int *arr)
{
    int counter;
    int highest;
    int col;

    col = 3;
    counter = 1;
    highest = arr[-1];
    while (col > 0)
    {
        if (arr[col - 1] > arr[col])
        {
            if (arr[col - 1] > highest)
            {
                counter++;
                highest = arr[col - 1];
            }
        }
        col--;
    }
    if (counter != (clue - '0'))
        return (1);
    return (0);
}

int check_up(int **grid, int current_row, char *col_up_clues)
{
    for (int col = 0; col < 4; col++)
    {
        int visible_count = 0;
        int max_height = 0;
        for (int row = 0; row <= current_row; row++)
        {
            if (grid[row][col] > max_height)
            {
                max_height = grid[row][col];
                visible_count++;
            }
        }
        if (visible_count > col_up_clues[col] - '0')
        {
            return 0;
        }
    }
    return 1;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int permute_row(int *row, int clue, int start, char *clues, int **grid, int current_row, int total_rows)
{
    int end = 3;
    if (start > end)
    {
        if (check_leftrows(clues[clue], row) && check_rightrows(clues[clue + 8], row))
        {
            for (int i = 0; i <= end; i++)
            {
                grid[current_row][i] = row[i];
            }
            if (current_row == total_rows - 1 || (current_row > 0 && check_up(grid, current_row + 1, clues + 16)))
            {
                return 1;
            }
        }
        return 0;
    }

    for (int i = start; i <= end; i++)
    {
        swap(&row[start], &row[i]);
        if (permute_row(row, clue, start + 1, clues, grid, current_row, total_rows))
        {
            return 1;
        }
        swap(&row[start], &row[i]);
    }
    return 0;
}
