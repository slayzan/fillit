/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:51:40 by humarque          #+#    #+#             */
/*   Updated: 2019/04/06 13:55:57 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

t_point	*new_point(int x, int y)
{
	t_point	*new;

	new = ft_memalloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}

t_point *get_maxpoint(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t_point *max;

	max = new_point(0,0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (i > max->x)
					max->x = i;
				if (j > max->y)
					max->y = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

t_point	*get_minpoint(char **tab)
{
	int i;
	int j;
	t_point *min;

	min = new_point(3, 3);
	printf("%d = min",min->x);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (i < min->x)
					min->x = i;
				if (j < min->y)
					min->y = j;
			}
			j++;
		}
		i++;
	}
	return (min);
}

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
//	int save;

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

t_coord	*ft_findpoint(char ***tetrab,int bloc)
{
	t_coord *new;

	if((new = (t_coord*)ft_memalloc(sizeof(t_coord))))
	{
		new->minx = ft_findminx(tetrab,bloc);
		new->maxx = ft_findmaxx(tetrab,bloc);
		new->miny = ft_findminy(tetrab,bloc);
		new->maxy = ft_findmaxy(tetrab,bloc);
	}
	return (new);
}
