/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:39:14 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/03 17:45:15 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && to_find[j])
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (!to_find[j])
		return (&str[i - j]);
	if (to_find[0] == '\0')
		return (str);
	return (0);
}
