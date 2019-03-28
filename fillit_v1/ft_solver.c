/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:19:57 by humarque          #+#    #+#             */
/*   Updated: 2019/03/28 18:00:30 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

t_square	new_square(int size)
{
	t_board *new;
	int i;
	int j;

	i = 0;
	new = (t_board*)ft_memalloc(size(t_board)); //malloc le maillon
	new->size = size;
	new->square = (char **)ft_memalloc(sizeof(char *) * size); // malloc taille total tableau
	while(i < size)
	{
		new->square[i] = ft_strnew(size);
		j = 0;
		while(j < size)
		{
			new->square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new);
}

int	ft_solveboard(t_square *square,char ***tetrab, int bloc)
{
	int i;
	int j;

	i = 0;

}
t_square	*ft_solve(char ***tetrab)
{
	int len_array;
	t_square	*square;

	len_array = 3;
	square = new_square(len_array);

}
