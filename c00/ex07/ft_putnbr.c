/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrRec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:25:39 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/28 16:20:40 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_negcheck(int i)
{
	int tmp;

	tmp = i;
	if (i < 0)
	{
		ft_putchar('-');
		tmp = tmp * -1;
	}
	return (tmp);
}

int		minintchecker(int i)
{
	int a;

	a = 0;
	if (i == -2147483648)
	{
		a = 1;
	}
	return (a);
}

void	ft_putnbr_rec(int i)
{
	int unitdigit;
	int rest;

	unitdigit = i % 10;
	rest = (i - unitdigit) / 10;
	if (rest != 0)
	{
		ft_putnbr_rec(rest);
	}
	ft_putchar('0' + unitdigit);
}

void	ft_putnbr(int i)
{
	int unitdigit;
	int rest;
	int tmp;
	int minintcheck;

	minintcheck = minintchecker(i);
	tmp = ft_negcheck(i + minintcheck);
	unitdigit = tmp % 10;
	rest = (tmp - unitdigit) / 10;
	if (rest != 0)
	{
		ft_putnbr_rec(rest);
	}
	if (minintcheck == 1)
	{
		ft_putchar('0' + 8);
	}
	else
	{
		ft_putchar('0' + unitdigit);
	}
}
