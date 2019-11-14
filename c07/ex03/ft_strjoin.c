/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:35:07 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 13:35:09 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

int		getfullsize(int size, char **strs)
{
	int fullsize;
	int i;
	int j;

	i = 0;
	j = 0;
	fullsize = 0;
	while (i < size && strs[i])
	{
		fullsize += ft_strlen(strs[i]);
		i++;
	}
	return (fullsize);
}

void	cpy(int size, char *dest, char **src, char *sp)
{
	int		i;
	int		j;
	int		p;
	int		o;

	o = -1;
	i = -1;
	p = -1;
	while (++i < size && src[i])
	{
		j = -1;
		while (src[i][++j])
			dest[++p] = src[i][j];
		o = -1;
		if (i + 1 < size)
			while (sp[++o])
				dest[++p] = sp[o];
	}
	dest[++p] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*full;
	int		fullsize;

	fullsize = getfullsize(size, strs);
	full = malloc(sizeof(char) * fullsize + (ft_strlen(sep) * (size - 1)) + 1);
	if (size == 0)
	{
		if (!(full = malloc(sizeof(char) * 1)))
			return (0);
		full[0] = '\0';
		return (full);
	}
	cpy(size, full, strs, sep);
	return (full);
}
