/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:57:31 by mchamayo          #+#    #+#             */
/*   Updated: 2019/02/26 17:34:08 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_hash(char ***tab, int bloc, int x, int y)
{
	int hash;

	hash = 0;
	if (x - 1 != -1)
		hash += tab[bloc][x - 1][y] == '#' ? 1 : 0;
	hash += tab[bloc][x][y - 1] == '#' ? 1 : 0;
	hash += tab[bloc][x + 1][y] == '#' ? 1 : 0;
	hash += tab[bloc][x][y + 1] == '#' ? 1 : 0;
	if (hash == 0)
		return (0);
	return (hash);
}

int		ft_check_tetradot(char ***tab)
{
	int bloc;
	int x;
	int y;
	int hash;

	x = 0;
	y = 0;
	bloc = 0;
	hash = 0;
	while (tab[bloc][x][y])
	{
		if (tab[bloc][x][y] == '#')
		{
			hash = ft_count_hash(tab, bloc, x, y) + hash;
		}
		y++;
		if (y == 4)
		{
			x++;
			printf ("x = %d\n", x);
			if (x == 4)
			{
				bloc++;
				x = 0;
				printf("bloc = %d, hash = %d, x = %d, y = %d\n", bloc, hash, x, y);
			}
			y = 0;
		}
	}
	return (hash);
}

int		ft_check_shape(char ***tab)
{
	int hash;

	hash = ft_check_tetradot(tab);
	printf("%d\n", hash);
	return (0);
}
