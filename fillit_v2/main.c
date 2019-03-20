/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:40:37 by humarque          #+#    #+#             */
/*   Updated: 2019/03/20 14:46:49 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	char *line;
	int count;
	char **tab;

	line = NULL;
	argc = 0;
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
		ft_putstr("error");
	else
	{
		tab = ft_stock_tab(fd2, count, line);
	}
	return (0);
}
