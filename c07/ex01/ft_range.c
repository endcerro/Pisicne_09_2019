/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:32:01 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 13:32:03 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

int		*ft_range(int min, int max)
{
	int *o;
	int i;

	if (min >= max)
		return (0);
	o = malloc(sizeof(int) * (max - min));
	if (!o)
		return (0);
	i = 0;
	while (min + i < max)
	{
		o[i] = min + i;
		i++;
	}
	return (o);
}
