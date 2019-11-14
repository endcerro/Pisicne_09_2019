/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:01:29 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/08 16:01:41 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	solve(int y, int x, int **tab)
{
	int value;
	int status;

	value = 1;
	status = 1;
	while (y < 5 && status != 0)
	{
		tab[y][x] = value;
		if (!validate(tab, y, x))
		{
			if (x < 4)
				status = solve(y, x + 1, tab);
			else
				status = solve(y + 1, 1, tab);
		}
		if (status == 0)
			return (0);
		value++;
		if (value == 5)
		{
			tab[y][x] = 0;
			return (-1);
		}
	}
	return (0);
}
