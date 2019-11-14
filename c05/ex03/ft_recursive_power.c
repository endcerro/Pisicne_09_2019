/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:19:01 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/10 13:19:02 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int i;

	i = 0;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power >= 1)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}
