/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:23 by humarque          #+#    #+#             */
/*   Updated: 2019/03/29 20:09:35 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef struct s_point
{
	int miny;
	int minx;
	int maxx;
	int maxy;
}			t_point;

typedef	struct	s_square
{
	char **square;
	int size;
}				t_square;

void					ft_tetracking(char ***tetrab, int len_array);
int					ft_check_shape(char ***tab, int count);
int					main(int argc, char **argv);
int					ft_parser(int fd);
int					ft_sizetetra(char ***array, int bloc, int x, int y);
char				***ft_tetraclean(char ***tab);
char				***ft_stocktetra(int fd, int count, char *line);
void				printtab(char ***tab);
void				free_square(t_square *square);
void				ft_printresult(char **tab, int len_array);
t_point				*ft_findpoint(char ***tetrab,int bloc);
t_square			*ft_solve(char ***tetrab, int max);

#endif
