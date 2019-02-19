/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:57:23 by humarque          #+#    #+#             */
/*   Updated: 2019/02/19 20:45:02 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

int					main(int argc, char **argv);
int					ft_parser(int fd, int fd2);
char				***ft_stocktetra(int fd, int count, char *line);
void				ft_printtab(char ***tab);

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
