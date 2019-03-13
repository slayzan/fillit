/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetraclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:52:24 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/13 18:35:22 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	return (tab);
}
