/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:51:16 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/11 18:51:20 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_stock_str
{
	char *numerical;
	char *charical;
}					t_stock_str;

char				**ft_split(char *str, char *sep);
struct s_stock_str	*outputstrs();
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
int					ft_recursive_power(int nb, int power);
void				ft_putnbr_base(int nbr, char *base, char *dt, int *nb);
void				ft_putstr(char *str);
void				getvalue(int val, struct s_stock_str	*tab);
char				**getblocksofthree(char *input);
void				getworded_c(char c, struct s_stock_str	*tab);
int					getworded(char *c, struct s_stock_str	*tab);
void				printpow10(int i, struct s_stock_str	*tab, int spc[]);
int					ft_atoi_base(char *nb, char *base);
int					ft_base_is_valid(char *base);
int					mchb_strl(char nb, char *base);
void				ft_addto(char *st, int *nb, char c);
char				**ft_split(char *str, char *sep);
int					run(int ac, char *av[]);
struct s_stock_str	*checkdico(struct s_stock_str	*tab);
void				freestrstr(char **tab);
void				freedico(struct s_stock_str	*tab);
void				printzero(struct s_stock_str	*tab);
int					checkforzero(char *c, struct s_stock_str	*tab);
int					fillblocksofthree(char *input, char	**tab, int nbofblocks);
int					checkiftropgrand(char *c);

#endif
