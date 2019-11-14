/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:28:44 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/10 13:28:46 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int val)
{
	int i;

	i = 0;
	while (i < 46342)
	{
		i++;
		if (i * i == val)
			return (i);
	}
	return (0);
}