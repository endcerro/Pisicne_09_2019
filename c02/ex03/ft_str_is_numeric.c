/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:36:46 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/31 16:12:40 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= '0' && c <= '9')
		is_valid = 1;
	return (is_valid);
}

int	ft_str_is_numeric(char *str)
{
	int num;
	int i;

	i = 0;
	num = 1;
	while (str[i])
	{
		if (!is_valid(str[i]))
			num = 0;
		i++;
	}
	return (num);
}
