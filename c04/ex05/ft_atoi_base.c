/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:14:46 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/05 11:15:27 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		mchb_strl(char nb, char *base)
{
	int j;

	j = 0;
	if (nb != '+')
	{
		while (base[j] && base[j] != nb)
			j++;
		if (!base[j])
			return (-1);
		return (j);
	}
	else
	{
		while (base[j])
			j++;
		return (-j);
	}
}

int		ft_pow(int val, int expos)
{
	int i;
	int tmp;

	i = 0;
	tmp = 1;
	while (i < val)
	{
		tmp = tmp * expos;
		i++;
	}
	return (tmp);
}

int		ft_base_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = 0;
		if (base[i] == 43 || base[i] == 45 || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		clean(char *nb, char *base, char *dest)
{
	int nbminus;
	int i;
	int j;

	i = 0;
	nbminus = 0;
	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			nbminus++;
		i++;
	}
	j = 0;
	while (mchb_strl(nb[i], base) > -1 && nb[i])
	{
		dest[j] = nb[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (nbminus);
}

int		ft_atoi_base(char *nb, char *base)
{
	int		i;
	int		final_nb;
	int		retnb;
	char	cpy[-1 * mchb_strl('+', nb)];
	int		size;

	i = 0;
	final_nb = 0;
	if (!ft_base_is_valid(base))
		return (0);
	retnb = clean(nb, base, cpy);
	size = -mchb_strl('+', cpy);
	while (cpy[i])
	{
		final_nb += mchb_strl((cpy[i]), base)
		* ft_pow(size - 1 - i, -mchb_strl('+', base));
		i++;
	}
	if (retnb % 2)
		return (-final_nb);
	return (final_nb);
}
