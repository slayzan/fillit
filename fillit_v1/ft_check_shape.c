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

int		ft_count_hash(char **tab, int x, int y)
{
	int hash;

	hash = 0;
	if (y - 1 != -1)
		hash += tab[x][y - 1] == '#' ? 1 : 0;
	hash += tab[x][y + 1] == '#' ? 1 : 0;
	hash += tab[x][y - 4] == '#' ? 1 : 0;
	hash += tab[x][y + 4] == '#' ? 1 : 0;
	if (hash == 0)
		return (0);
	return (hash);
}

int		ft_check_tetradot(char **tab, int count)
{
	int	hash;
	int	x;
	int	y;

	x = 0;
	y = 0;
	hash = 0;
	while (tab[x][y])
	{
		if (tab[x][y] == '#')
		{
			hash = ft_count_hash(tab, x, y) + hash;
			printf("hash = %d\n", hash);
		}
		printf("y = %d\n", y);
		y++;
		if (y == 16 && x < count)
		{
			x++;
			y = 0;
		}
	}
	return (hash);
}

int		ft_check_shape(char **tab, int count)
{
	int hash;
	int ret;

	hash = 0;
	ret = 6 * ((count + 1) / 5);
	count = (count + 1) / 5 - 1;
	hash = ft_check_tetradot(tab, count);
	printf("count = %d\n", ret);
	if (hash >= ret)
		return (1);
	return (0);
}
