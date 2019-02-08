/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/02/08 16:08:51 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

char	***ft_puttab(char **line, char ****tab, int x, int y, int num)
{
	int i;

	i = 0;
	if(line[0] == '\0')
	{
		num++;
		return (tab);
	}
	while(line[i])
	{
		tab[num][x][y] = line[i];
		y++;
		i++;
	}
	tab[num][x][y] = '\0';
	return (tab);
}	

char	***ft_stocktetra(int fd)
{
	char *line;
	char ***tab;
	int x;
	int y;
	int num;

	x = 0;
	y = 0;
	num	
	while (get_next_line(fd, &line) == 1)
	{
		ft_puttab(line,tab, &x, &y, &num);
	}
}
