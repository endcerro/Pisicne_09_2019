/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:23:01 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/16 11:23:02 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *out;

	out = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		out[i] = (*f)(tab[i]);
		i++;
	}
	return (out);
}
