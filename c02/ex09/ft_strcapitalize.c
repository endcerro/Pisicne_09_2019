/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:58:57 by edal--ce          #+#    #+#             */
/*   Updated: 2019/08/31 16:13:21 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char c)
{
	int is_valid;

	is_valid = 0;
	if (c >= '0' && c <= '9')
		is_valid = 1;
	if (c >= 'a' && c <= 'z')
		is_valid = 2;
	if (c >= 'A' && c <= 'Z')
		is_valid = 3;
	return (is_valid);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int f1;

	i = 0;
	f1 = 1;
	while (str[i])
	{
		if (is_valid(str[i]) == 2 && f1)
			str[i] -= 32;
		else if (is_valid(str[i]) == 3 && !f1)
			str[i] += 32;
		f1 = 0;
		if (!is_valid(str[i]))
			f1 = 1;
		i++;
	}
	return (str);
}
