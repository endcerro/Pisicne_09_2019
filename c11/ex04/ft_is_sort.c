/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:01:04 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/17 21:01:07 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int h;

	i = 0;
	while (i < length - 1 && (h = (*f)(tab[i + 1], tab[i])) == 0)
		++i;
	if (h > 0)
	{
		while (++i < length - 1)
			if ((*f)(tab[i + 1], tab[i]) < 0)
				return (0);
	}
	else if (h < 0)
	{
		while (++i < length - 1)
			if ((*f)(tab[i + 1], tab[i]) > 0)
				return (0);
	}
	return (1);
}
