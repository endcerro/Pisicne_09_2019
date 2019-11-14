/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:50:21 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/31 10:53:40 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= 'a' && c <= 'z')
		is_valid = 1;
	return (is_valid);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_valid(str[i]))
			str[i] -= 32;
		++i;
	}
	return (str);
}
