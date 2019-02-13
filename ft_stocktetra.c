/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/02/13 15:37:24 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

char	***ft_malloc_tab(int count)
{
	char	***tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char ***)malloc(sizeof((char **) * (num + 1)))))
		return (NULL);
	while (i < count)
	{
		if (!(tab[i++] = (char **)malloc(4 * sizeof(char *))))
			return (NULL);
		while (j < 4)
		{
			if (!(tab[i][j++] = (char *)malloc(5 * sizeof(char))))
				return (NULL);
		}
	}
	return (tab);
}

char	***ft_stocktetra(int fd, int count)
{
	char	*line;
	char	***tab;
	int		num;
	int		x;
	int		y;

	x = 0;
	y = 0;
	num = count / 5 + 1;
	printf("Number of blocs = %d\n", num);
	tab = ft_malloc_tab(x, y, num);
}
