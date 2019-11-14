/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:29:53 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/12 11:19:43 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	if (nb <= 0 || nb == 1)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if ((nb / i) * i == nb)
			return (0);
		i++;
	}
	return (1);
}