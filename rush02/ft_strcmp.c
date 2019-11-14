/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:35:02 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/02 19:24:19 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	printzero(struct s_stock_str	*tab)
{
	int		i;

	i = 0;
	while (ft_strcmp(tab[i].numerical, "0") != 0)
		i++;
	ft_putstr(tab[i].charical);
}

void	printpow10(int i, struct s_stock_str	*tab, int spc[])
{
	int		lenght;
	int		j;
	char	str[3 * i + 2];

	if (i > 0)
	{
		ft_putstr(" ");
		lenght = 3 * i + 2;
		j = 0;
		str[0] = '1';
		while (++j < lenght - 1)
			str[j] = '0';
		str[j] = '\0';
		if (getworded(str, tab) == 1)
		{
			printf("Dict Error\n");
		}
		ft_putstr(" ");
		spc[0] = 0;
	}
}

int		checkforzero(char *c, struct s_stock_str	*tab)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '0')
		{
			return (0);
		}
		i++;
	}
	printzero(tab);
	return (1);
}

int		ft_recursive_power(int nb, int power)
{
	int i;

	i = 0;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power >= 1)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}
