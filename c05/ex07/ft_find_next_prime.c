/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:30:39 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/12 14:01:22 by edal--ce         ###   ########.fr       */
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

int		ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	while (!ft_is_prime(nb + i))
		i++;
	return (nb + i);
}
