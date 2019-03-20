/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/03/13 19:15:49 by mchamayo         ###   ########.fr       */
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

void	printtab(char ***tab)
{
	int x;
	int y;
	int bloc;

	bloc = 0;
	x = 0;
	y = 0;

	while (tab[bloc][x][y])
	{
		printf("%c", tab[bloc][x][y]);
		y++;
		if (y == 4)
		{
			printf("\n");
			x++;
			if (x == 4)
			{
				printf("\n");
				bloc++;
				x = 0;
			}
			y = 0;
		}
	}
	printf("\n");
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
	printtab(tab);
	if (ft_check_shape(tab, bloc) == 1)
	{
		if (!ft_tetraclean(tab))
			return 0;
		return (tab);
	}
	return (0);
}

