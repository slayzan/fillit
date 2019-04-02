/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:19:57 by humarque          #+#    #+#             */
/*   Updated: 2019/04/02 12:33:33 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

//Maloc le tableau de solution;
static t_square	*new_square(int size)
{
	t_square *new;
	int i;
	int j;

	i = 0;
	if((new = (t_square*)ft_memalloc(sizeof(t_square))))
	{
		new->size = size;
		if((new->square = (char **)ft_memalloc(sizeof(char *) * size)))
		{	// malloc taille total tableau
			while(i < size)
			{
				if(!(new->square[i] = ft_strnew(size)))
				{
					while (--i)
						free(new->square[i]);
					free(new->square);
					free(new);
				}		
				j =	 0;
				while(j < size)
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
static void		ft_place(t_square *board, char ***tetrab, int bloc, t_point *point, int s)
{
	t_coord *coord;
	int i;
	int j;

	coord = ft_findpoint(tetrab,bloc);
	i = coord->minx;
	while (i <= coord->maxx)
	{
		j = coord->miny;
		while (j <= coord->maxy)
		{
			if (tetrab[bloc][i][j] == '#')
					board->square[point->x + i - coord->minx][point->y + j - coord->miny] = 'A' + bloc;
			j++;
		}
		i++;
	}
}

//verifie si le tetramino a la place pour rentrer sur le board;
static int	ft_checkplace(t_square *board, char ***tetrab, int bloc,int x,int y)
{
	t_coord *point;
	int i;
	int j;

	point = ft_findpoint(tetrab,bloc);
	i = point->minx;
	while (i <= point->maxx)
	{
		j = point->miny;
		while (j <= point->maxy)
		{
			if (tetrab[bloc][i][j] == '#' && 
					board->square[x + i - point->minx][y + j - point->miny] != '.')
				return (0);
			j++;
					
		}
		i++;
	}
	ft_place(board,tetrab,bloc,new_point(x,y),'A' + bloc);
	return (1);
}

// recursive parcour le tableau et place tant checkplace ne renoie pas 0;
static int	ft_solveboard(t_square *board,char ***tetrab, int bloc, int max)
{
	int i;
	int j;
	t_coord *point;

	point = ft_findpoint(tetrab,bloc); 
	if (bloc == max)
		return (1);
	i = 0;
	while (i < board->size - point->maxx + point->minx)
	{
		j = 0;
		while (j < board->size - point->maxy + point->miny)	
		{
			if (ft_checkplace(board,tetrab,bloc,i,j))
			{
				if (ft_solveboard(board,tetrab,bloc + 1,max))
						return (1);
				else
					ft_place(board,tetrab,bloc,new_point(i,j),'.');//replace '.' si erreur
			}
		}
	}
	return (0);
}
//debut recursive creer le tablau l'agrandit si solveboard renvoie 0;
t_square	*ft_solve(char ***tetrab, int max)
{
	int len_array;
	int bloc;
	t_square	*board;

	len_array = 3;
	bloc = 0;
	board = new_square(len_array);
	if (!(ft_solveboard(board,tetrab,bloc,max)))
	{
		free_square(board);
		board = new_square(len_array++);
	}
	return (board);
}
