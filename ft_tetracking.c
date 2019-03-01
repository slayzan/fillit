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

/*int		ft_puttetra(char **tab,char ***array, int bloc)
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
  */
int		ft_sizetetra(char ***array, int bloc)
{
	int x;
	int y;
	int sizex;
	int sizey;
	int stocky;
	int stockx;

	x = 0;
	y = 0;
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
				sizey++;
				sizex = 1;
			}
			y++;
			if (y== 4)
			{
				printf("x = %d\n", x);
				x++;
				y = 0;
				stocky = (sizey > stocky) ? sizey : stocky;
				sizey = 0;
				printf("stocky = %d", stocky);
				stockx = (sizex) ? stockx++ : stockx;
			}
		}
	}

	return((stockx >= stocky) ? stockx : stocky);

}
/*int ft_malloc_array(int bloc)
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
  }*/
