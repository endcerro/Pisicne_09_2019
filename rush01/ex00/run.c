/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaume <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:05:46 by fheaume           #+#    #+#             */
/*   Updated: 2019/09/08 19:10:41 by fheaume          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int		run(int argc, char *argv[])
{
	int **tab;
	int i;
	int *input;

	input = intput_is_valid(argc, argv);
	if (!input)
		return (1);
	tab = malloc(sizeof(int*) * 6);
	if (!tab)
		return (1);
	i = 0;
	while (i < 6)
	{
		tab[i] = malloc(sizeof(int) * 6);
		if (!tab[i])
			return (1);
		i++;
	}
	fillgrid(input, tab);
	solve(1, 1, tab);
	print_return(tab);
	clear(tab);
	return (0);
}

void	clear(int **tab)
{
	int i;

	i = 0;
	while (i < 6)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_return(int **tab)
{
	int i;
	int j;
	int temp;

	if (tab[4][4] == 0)
		write(1, "Error\n", 6);
	else
	{
		i = 1;
		while (i < 5)
		{
			j = 1;
			while (j < 5)
			{
				temp = tab[i][j] + 48;
				write(1, &temp, 1);
				if (j < 4)
					write(1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

int		*intput_is_valid(int argc, char *argv[])
{
	int *tab;
	int i;
	int j;

	j = 0;
	i = 0;
	tab = malloc(sizeof(int) * 16);
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] <= '4' && argv[1][i] >= '1')
		{
			tab[j] = argv[1][i] - '0';
			j++;
		}
		i++;
	}
	if (i != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (tab);
}

int		**fillgrid(int *vars, int **tab)
{
	int i;
	int p;

	i = 0;
	while (i < 6)
	{
		p = 0;
		while (p < 6)
			tab[i][p++] = 0;
		i++;
	}
	i = 1;
	p = 0;
	while (i < 5)
	{
		tab[0][i] = vars[p];
		tab[5][i] = vars[p + 4];
		tab[i][0] = vars[p + 8];
		tab[i][5] = vars[p + 12];
		i++;
		p++;
	}
	return (tab);
}
