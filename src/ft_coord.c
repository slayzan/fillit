/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:51:40 by humarque          #+#    #+#             */
/*   Updated: 2019/04/09 18:50:43 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*new_point(int x, int y)
{
	t_point	*new;

	if (!(new = ft_memalloc(sizeof(t_point))))
	{
		free(new);
		return (NULL);
	}
	new->x = x;
	new->y = y;
	return (new);
}

t_point		*get_maxpoint(char **tab)
{
	int		i;
	int		j;
	t_point *max;

	i = 0;
	j = 0;
	max = new_point(0, 0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (i > max->x)
					max->x = i;
				if (j > max->y)
					max->y = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

t_point		*get_minpoint(char **tab)
{
	int		i;
	int		j;
	t_point *min;

	min = new_point(3, 3);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (i < min->x)
					min->x = i;
				if (j < min->y)
					min->y = j;
			}
			j++;
		}
		i++;
	}
	return (min);
}
