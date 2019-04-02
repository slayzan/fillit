/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:54 by mchamayo          #+#    #+#             */
/*   Updated: 2019/04/02 16:08:18 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**tab;
	int		count;
	t_tetri		*first_tetri;
//	int		fd2;
//	char	*line;
//	t_square *board;
//	t_point  *point;
	
	count = 0;
	first_tetri = NULL;
	tab = NULL;
	if (argc != 2)
	{
		printf("error argc");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!(count = ft_parser(fd)))
	{
		printf("error parser");
		return (0);
	}
	if ((tab = read_entry(argv[1], (count % 5) + 1)) == NULL)
	{
		printf("error read_entry\n");
		return (0);
	}
	first_tetri = ft_stocktetra(tab, ((count % 5) + 1));
/*
	line = NULL;
	argc = 0;
	if (!(fd2 = open(argv[1], O_RDONLY)))
	{
		close(fd2);
		exit(EXIT_FAILURE);
	}
	if (!(count = ft_parser(fd)))
		printf("error");
	printf("count = %d\n", count);
	else
	{
		if(!(tab = ft_stocktetra(fd2, count, line)))
			return (0);
		board = ft_solve(tab,7);
		//ft_printresult(board->square,15);
	}*/
	return (0);
}
