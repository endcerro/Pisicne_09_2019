/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:14:38 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/01 03:09:15 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= ' ' && c <= '~')
		is_valid = 1;
	return (is_valid);
}

void	print_hex(char a)
{
	char	first_c;
	char	second_c;
	int		first_i;
	int		second_i;
	char	c;

	first_i = a / 16;
	second_i = a % 16;
	if (first_i > 9)
		first_c = 96 + first_i - 9;
	else
		first_c = '0' + first_i;
	if (second_i > 9)
		second_c = 96 + second_i - 9;
	else
		second_c = '0' + second_i;
	c = '\\';
	write(1, &c, 1);
	write(1, &first_c, 1);
	write(1, &second_c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_valid(str[i]))
			write(1, &str[i], 1);
		else
			print_hex(str[i]);
		++i;
	}
}
