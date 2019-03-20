/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:37:27 by humarque          #+#    #+#             */
/*   Updated: 2019/03/20 14:37:35 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>

typedef struct		s_tra
{
	char		**tet;
	int		x;
	int		y;
	char		letter;
	struct s_tra	*next;
	struct s_tra	*prev;
}			t_tra;

int			main(int argc, char **argv);
int			ft_parser(int fd);
char			**ft_stock_tab(int fd, int count, char *line);

#endif
