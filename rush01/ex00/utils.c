/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:07:07 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/08 18:57:34 by fheaume          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	reversecheckcol(int **tab, int indxcol, int nbz)
{
	int nbseen;
	int lastseen;
	int i;

	nbseen = 0;
	lastseen = 0;
	i = 4;
	while (i > 0)
	{
		if (tab[i][indxcol] > lastseen)
		{
			nbseen++;
			lastseen = tab[i][indxcol];
		}
		i--;
	}
	if (nbseen != tab[5][indxcol] && nbz == 0)
		return (1);
	return (0);
}

int	reversecheckline(int **tab, int indxline, int nbz)
{
	int nbseen;
	int lastseen;
	int i;

	nbseen = 0;
	lastseen = 0;
	i = 4;
	while (i > 0)
	{
		if (tab[indxline][i] > lastseen)
		{
			nbseen++;
			lastseen = tab[indxline][i];
		}
		i--;
	}
	if (nbseen != tab[indxline][5] && nbz == 0)
		return (1);
	return (0);
}

int	checkline(int indxline, int **tab)
{
	int i;
	int nbz;
	int nbseen;
	int lastseen;

	i = 1;
	nbz = 0;
	nbseen = 0;
	lastseen = 0;
	while (i < 5)
	{
		if (tab[indxline][i] == 0)
			nbz++;
		if (tab[indxline][i] > lastseen)
		{
			nbseen++;
			lastseen = tab[indxline][i];
		}
		i++;
	}
	if (nbseen != tab[indxline][0] && nbz == 0)
		return (1);
	return (reversecheckline(tab, indxline, nbz));
}

int	checkcolumn(int indxcolumn, int **tab)
{
	int i;
	int nbz;
	int nbseen;
	int lastseen;

	i = 1;
	nbz = 0;
	nbseen = 0;
	lastseen = 0;
	while (i < 5)
	{
		if (tab[i][indxcolumn] == 0)
			nbz++;
		if (tab[i][indxcolumn] > lastseen)
		{
			nbseen++;
			lastseen = tab[i][indxcolumn];
		}
		i++;
	}
	if (nbseen != tab[0][indxcolumn] && nbz == 0)
		return (1);
	return (reversecheckcol(tab, indxcolumn, nbz));
}
