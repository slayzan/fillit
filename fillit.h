/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:23 by humarque          #+#    #+#             */
/*   Updated: 2019/03/06 14:40:47 by mchamayo         ###   ########.fr       */
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

typedef struct		s_verif
{
	int newline;
}					t_verif;

typedef struct		s_node
{
	int				number;
	char			*str;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

#endif
