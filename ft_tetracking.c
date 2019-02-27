/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:20:56 by humarque          #+#    #+#             */
/*   Updated: 2019/02/27 17:21:04 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_putpiece(char **solver, char ***tab, int height)
{
	int i;
	int j;
	int y;
	int x;
	int bloc;

	i = 0;
	y = 0;
	x = 0;
	j = 0;
	bloc = 0;
	while (tab[bloc][x][y])
	{
		if(tab[bloc][x][y] == '#')
		{
			solver[i][y] = '65' + bloc;
		}
		if(x == 4)
		{
			x = 0;
			if (i > height)
				return (0);
			else
				i++;
		}
	}
}


char	**ft_allocsize(char **tab,int height, int width)
{
	int x;
	int save;

	x = 0;
	if(!(tab = ft_memalloc(sizeof(char *) * height)))
	{
		free(tab);
		return (NULL);
	}
	while (x < height)
	{
		if(!(tab[x] = ft_memalloc(sizeof(char) * (width + 1))))
		{
			save = x;
			x = 0;
			while (x < save)
				free(tab[x++]);
			free(tab);
		}
		x++;
	}
	return (tab);
}

int		ft_resolve(char ***tab)
{
	char **solver;
	int height;
	int width;
	int resultat;
	int i;

	height = 4;
	width = 4;
	i = 0;
	if(!(solver = ft_allocsize(solver,height,width)))
		return (NULL);

	while (i <= width)
		 solver[i++] = '.';
	resultat = ft_putpiece(tab,solver);	
}
