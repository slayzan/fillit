/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:54 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/29 20:05:01 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		count;
	char	*line;
	char	***tab;
	t_square *board;
	t_point  *point;

	line = NULL;
	argc = 0;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!(fd2 = open(argv[1], O_RDONLY)))
	{
		close(fd2);
		exit(EXIT_FAILURE);
	}
	if (!(count = ft_parser(fd)))
		printf("error");
	else
	{
		if(!(tab = ft_stocktetra(fd2, count, line)))
			return (0);
		point = ft_findpoint(tab, 1);
		printf("%d", point->maxy);
		/*board = ft_solve(tab,7);
		ft_printresult(board->square,15);*/
	}
	return (0);
}
