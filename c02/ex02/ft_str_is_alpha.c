/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:29:09 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/31 16:11:56 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= 'a' && c <= 'z')
		is_valid = 1;
	if (c >= 'A' && c <= 'Z')
		is_valid = 1;
	return (is_valid);
}

int	ft_str_is_alpha(char *str)
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
