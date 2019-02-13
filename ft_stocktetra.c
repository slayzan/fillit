/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/02/13 20:15:24 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

char	***ft_malloc_tab(int num)
{
	char	***tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char ***)malloc(sizeof(char  **) * (num + 1))))
		return (NULL);
	while (i < num)
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
	int 	i;

	x = 0;
	y = 0;
	i = 0;
	num = 0;
	printf("Number of blocs = %d\n", num);
	tab = ft_malloc_tab(count/ 5 + 1);
	while (get_next_line(fd,&line) == 1)
	{
		while(line[i])
		{
			tab[num][x][y++] = line[i++];
		}
		x++;
		if(line[0] == '\0')
			num++;
	}
	tab[num][x][y] = 0;
	ft_printtab(tab);
	return (tab);
}