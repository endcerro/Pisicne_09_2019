/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:16:55 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/10 13:16:57 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int tmp;

	i = 0;
	tmp = 1;
	if (nb == 0 && power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (i < power)
	{
		tmp = tmp * nb;
		i++;
	}
	return (tmp);
}
