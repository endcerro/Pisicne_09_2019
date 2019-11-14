/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:17:08 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 12:17:11 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_base_rec(int a, char *bs, char *dt, int *p)
{
	int bnb;

	bnb = mchb_strl('+', bs) * -1;
	if (a >= bnb)
		ft_putnbr_base_rec(a / bnb, bs, dt, p);
	ft_addto(dt, p, bs[a % bnb]);
}

void	ft_putnbr_base(int nbr, char *base, char *dt, int *nb)
{
	int basenb;

	basenb = mchb_strl('+', base) * -1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_addto(dt, nb, '-');
	}
	ft_putnbr_base_rec(nbr, base, dt, nb);
	ft_addto(dt, nb, '\0');
}

int		size_int_base(int nb, int base_size)
{
	int res;

	res = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		++res;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= base_size;
		res++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		cache;
	int		*nb;
	int		tmp;

	if (!(nb = malloc(sizeof(int) * 1)))
		return (0);
	*nb = 0;
	if (!ft_base_is_valid(base_to) || !ft_base_is_valid(base_from))
		return (0);
	if (!nbr[0])
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (0);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	cache = ft_atoi_base(nbr, base_from);
	tmp = size_int_base(cache, -mchb_strl('+', base_to));
	if (!(dest = malloc(sizeof(char) * tmp + 1)))
		return (0);
	ft_putnbr_base(cache, base_to, dest, nb);
	return (dest);
}
