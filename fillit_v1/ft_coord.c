/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:51:40 by humarque          #+#    #+#             */
/*   Updated: 2019/03/28 20:47:30 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

static int	ft_findminx(char ***tetrab, int bloc)
{

	int y;
	int x;

	y = 0;
	x = 0;
	while (tetrab[bloc][x][y] != '#' && tetrab[bloc][x][y] != '\0')
	{
		if (y == 4)
		{
			x++;
			y = 0;
		}
		y++;
	}
	return (x);
}

static int	ft_findmaxx(char ***tetrab, int  bloc)
{
	int x;
	int y;
	int find;

	x = 0;
	y = 0;
	find = 0;
	while (find < 4)
	{
		y = 0;
		while (tetrab[bloc][x][y])
		{
			if (tetrab[bloc][x][y] == '#')
				find++;
			y++;
		}
		x++;
	}
	return (x);
}

static int	ft_findminy(char ***tetrab,int bloc)
{
	int y;
	int x;
	
	x = 0;
	y = 0;
	while (tetrab[bloc][x][y] != '#' && tetrab[bloc][x][y] != '\0')
	{
		if (x == 4)
		{
			y++;
			x = 0;
		}
		x++;
	}
	return (y);
}

static int		ft_findmaxy(char ***tetrab,int bloc)
{
	int y;
	int x;
	int find;
	int save;

	y = 0;
	x = 0;
	find = 0;
	while (find < 4)
	{
		
		if (tetrab[bloc][x][y] == '#')
			find++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}

	return (y);
}

t_point	*ft_findpoint(char ***tetrab,int bloc)
{
	t_point *new;

	if((new = (t_point*)ft_memalloc(sizeof(t_point))))
	{
		new->minx = ft_findminx(tetrab,bloc);
		new->maxx = ft_findmaxx(tetrab,bloc);
		new->miny = ft_findminy(tetrab,bloc);
		new->maxy = ft_findmaxy(tetrab,bloc);
	}
	return (new);
}
