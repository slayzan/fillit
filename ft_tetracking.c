/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:39:38 by humarque          #+#    #+#             */
/*   Updated: 2019/03/06 14:22:47 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 	**ft_malloctab(int len_array)
{
	char **tab;
	int i;
	int j;
	int save;

	i = 0;
	j = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (len_array))))
	{
		free(tab);
		return(NULL);
	}
	while (tab[i])
	{
		if (!(tab[i++] =(char *)ft_memalloc(sizeof(char) * (len_array))))
		{
			save = i;
			i = 0;
			while (i < save)
				free(tab[i++]);
		}
		while (tab[i][j])
			tab[i][j++] = '.';
		j = 0;
	}

	return (tab);
}

int		ft_sizetetra(char ***array, int bloc, int x, int y)
{
	int sizex;
	int sizey;
	int stocky;
	int stockx;

	sizey = 0;
	sizex = 0;
	stockx = 0;
	stocky = 0;
	while (x < 3)
	{
		while (array[bloc][x][y])
		{
			if (array[bloc][x][y] == '#')
			{
				if(array[bloc][x][y + 1] == '#'
						&& array[bloc][x + 1][y]
						&& array[bloc][x + 1][y - 1] == '#')
					return (4);
				sizey++;
				sizex = 1;
			}
			y++;
			if (y== 4)
			{
				x++;
				y = 0;
				stocky = (sizey > stocky) ? sizey : stocky;
				sizey = 0;
				stockx = (sizex) ? stockx++ : stockx;
			}
		}
	}

	return((stockx >= stocky) ? stockx : stocky);

}

int ft_tetracking(int bloc)
{
  int len_array;
  char **tab;

  len_array = ft_sqrt((bloc * 4) + 1);
  printf("sqrt = %d\n", len_array);
  tab = ft_malloctab(len_array);
 return (0); 
}
