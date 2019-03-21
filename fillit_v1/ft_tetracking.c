/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:39:38 by humarque          #+#    #+#             */
/*   Updated: 2019/03/21 17:27:19 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
static char 	**ft_malloctab(int len_array, char **tab)
{
	int i;
	int j;
	int save;

	len_array = 0;
	i = 0;
	j = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (20 + 1))))
	{
		free(tab);
		return(NULL);
	}
	while (tab[i])
	{
		if (!(tab[i++] =(char *)ft_memalloc(sizeof(char) * (20 + 1))))
		{
			save = i;
			i = 0;
			while (i < save)
				free(tab[i++]);
		}
	}
	tab[i] = 0;
	i = 0;
	
	while (tab[i] != 0)
	{
		while (tab[i][j])
		{	tab[i][j++] = '.';
		}
			i++;
		j = 0;
	}

	return (tab);
}*/

char **ft_malloctab(int len_array, char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * len_array + 1)))
		return (NULL);
	while (y < len_array)
	{
		if (!(tab[y] = (char *)ft_memalloc(sizeof(char) * len_array + 1)))
			return (NULL);
		y++;
	}
	y = 0;
	while (x < len_array)
	{
		while (y < len_array)
			tab[x][y++] = '.';
		tab[x][y] = '\0';
		y = 0;
		x++;
	}
	tab[x] = NULL;
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

int 	ft_firsttetra(char **tab, int bloc, char ***tetrab, int len_array)
{
	int x;
	int y;
	int i;
	int j;
	int put;
	
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	put = 0;
	while (put != 4)
	{
		if (tetrab[bloc][x][y] == '#' && tab[i + x][j + y] == '.')
		{
			tab[i + x][j + y] = '#';
			tetrab[bloc][x][y] = '.';
			put++;
		}
		while (tetrab[bloc][x][y] != '#'  &&  tetrab[bloc][x][y])
			y++;
		if (((i + x) > len_array) || (j + y) > len_array)
			return (0);
		if(y == 4  && tetrab[bloc][x][y] != '#')
		{
			y = 0;
			x++;
		}
	}
	return (1);
}

void	ft_print(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int ft_tetracking(char ***tetrab)
{
  	char **tab;
	int		len_array;
	int res;

	len_array = 2;
	tab = NULL;
	tab = ft_malloctab(len_array, tab);
	//ft_print(tab);
	res = ft_firsttetra(tab, 0, tetrab, len_array);
	ft_print(tab);
	printf("res = %d\n", res);
	return (0); 
}


