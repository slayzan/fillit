/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:54 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/13 18:31:09 by mchamayo         ###   ########.fr       */
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
		tab = ft_stocktetra(fd2, count, line);
		printtab(tab);
		if (!tab)
			exit(EXIT_FAILURE);
		else
			ft_putendl("main : ft_stocktetra is ok");
	}
	return (0);
}
