/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/02/19 21:06:19 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

char	***ft_malloc_tab(int count)
{
	char	***tab;
	int		i;
	int		j;
	int		num;
	int space;


	i = 0;
	j = 0;
	num = count / 5 + 1;
	space = num - 1;
	if (!(tab = (char ***)malloc(sizeof(char  **) * (space + 1))))
		return (NULL);
	while (i < space)
	{
		if (!(tab[i] = (char **)malloc(sizeof(char *) * (space + 1))))
			return (NULL);
		while (j < space)
		{
			if (!(tab[i][j++] = (char *)malloc(sizeof(char) * (2000))))
				return (NULL);
		}
		i++;
		j = 0;
	}
	return (tab);
}

char	***ft_stocktetra(int fd2, int count, char *line)
{
	char	***tab;
	int		num;
	int		x;
	int		y;
	int 	i;
	
	x = 0;
	y = 0;
	i = 0;
	num = 1;
	tab = ft_malloc_tab(count);
	while(get_next_line(fd2, &line) == 1)
	{
		printf(" line = %s\n",line);
		if (line[0] == '\0')
			num++;
		else
		{
			while (line[i])
			{
				tab[num][x][y] = line[i];
				y++;
				i++;
			}
			tab[num][x][y] = '\0';
			x++;
			i = 0;
			y = 0;
		}
	} 
	printf(" num = %d\n" , num);
	tab[num++][x][y] = 0;
	//ft_printtab(tab);
	return (tab);
}
