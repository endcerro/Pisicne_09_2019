/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:58:46 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/13 11:58:48 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			cpt++;
		i++;
	}
	return (cpt);
}
