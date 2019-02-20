/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:57:31 by mchamayo          #+#    #+#             */
/*   Updated: 2019/02/20 18:33:32 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetradot(char ***tab)
{
	int bloc;
	int x;
	int y;
	int hash;

	hash = 0;
	x = 0;
	y = 0;
	bloc = 0;
	while (tab[bloc][x][y])
	{
		if (tab[bloc][x][y] == '#')
		{
			if (x - 1 != -1)
				hash += tab[bloc][x - 1][y] == '#' ? 1 : 0;
			hash += tab[bloc][x][y - 1] == '#' ? 1 : 0;
			hash += tab[bloc][x + 1][y] == '#' ? 1 : 0;
			hash += tab[bloc][x][y + 1] == '#' ? 1 : 0;
			if (hash == 6)
				return (1);
		}
		y++;
		if (y == 4)
		{
			x++;
			y = 0;		
		}
	}
	return 0;
}

int		ft_check_shape(char ***tab)
{
	if (ft_check_tetradot(tab) == 1)
	{
		printf("TETRAMINO IS COOL\n");
		return (1);
	}
	else
		printf("TETRAMINO EST POURRI\n");
	return (0);
}
