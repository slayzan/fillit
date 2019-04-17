/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/04/17 15:18:51 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char		**ft_malloc_tab(char **tab, int count)
{
	int	i;
	int	j;
	int	num;

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
	if (!(s2 = ft_memalloc(sizeof(char) * 16)))
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (bloc + 1) + 1)))
		return (NULL);
	while (i < bloc)
	{
		j = 0;
		s2 = ft_strncpy(s2, str, 16);
		tab[i] = ft_strdup(s2);
		while (j++ < 16)
			str++;
		i++;
		ft_strclr(s2);
	}
	free(s2);
	tab[i] = 0;
	return (tab);
}

char		**ft_stocktetra(int fd, int count, int bloc)
{
	char	**tab;
	char	*str;
	char	*tmp;
	char	*line;

	tab = NULL;
	if (!(str = ft_memalloc(sizeof(char) * (16 * bloc) + 1)))
		return (NULL);
	if (!(tmp = ft_memalloc(sizeof(char) * (4))))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != '\0')
		{
			tmp = ft_strcpy(tmp, line);
			str = ft_strcat(str, tmp);
			ft_strclr(tmp);
		}
		free(line);
	}
	ft_strdel(&tmp);
	if (!(tab = ft_tabcreate(str, tab, count)))
		return (NULL);
	ft_strdel(&str);
	return (tab);
}
