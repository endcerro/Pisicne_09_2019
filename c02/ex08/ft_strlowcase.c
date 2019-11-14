/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:55:32 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/31 10:56:48 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= 'A' && c <= 'Z')
		is_valid = 1;
	return (is_valid);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_valid(str[i]))
			str[i] += 32;
		++i;
	}
	return (str);
}
