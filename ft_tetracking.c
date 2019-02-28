/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:39:38 by humarque          #+#    #+#             */
/*   Updated: 2019/02/28 18:30:42 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_puttetra(char **tab,char ***array, int bloc)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (bloc != bloc + 1)
	{
		while (tab[i])
		{
			if (tab[i][y] == '.')
			{
				
			}
		}
	}	
}

int		sizetetra(char ***array, int bloc, int x)
{
	int y;
	int i;
	int stockj;
	int find;

	y = -1;
	i = 0;
	stockj = 0;
	find = 0;
	while (x <= 4)
	{
		while(array[bloc][x][y])
		{
			if(array[bloc][x][y] == '#')
			{
				j++;
				find = 1;
			}
			y++;
			if (y == 5)
			{
				stockj = (stockj < j) ? j : stockj;
				i = (find) ? i++ : i;
				j = 0;
				find = 0;
				x++;
			}
		}
	}
		
}

int ft_malloc_array(int bloc)
{
	int len_array;
	
	len_array = sqrt(bloc * 4) + 1;
	printf("sqrt = %d\n", len_array);
	return (len_array);
}

int ft_tetracking(char ***tab, int bloc)
{
	tab = 0;
	ft_malloc_array(bloc);
	return (0);
}
