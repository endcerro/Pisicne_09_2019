/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:29:43 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/28 00:57:57 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printblock(char a, char b, char c)
{
	if (c > '2')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a < '8')
	{
		ft_printblock(a, b, c);
		if (c == '9')
		{
			b++;
			if (b == '9')
			{
				a++;
				b = a + 1;
			}
			c = b + 1;
		}
		else
		{
			c++;
		}
	}
}
