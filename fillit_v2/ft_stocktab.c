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
	}
	ft_printtab(tab);
	return (tab);
}
