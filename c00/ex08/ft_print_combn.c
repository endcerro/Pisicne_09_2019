/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:29:43 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/28 23:50:14 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	int unitdigit;
	int rest;

	unitdigit = i % 10;
	rest = (i - unitdigit) / 10;
	if (rest != 0)
	{
		ft_putnbr(rest);
	}
	ft_putchar('0' + unitdigit);
}

void	print_array(int *tableau, int nombrecases)
{
	int compteur;

	compteur = 0;
	while (compteur < nombrecases)
	{
		ft_putnbr(tableau[compteur]);
		compteur++;
	}
}

void	increment_array(int *tableau, int nombrecases, int cptrecurs)
{
	if (tableau[nombrecases - 1] == 9 - cptrecurs)
	{
		increment_array(tableau, nombrecases - 1, cptrecurs + 1);
		tableau[nombrecases - 1] = tableau[nombrecases - 2] + 1;
	}
	else
	{
		tableau[nombrecases - 1]++;
	}
}

void	ft_print_combn(int nombrecases)
{
	int tableau[nombrecases];
	int i;

	i = 0;
	while (i < nombrecases)
	{
		tableau[i] = i;
		i++;
	}
	i = 0;
	while (tableau[0] < (10 - nombrecases))
	{
		print_array(tableau, nombrecases);
		ft_putchar(',');
		ft_putchar(' ');
		increment_array(tableau, nombrecases, i);
	}
	print_array(tableau, nombrecases);
}
