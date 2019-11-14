/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:13:40 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/05 11:14:25 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlenght(char *c)
{
	int i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int		ft_base_is_valid(char *base)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ft_strlenght(base) == 0 || ft_strlenght(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45 || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		j = (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base_rec(long int nb, char *base, long int basenb)
{
	if (nb >= basenb)
		ft_putnbr_base_rec(nb / basenb, base, basenb);
	ft_putchar(base[nb % basenb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int basenb;
	long int nb;

	if (ft_base_is_valid(base))
	{
		basenb = (long int)ft_strlenght(base);
		nb = (long int)nbr;
		if (nb < 0)
		{
			nb = nb * -1;
			ft_putchar('-');
		}
		ft_putnbr_base_rec(nb, base, basenb);
	}
}
