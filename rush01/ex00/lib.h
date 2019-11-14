/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaume <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:11:57 by fheaume           #+#    #+#             */
/*   Updated: 2019/09/08 19:13:09 by fheaume          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int		reversecheckcol(int **tab, int indxcol, int nbz);
int		reversecheckline(int **tab, int indxline, int nbz);
int		checkline(int indxline, int **tab);
int		checkcolumn(int indxcolumn, int **tab);
int		validate(int **tab, int indxline, int indxcol);
int		solve(int y, int x, int **tab);
int		checkduplicatesline(int **tab, int indxline);
int		checkduplicatescolmn(int **tab, int indxcol);
void	print_return(int **tab);
int		*intput_is_valid(int argc, char *argv[]);
int		**fillgrid(int *vars, int **tab);
int		run(int argc, char *argv[]);
void	clear(int **tab);

#endif
