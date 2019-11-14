/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:12:40 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/05 11:13:05 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (*str)
	{
		str++;
		cpt++;
	}
	return (cpt);
}

int		ft_pow(int nb, int pow)
{
	int i;
	int dest;

	dest = 1;
	i = 1;
	while (i < pow)
	{
		dest = dest * nb;
		i++;
	}
	return (dest);
}

int		getnb(char *c)
{
	int pow;
	int nb;
	int i;

	i = 0;
	nb = 0;
	pow = ft_strlen(c);
	while (c[i])
	{
		nb += (c[i] - '0') * ft_pow(10, pow);
		i++;
		pow--;
	}
	return (nb);
}

int		ft_atoi(char *str)
{
	int		i;
	int		signe;
	char	cpy[ft_strlen(str)];
	int		j;

	j = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		cpy[j] = str[i];
		j++;
		i++;
	}
	cpy[j] = '\0';
	return (getnb(cpy) * signe);
}
