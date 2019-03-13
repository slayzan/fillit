/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetraclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:52:24 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/13 19:17:45 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_TabToLeft(int ymin, char ***tab)
{
	int replace;
	int x;
	int y;
	int bloc;

	replace = 0;
	x = 0;
	y = 0;
	bloc = 0;
	if (ymin > 0)
	{
		while (tab[bloc][x][y])
		{
			if (tab[bloc][x][y] == '#')
			{
				tab[bloc][x][y - ymin] = tab[bloc][x][y];
				tab[bloc][x][y] = '.';
			}
			y++;
			replace = ymin - 1;
			if (y == 4)
			{
				x++;
				y = 0;
			}
		}
		return (tab);
	}
	return (tab);
}

int		ft_search_xmin(char ***tab)
{
	int y;
	int x;
	int bloc;

	y = 0;
	x = 0;
	bloc = 0;
	while (tab[bloc][x][y] != '#' && tab[bloc][x][y] != '\0')
	{
		y++;
		if (y == 4)
		{
			x++;
			y = 0;
		}
	}
	return (x);
}

int		ft_search_ymin(char ***tab)
{
	int y;
	int x;
	int bloc;

	bloc = 0;
	x = 0;
	y = 0;
	while (tab[bloc][x][y] != '#' && tab[bloc][x][y] != '\0')
	{
		x++;
		if (x == 4)
		{
			y++;
			x = 0;
		}
	}
	return (y);
}

char	***ft_tetraclean(char ***tab)
{
	printf("ymin = %d\n", ft_search_ymin(tab));
	printf("xmin = %d\n", ft_search_xmin(tab));
	ft_TabToLeft(ft_search_ymin(tab), tab);
	printtab(tab);
	return (tab);
}
