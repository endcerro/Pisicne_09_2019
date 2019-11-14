/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:57:10 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/19 20:57:12 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		checkdiags(int **grid, int x, int y)
{
	int cpt;
	int i;

	cpt = 0;
	i = 0;
	while (i + x < 10 && i + y < 10)
	{
		if (grid[x + i][y + i] != 0)
			if (++cpt > 1)
				return (0);
		i++;
	}
	i = 0;
	cpt = 0;
	while (x + i < 10 && y - i >= 0)
	{
		if (grid[x + i][y - i] != 0)
			if (++cpt > 1)
				return (0);
		i++;
	}
	return (1);
}

int		checkforotherqueen(int **grid, int x, int y)
{
	int i;
	int cpt;

	i = -1;
	cpt = 0;
	while (++i < 10)
		if (grid[x][i] != 0 && i != y)
			if (++cpt > 1)
				return (0);
	i = 0;
	cpt = 0;
	while (i < 10)
	{
		if (grid[i][y] != 0 && i != x)
		{
			if (++cpt > 1)
				return (0);
		}
		i++;
	}
	return (checkdiags(grid, x, y));
}

int		isvalid(int **grid)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			if (checkforotherqueen(grid, i, j) == 0)
				return (0);
	}
	return (1);
}

int		printresult(int **grid)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (grid[i][j] == 1)
			{
				c = '0' + i;
				write(1, &c, 1);
			}
			i++;
		}
		j++;
	}
	c = '\n';
	write(1, &c, 1);
	return (1);
}

int		solve(int **grid, int colnb)
{
	int linb;
	int status;

	status = 0;
	linb = 0;
	if (colnb == 10)
		return (printresult(grid));
	while (colnb < 10)
	{
		if (linb > 9)
			return (0);
		grid[linb][colnb] = 1;
		if (!isvalid(grid))
			grid[linb][colnb] = 0;
		else
		{
			status = solve(grid, colnb + 1);
			if (!status || status)
				grid[linb][colnb] = 0;
		}
		linb++;
	}
	return (status);
}
