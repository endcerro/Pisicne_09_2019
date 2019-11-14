/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:17:23 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/28 23:48:10 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printblock(int a)
{
	ft_putchar('0' + (a / 10));
	ft_putchar('0' + (a % 10));
}

void	ft_printwhole(int a, int b)
{
	ft_printblock(a);
	ft_putchar(' ');
	ft_printblock(b);
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		ft_printwhole(a, b);
		b++;
		if (b == 100)
		{
			a++;
			b = a + 1;
		}
	}
}
