/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:37:56 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/29 20:56:09 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	cpt;
	int	tmp[size];

	cpt = 0;
	while (cpt < size)
	{
		tmp[cpt] = tab[size - cpt - 1];
		cpt++;
	}
	cpt = 0;
	while (cpt < size)
	{
		tab[cpt] = tmp[cpt];
		cpt++;
	}
}
