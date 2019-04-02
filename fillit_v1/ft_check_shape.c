/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:57:31 by mchamayo          #+#    #+#             */
/*   Updated: 2019/04/02 12:18:05 by humarque         ###   ########.fr       */
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

int		ft_check_tetradot(char ***tab, int x, int y)
{
	int bloc;
	int hash;

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
			if (x == 4)
			{
				bloc++;
				x = 0;
			}
			y = 0;
		}
	}
	return (hash);
}

int		ft_check_shape(char ***tab, int count)
{
	int hash;
	int ret;

	ret = 6 * count;
	hash = ft_check_tetradot(tab, 0, 0);
	if (hash >= ret)
		return (1);
	return (0);
}
