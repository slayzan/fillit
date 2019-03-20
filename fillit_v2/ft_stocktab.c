/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:54 by mchamayo          #+#    #+#             */
/*   Updated: 2019/03/13 18:31:09 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab(char **tab, char *line, int count)
{
	int	i;
	int	x;
	int	y;
	int	nb_tet;

	i = 0;
	x = 0;
	y = 0;
	nb_tet = (count / 5);
	while (x < nb_tet)
	{
		if(!(tab[x] = (char*)malloc(sizeof(char) * 20 + 1)))
			return (NULL);
		while (y < 20)
		{
			tab[x][y] = line[i];
			y++;
			i++;
		}
		tab[x][20] = '\0';
		y = 0;
		x++;
		i++;
	}
	tab[y] = NULL;
	return (tab);
}

void	ft_printtab(char **tab)
{
	int x;

	x = 0;
	while (tab[x] != NULL)
	{
		printf("%s\n", tab[x]);
		x++;
	}
}

char **ft_stock_tab(int fd, int count, char *line)
{
	char	**tab;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count / 5 + 1))))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		tab = create_tab(tab, line, count);
		printf("%s\n", line);
	}
	ft_printtab(tab);
	return (tab);
}
