/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:14:45 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/10 13:14:46 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;
	int nbo;

	if (nb < 0)
		return (0);
	nbo = 1;
	i = 1;
	if (nb >= 1)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (1);
}
