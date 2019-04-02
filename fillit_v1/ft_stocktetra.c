/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/04/02 16:17:51 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
char	***ft_malloc_tab(int count)
{
	char	***tab;
	int	i;
	int	j;
	int	num;
	int	line;

	i = 0;
	j = 0;
	num = count / 5 + 1;
	line = num * 4 + 1;
	if (!(tab = (char ***)malloc(sizeof(char **) * ((line + 1)))))
		return (NULL);
	while (i < line)
	{
		if (!(tab[i] = (char **)malloc(sizeof(char *) * (line + 1))))
			return (NULL);
		while (j < 5)
		{
			if (!(tab[i][j] = ft_strnew(line + 1)))
				return (NULL);
		}
		i++;
		j = 0;
	}
	return (tab);
}
// stocke les blocs de tetraminos dans un tableau tab[bloc][x][y]
// ou bloc est le nombre de blocs de tetraminos, x le nombre de lignes,
// et y le nombre de colonnes.

char	***ft_stocktetra(int fd2, int count, char *line)
{
	char	***tab;
	int		bloc;
	int		y;
	int		x;

	x = 0;
	y = 0;
	bloc = 0;
	tab = ft_malloc_tab(count);
	while (get_next_line(fd2, &line) == 1)
	{
		if (line[0] == '\0')
		{
			x = 0;
			bloc++;
		}
		else
		{
			while (line[y])
			{
				tab[bloc][x][y] = line[y];
				y++;
			}
			tab[bloc][x][y] = '\0';
			y = 0;
			x++;
		}
	}
	tab[bloc++][x++][y++] = 0;
	if (!ft_tetraclean(tab))
		return (0);
	return (tab);
}

void	free_square(t_square *square)
{
	int i;

	i = 0;
	while(i < square->size)
	{
		ft_memdel((void **)&(square->square[i]));
		i++;
	}
	ft_memdel((void **)&(square->square));
	ft_memdel((void **)&(square));
}
*/
t_tetri	*ft_create_tetri(char **tetrimino, int count)
{
	t_tetri *tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->shape = tetrimino;
	tetri->letter = 'A' + count;
	tetri->x = 0;
	tetri->y = 0;
	tetri->next = NULL;
	return (tetri);
}

char	**read_entry(char *str, int count)
{
	int 	fd;
	int 	ret;
	char	buf[BUFF_SIZE + 1];
	char	**tab;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tab = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	if (!(tab = (char **)malloc(sizeof(char *) * count + 1)))
		return (NULL);
	return (tab);
}

t_tetri 	*ft_stocktetra(char **tab, int count)
{
	int i;
	t_tetri	*first_tetri;
	t_tetri	*tmp;

	i = 0;
	first_tetri = NULL;
	tmp = NULL;
	first_tetri = ft_create_tetri(ft_strsplit(tab[0], '\n'), 0);
	tmp = first_tetri;
	while (i < count)
	{
		tmp->next = ft_create_tetri(ft_strsplit(tab[i], '\n'), i);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
