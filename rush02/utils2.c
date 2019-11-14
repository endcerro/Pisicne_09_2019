/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:32:34 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/15 19:32:36 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int					is_valid_num(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= '0' && c <= '9')
		is_valid = 1;
	return (is_valid);
}

int					ft_str_is_numeric(char *str)
{
	int num;
	int i;

	i = 0;
	num = 1;
	while (str[i])
	{
		if (!is_valid_num(str[i]))
			num = 0;
		i++;
	}
	return (num);
}

void				freedico(struct s_stock_str	*tab)
{
	int i;

	i = 0;
	while (tab[i].numerical)
	{
		free(tab[i].numerical);
		free(tab[i].charical);
		i++;
	}
	free(tab);
}

struct s_stock_str	*checkdico(struct s_stock_str	*tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i].numerical)
	{
		if (!ft_str_is_numeric(tab[i].numerical))
		{
			ft_putstr("Dict Error\n");
			freedico(tab);
			return (0);
		}
		i++;
	}
	return (tab);
}
