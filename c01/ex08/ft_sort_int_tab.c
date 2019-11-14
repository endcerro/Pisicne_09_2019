/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:39:44 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/29 15:39:46 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_smallest(int *tab, int size)
{
	int smallest;
	int i;
	int indexsmallest;

	smallest = 2147483647;
	i = 0;
	while (i < size)
	{
		if (tab[i] < smallest)
		{
			smallest = tab[i];
			indexsmallest = i;
		}
		i++;
	}
	tab[indexsmallest] = 2147483647;
	return (smallest);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int tmp[size];
	int i;

	i = 0;
	while (i < size)
	{
		tmp[i] = find_smallest(tab, size);
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = tmp[i];
		i++;
	}
}
