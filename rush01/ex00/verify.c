/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:00:22 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/08 16:00:27 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	checkduplicatesline(int **tab, int indxline)
{
	int j;
	int i;
	int val;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			val = tab[indxline][j];
			if (tab[indxline][i] == val && i != j && val != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkduplicatescolmn(int **tab, int indxcol)
{
	int i;
	int j;
	int val;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			val = tab[i][indxcol];
			if (tab[j][indxcol] == val && i != j && val != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate(int **tab, int indxline, int indxcol)
{
	if (checkduplicatesline(tab, indxline))
		return (1);
	if (checkduplicatescolmn(tab, indxcol))
		return (1);
	if (checkline(indxline, tab))
		return (1);
	if (checkcolumn(indxcol, tab))
		return (1);
	return (0);
}
