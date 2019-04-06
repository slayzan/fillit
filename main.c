/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:54 by mchamayo          #+#    #+#             */
/*   Updated: 2019/04/06 16:06:48 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			fd2;
	int			count;
	char		**tab;
	t_tetri		**first_tetri;
	t_square	*square;

	count = 0;
	first_tetri = NULL;
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
	if (!(fd2 = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!(count = ft_parser(fd)))
	{
		printf("error parser");
		return (0);
	}
	char **test;
	tab = ft_stocktetra(fd2, count);
//	if(!(ft_check_shape(tab, count)))
//		printf("error checkshape");
	count = (count + 1) / 5;
	first_tetri = ft_createlist(tab, count);
	square = ft_solve(first_tetri, count);
	ft_printresult(square->square, square->size);
	return (0);
}
