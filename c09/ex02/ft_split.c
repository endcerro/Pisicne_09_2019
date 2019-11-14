/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 02:05:08 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/10 02:05:10 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*stcpy(int start, int end, char *base)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = malloc(sizeof(char) * (end - start) + 1)))
		return (0);
	while (start < end)
	{
		out[i] = base[start];
		start++;
		i++;
	}
	out[i] = '\0';
	return (out);
}

int		isseparator(char c, char *separators)
{
	int i;

	i = 0;
	while (separators[i])
	{
		if (separators[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		countwords(char *str, char *sep)
{
	int i;
	int cpt;
	int started;

	started = 1;
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (isseparator(str[i], sep))
			started = i;
		else if (started)
		{
			cpt++;
			started = 0;
		}
		i++;
	}
	return (cpt);
}

char	**ft_split(char *str, char *sep)
{
	char	**output;
	int		vars[4];

	vars[0] = -1;
	vars[1] = -1;
	vars[2] = 0;
	vars[3] = -1;
	if (!(output = malloc(sizeof(char*) * countwords(str, sep) + 1)))
		return (0);
	while (str[++vars[0]])
	{
		if (isseparator(str[vars[0]], sep) && vars[2])
		{
			output[++vars[1]] = stcpy(vars[3], vars[0], str);
			vars[2] = 0;
		}
		if (!isseparator(str[vars[0]], sep) && !vars[2]++)
			vars[3] = vars[0];
	}
	if (vars[2] && str[0])
		output[++vars[1]] = stcpy(vars[3], vars[0], str);
	output[++vars[1]] = 0;
	return (output);
}
