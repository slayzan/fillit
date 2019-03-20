/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetraclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:52:24 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/13 19:26:33 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_TabToUp(int xmin, char ***tab)
{
	int x;
	int y;
	int bloc;

	x = 0;
	y = 0;
	bloc = 0;
	if (xmin > 0)
	{
		while (tab[bloc][x][y])
		{
			if (tab[bloc][x][y] == '#')
			{
				tab[bloc][x - xmin][y] = tab[bloc][x][y];
				tab[bloc][x][y] = '.';
			}
			x++;
			if (x == 4)
			{
				y++;
				if (y == 4)
					bloc++;
				x = 0;
			}
		}
		return (tab);
	}
	return (tab);
}

char	***ft_TabToLeft(int ymin, char ***tab)
{
	int x;
	int y;
	int bloc;

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
			if (y == 4)
			{
				x++;
				if (x == 4)
					bloc++;
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
	while (***tab)
	{
		ft_TabToLeft(ft_search_ymin(tab), tab);
		ft_TabToUp(ft_search_xmin(tab), tab);
		tab++;
	}
	return (tab);
}
