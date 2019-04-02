/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:23 by humarque          #+#    #+#             */
/*   Updated: 2019/04/02 17:15:22 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef struct s_coord
{
	int minx;
	int maxx;
	int miny;
	int maxy;
}			t_coord;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_square
{
	char **square;
	int size;
}				t_square;

typedef	struct s_tetri
{
	char	**shape;
	int		x;
	int		y;
	char	letter;
	struct	s_tetri *next;
	struct	s_tetri *prev;

} 				t_tetri;

char **ft_strsplitlol(char const *s, char c);
void	ft_printresult(char **tab, int len_array);
char				**read_entry(char *str, int count);
int					ft_count_tetri(char *str);
void					ft_tetracking(char ***tetrab, int len_array);
int					ft_check_shape(char ***tab, int count);
int					main(int argc, char **argv);
int					ft_parser(int fd);
int					ft_sizetetra(char ***array, int bloc, int x, int y);
char				***ft_tetraclean(char ***tab);
char 				**ft_stocktetra(int fd, int count);
void				printtab(char ***tab);
void				free_square(t_square *square);
void				ft_printresult(char **tab, int len_array);
t_point				*new_point(int x, int y);
t_coord				*ft_findpoint(char ***tetrab,int bloc);
t_square			*ft_solve(char ***tetrab, int max);

#endif
