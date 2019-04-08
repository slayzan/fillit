/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:19:57 by humarque          #+#    #+#             */
/*   Updated: 2019/04/06 15:41:09 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Malloc le tableau de solution;

static t_square	*new_square(int size)
{
	t_square	*new;
	int			i;
	int			j;

	i = 0;
	if ((new = (t_square*)ft_memalloc(sizeof(t_square))))
	{
		new->size = size;
		if ((new->square = (char **)ft_memalloc(sizeof(char *) * size)))
		{
			while (i < size)
			{
				if (!(new->square[i] = ft_strnew(size)))
				{
					while (--i)
						free(new->square[i]);
					free(new->square);
					free(new);
				}
				j = 0;
				while (j < size)
				{
					new->square[i][j] = '.';
					j++;
				}
				i++;
			}
		}
	}
	return (new);
}

// place le tetramino sur le board

static void		ft_place(t_square *board, t_tetri *tet, t_point *point, char s)
{
	int	i;
	int j;
	int mi;
	int mj;

	mi = tet->min->x;
	mj = tet->min->y;
	i = mi;
	while (i <= tet->max->x)
	{
		j = mj;
		while (j <= tet->max->y)
		{
			if (tet->shape[i][j] == '#')
				board->square[point->x + i - mi][point->y + j - mj] = s;
			j++;
		}
		i++;
	}
}

//verifie si le tetramino a la place pour rentrer sur le board;

static int		ft_checkplace(t_square *board, t_tetri *tetra, int x, int y)
{
	int i;
	int j;
	int mi;
	int mj;

	mi = tetra->min->x;
	mj = tetra->min->y;
	i = mi;
	while (i <= tetra->max->x)
	{
		j = mj;
		while (j <= tetra->max->y)
		{
			if (tetra->shape[i][j] == '#' &&
					board->square[x + i - mi][y + j - mj] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_place(board, tetra, new_point(x, y), tetra->letter);
	return (1);
}

// recursive parcour le tableau et place tant checkplace ne renoie pas 0;

static int		ft_solveboard(t_square *board, t_tetri **tet, int bloc, int ac)
{
	int i;
	int j;

	if (ac == bloc)
		return (1);
	i = 0;
	while (i < board->size - tet[ac]->max->x + tet[ac]->min->x)
	{
		j = 0;
		while (j < board->size - tet[ac]->max->y + tet[ac]->min->y)
		{
			if (ft_checkplace(board, tet[ac], i, j))
			{
				if (ft_solveboard(board, tet, bloc, ac + 1))
					return (1);
				else
					ft_place(board, tet[ac], new_point(i, j), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

//debut recursive creer le tablau l'agrandit si solveboard renvoie 0;

t_square		*ft_solve(t_tetri **tetra, int bloc)
{
	int			len_array;
	t_square	*board;

	len_array = 2;
	board = new_square(len_array);
	while (!ft_solveboard(board, tetra, bloc, 0))
	{
		len_array++;
		free_square(board);
		board = new_square(len_array);
	}
	return (board);
}
