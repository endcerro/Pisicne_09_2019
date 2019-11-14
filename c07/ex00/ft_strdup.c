/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:14 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 13:28:17 by edal--ce         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	p = malloc(ft_strlen(s1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
