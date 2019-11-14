/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:23:19 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/15 19:23:20 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printone(char **ipt, struct s_stock_str	*tab, int i, int j)
{
	if (j == 1 && ipt[i][j] == '1')
	{
		getvalue(((((ipt[i][j] - '0') * 10) +
		ipt[i][j + 1] - '0')), tab);
		j++;
	}
	else if (j == 1)
		getvalue(((ipt[i][j] - '0') * 10), tab);
	else
		getworded_c(ipt[i][j], tab);
	if (j == 0 && ipt[i][j] != '0')
	{
		ft_putstr(" ");
		getworded("100", tab);
	}
}

void	printthefnspace(int spc[])
{
	ft_putstr(" ");
	spc[0] = 0;
}

void	printblocks(char **input, struct s_stock_str	*tab, int blockcount)
{
	int i;
	int j;
	int space[1];

	space[0] = 0;
	i = -1;
	j = -1;
	while (input[++i])
	{
		while (input[i][++j])
		{
			if (space[0] && input[i][j] != '0')
				printthefnspace(space);
			if (j == 1 && input[i][j] == '1')
				printone(input, tab, i, j++);
			else
				printone(input, tab, i, j);
			if (input[i][j] != '0')
				space[0] = 1;
		}
		if (input[i][0] != '0' || input[i][1] != '0' || input[i][2] != '0')
			printpow10((blockcount - i - 1), tab, space);
		j = -1;
	}
}

int		sanitize(char *input)
{
	int		i;
	char	c;

	i = 0;
	while (input[i])
	{
		c = input[i];
		if (!(c >= '0' && c <= '9'))
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	if (checkiftropgrand(input))
		return (1);
	return (0);
}

int		run(int argc, char *argv[])
{
	int					i;
	struct s_stock_str	*tab;
	char				**blocks;

	if (sanitize(argv[argc - 1]))
		return (1);
	if (argc == 3)
		tab = outputstrs(argv[1]);
	else
		tab = outputstrs("numbers.dict");
	if (tab == 0)
		return (1);
	if (!(blocks = getblocksofthree(argv[argc - 1])))
		return (0);
	i = 0;
	while (blocks[i])
		i++;
	if (!checkforzero(argv[argc - 1], tab))
	{
		printblocks(blocks, tab, i);
	}
	freestrstr(blocks);
	freedico(tab);
	return (0);
}
