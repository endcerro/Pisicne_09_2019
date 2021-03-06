/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:22:16 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/01 14:36:45 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	pickchar(int posx, int posy, int height, int width)
{
	char c;
	char tab[6];

	tab[0] = 'A';
	tab[1] = 'A';
	tab[2] = 'C';
	tab[3] = 'C';
	tab[4] = 'B';
	c = ' ';
	if (posx == 0 || posx == width - 1)
		c = tab[4];
	if (posy == 0 || posy == height - 1)
		c = tab[4];
	if (posy == 0 && posx == 0)
		c = tab[0];
	else if (posy == height - 1 && posx == 0)
		c = tab[1];
	else if (posy == 0 && posx == width - 1)
		c = tab[2];
	else if (posy == height - 1 && posx == width - 1)
		c = tab[3];
	ft_putchar(c);
}

void	rush(int width, int height)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < height)
	{
		while (x < width)
		{
			pickchar(x, y, height, width);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
