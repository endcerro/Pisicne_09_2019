/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bd_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:21:43 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/15 14:21:45 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stock_str		*outputstrs(char *dico)
{
	int		fd;
	int		ret;
	char	*buffer;
	char	cache[1];
	char	**output;

	fd = open(dico, O_RDONLY);
	ret = 0;
	if (fd == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (read(fd, cache, 1))
		ret++;
	if (!(buffer = malloc(sizeof(char) * ret + 1)))
		return (0);
	fd = open(dico, O_RDONLY);
	buffer[read(fd, buffer, ret)] = '\0';
	output = ft_split(buffer, ": \n");
	free(buffer);
	fd = 0;
	while (output[fd])
		fd++;
	return (ft_strs_to_tab(fd, output));
}

int						ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

char					*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	p = malloc(ft_strlen(s1) * sizeof(char) + 1);
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

void					freestrstr(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (0);
	while (av[i + 1])
	{
		tab[j].numerical = ft_strdup(av[i]);
		tab[j].charical = ft_strdup(av[i + 1]);
		j++;
		i = i + 2;
	}
	tab[j].numerical = 0;
	tab[j].charical = 0;
	return (checkdico(tab));
}
