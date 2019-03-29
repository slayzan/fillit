/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:39:38 by humarque          #+#    #+#             */
/*   Updated: 2019/03/29 18:19:11 by humarque         ###   ########.fr       */
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
	{
		free(tab);
		return (NULL);
	}
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
		printf("%d",y);
		//printf("%c", tab[x][y - 1]);
		if (tetrab[bloc][x][y] == '#' && tab[x][y] == '.')
		{
			tab[i + x][j + y] = '#';
			tetrab[bloc][x][y] = '.';
			put++;
		}
		while (tetrab[bloc][x][y] != '#'  &&  tetrab[bloc][x][y])
		{
			y++;
		}
		if (((i + x) > len_array) || (j + y) > len_array)
		{
			return (0);
		}
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

char **freetab(char **tab, int len_array)
{
	int i;

	i = 0;
	while (i <= len_array)
	{
		free(tab[i++]);
	}
	free(tab);
	return (tab);
}
/*void	test(char **tab, char ***tetrab, int len_array)
{
	tab = ft_malloctab(len_array,tab);

}
*/

void	ft_track(char ***tetrab, char **tab, int len_array, int bloc)
{
	tab = NULL;
	if(!(tab = ft_malloctab(len_array, tab)))
	{
		freetab(tab,len_array);
		exit(EXIT_FAILURE);
	}
	if((ft_firsttetra(tab,bloc,tetrab,len_array) == 0))
	{
		freetab(tab,len_array);
		ft_track(tetrab,tab,len_array + 1, bloc);
	}

}

void ft_tetracking(char ***tetrab, int len_array)
{
  	char **tab;
	int bloc;
	
	tab = NULL;	
	bloc = 0;
	ft_track(tetrab,tab,len_array,bloc);
//	ft_print(tab);
}


