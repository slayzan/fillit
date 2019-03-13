/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/03/13 16:44:20 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_malloc_tab(int count)
{
	char	***tab;
	int		i;
	int		j;
	int		num;
	int		line;

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
			if (!(tab[i][j++] = (char *)malloc(sizeof(char) * (5))))
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
/*	NE PAS SORTIR DES COMMENTAIRES SINON FAIT BEUG CHECK SHAPE
 	x = 0;
	bloc = 0;
	y = 0;
	while (tab[bloc])
	{
		while (tab[bloc][x][y])
		{
//			printf("%c", tab[bloc][x][y++]);
			y++;
		}
		x++;
		y = 0;

		if(x >= 4)
		{
			x = 0;
			bloc++;
		}
	}*/
//	printf("taille tetra = %d\n", ft_sizetetra(tab, 2, 0, 0));
	if (ft_check_shape(tab, bloc) == 1)
		return (tab);
	return (0);
}
