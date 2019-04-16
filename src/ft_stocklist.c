/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocklist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:37:18 by humarque          #+#    #+#             */
/*   Updated: 2019/04/16 14:34:06 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**ft_splittab(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tab;

	i = 0;
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * (4))))
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (NULL);
	while (i < 4)
	{
		j = 0;
		tmp = ft_strncpy(tmp, str, 4);
		tab[i] = ft_strdup(tmp);
		i++;
		while (j++ < 4)
			str++;
		ft_strclr(tmp);
	}
	free(tmp);
	return (tab);
}

t_tetri				**ft_createlist(char **tab, int bloc)
{
	int			i;
	t_tetri		**new;

	if (!(new = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * bloc)))
		return (NULL);
	i = 0;
	while (i < bloc)
	{
		if (!(new[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
			return (NULL);
		new[i]->shape = ft_splittab(tab[i]);
		new[i]->min = get_minpoint(new[i]->shape);
		new[i]->max = get_maxpoint(new[i]->shape);
		new[i]->letter = 'A' + i;
		i++;
	}
	return (new);
}
