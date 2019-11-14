/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:30 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/17 23:33:07 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		calculator(char *argv[])
{
	int nb1;
	int nb2;

	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		return (nb1 + nb2);
	else if (argv[2][0] == '-')
		return (nb1 - nb2);
	else if (argv[2][0] == '*')
		return (nb1 * nb2);
	else if (argv[2][0] == '/')
		return (nb1 / nb2);
	else if (argv[2][0] == '%')
		return (nb1 % nb2);
	else
		return (0);
}

int		main(int argc, char *argv[])
{
	char o;

	if (argc != 4)
		return (1);
	o = argv[2][0];
	if (ft_atoi(argv[3]) == 0 && (o == '/'))
		write(1, "Stop : division by zero", 23);
	else if (ft_atoi(argv[3]) == 0 && (o == '%'))
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(calculator(argv));
	write(1, "\n", 1);
	return (0);
}
