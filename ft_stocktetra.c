/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/04/06 15:44:03 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_malloc_tab(char **tab, int count)
{
	int	i;
	int	j;
	int	num;
	int	line;

	i = 0;
	j = 0;
	num = count / 5 + 1;
	if (!(tab = (char **)malloc(sizeof(char *) * ((num + 1)))))
		return (NULL);
	while (i < num)
	{
		if (!(tab[i] = (char *)ft_memalloc(sizeof(char*) * 21)))
		{
			while (--i)
			{
				free(tab[i]);
			}
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void		free_square(t_square *square)
{
	int i;

	i = 0;
	while (i < square->size)
	{
		ft_memdel((void **)&(square->square[i]));
		i++;
	}
	ft_memdel((void **)&(square->square));
	ft_memdel((void **)&(square));
}

static char	**ft_tabcreate(char *str, char **tab, int bloc)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	s2 = ft_memalloc(sizeof(char) * 21);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (bloc + 1))))
		return (NULL);
	while (i < bloc)
	{
		j = 0;
		s2 = ft_strncpy(s2, str, 16);
		if (!(tab[i] = (char*)malloc(sizeof(char *) * 21)))
			return (NULL);
		tab[i] = ft_strdup(s2);
		tab[i][17] = '\0';
		while (j < 16)
		{
			str++;
			j++;
		}
		i++;
		ft_strclr(s2);
	}
	free(s2);
	tab[i] = 0;
	return (tab);
}

char		**ft_stocktetra(int fd, int count)
{
	char	**tab;
	int		i;
	int		bloc;
	char	*str;
	char	*line;

	bloc = ((count + 1) / 5);
	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 21)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != '\0')
			str = ft_strjoin(str, line);
		free(line);
	}
	if (!(tab = ft_tabcreate(str, tab, bloc)))
	{
		return (NULL);
	}
	return (tab);
}
