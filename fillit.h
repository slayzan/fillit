/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:23 by humarque          #+#    #+#             */
/*   Updated: 2019/03/13 15:55:12 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <math.h>

int					ft_tetracking(int bloc);
int					ft_check_shape(char ***tab, int count);
int					main(int argc, char **argv);
int					ft_parser(int fd);
int					ft_sizetetra(char ***array, int bloc, int x, int y);
char				***ft_stocktetra(int fd, int count, char *line);

typedef struct		s_tra
{
	char			**tet;
	int 			x;
	int				y;
	char			letter;
	struct s_tra	*next;
	struct s_tra	*previous;
}					t_tra;

#endif
