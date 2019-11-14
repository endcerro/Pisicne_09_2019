/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:58:00 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/05 20:04:08 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print(char *tab[], int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		ft_putstr(tab[i - 1]);
		i++;
	}
}

void	cpy(int argc, char const *argv[])
{
	char	*tab[argc];
	int		i;
	char	*cache;

	i = 1;
	while (i < argc)
	{
		tab[i - 1] = (char *)argv[i];
		i++;
	}
	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
		{
			cache = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = cache;
			i = 1;
		}
		else
			i++;
	}
	print(tab, argc);
}

int		main(int argc, char const *argv[])
{
	cpy(argc, argv);
	return (0);
}
