/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocklist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:37:18 by humarque          #+#    #+#             */
/*   Updated: 2019/04/09 12:04:55 by mchamayo         ###   ########.fr       */
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
	tmp = (char*)ft_memalloc(sizeof(char) * (21));
	tab = (char **)ft_memalloc(sizeof(char *) * 4);
	while (i < 4)
	{
		j = -1;
		tmp = ft_strncpy(tmp, str, 4);
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char*) * 5)))
			return (NULL);
		tab[i] = ft_strdup(tmp);
		tab[i++][5] = '\0';
		while (++j < 4)
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

	new = (t_tetri**)ft_memalloc(sizeof(t_tetri*) * bloc);
	i = 0;
	while (i < bloc)
	{
		new[i] = (t_tetri*)ft_memalloc(sizeof(t_tetri));
		new[i]->shape = ft_splittab(tab[i]);
		new[i]->min = get_minpoint(new[i]->shape);
		new[i]->max = get_maxpoint(new[i]->shape);
		new[i]->letter = 'A' + i;
		i++;
	}
	return (new);
}
