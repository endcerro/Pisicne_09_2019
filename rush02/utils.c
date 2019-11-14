/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:18:46 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/15 14:18:48 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	getvalue(int val, struct s_stock_str	*tab)
{
	int		nb[1];
	char	*dest;
	int		i;

	nb[0] = 0;
	dest = malloc(sizeof(char) * 20);
	ft_putnbr_base(val, "0123456789", dest, nb);
	i = 0;
	while (ft_strcmp(tab[i].numerical, dest) != 0 && tab[i].numerical != 0)
		i++;
	free(dest);
	if (tab[i].numerical == 0)
		printf("casseé\n");
	if (val != 0)
		ft_putstr(tab[i].charical);
}

int		getworded(char *c, struct s_stock_str	*tab)
{
	int i;

	i = 0;
	while (tab[i].numerical != 0 && ft_strcmp(c, tab[i].numerical) != 0)
		i++;
	if (tab[i].numerical == 0)
		return (1);
	if (ft_strcmp(c, "0") != 0)
		ft_putstr(tab[i].charical);
	return (0);
}

void	getworded_c(char c, struct s_stock_str	*tab)
{
	int i;

	i = 0;
	while (c != tab[i].numerical[0] && tab[i].numerical != 0)
		i++;
	if (tab[i].numerical == 0)
		printf("casseé\n");
	if (c != '0')
		ft_putstr(tab[i].charical);
}

int		fillblocksofthree(char *input, char **tab, int nbofblocks)
{
	int i;
	int p;

	i = 2;
	p = ft_strlen(input);
	while (--p >= 0)
	{
		tab[nbofblocks][i--] = input[p];
		if (i < 0)
		{
			nbofblocks--;
			i = 2;
		}
	}
	while (i != -1 && i != 2)
		tab[nbofblocks][i--] = '0';
	return (nbofblocks);
}

char	**getblocksofthree(char *input)
{
	char	**tab;
	int		nbofblocks;
	int		i;

	nbofblocks = ft_strlen(input) / 3;
	if ((ft_strlen(input) / 3 * 3) != ft_strlen(input))
		nbofblocks++;
	if (!(tab = malloc(sizeof(char*) * nbofblocks + 1)))
		return (0);
	i = -1;
	while (++i < nbofblocks)
		if (!(tab[i] = malloc(sizeof(char) * 3 + 1)))
			return (0);
	nbofblocks--;
	fillblocksofthree(input, tab, nbofblocks);
	return (tab);
}
