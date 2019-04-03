/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocktetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:09 by humarque          #+#    #+#             */
/*   Updated: 2019/04/03 15:09:32 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char	**ft_malloc_tab(char **tab, int count)
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
		if(!(tab[i] = (char *)ft_memalloc(sizeof(char*) * 21)))
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


void	free_square(t_square *square)
{
	int i;

	i = 0;
	while(i < square->size)
	{
		ft_memdel((void **)&(square->square[i]));
		i++;
	}
	ft_memdel((void **)&(square->square));
	ft_memdel((void **)&(square));
}
/*
t_tetri	*ft_create_tetri(char **tetrimino, int count)
{
	t_tetri *tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->shape = tetrimino;
	tetri->letter = 'A' + count;
	tetri->x = 0;
	tetri->y = 0;
	tetri->next = NULL;
	return (tetri);
}

char	**read_entry(char *str, int count)
{
	int 	fd;
	int 	ret;
	char	buf[BUFF_SIZE + 1];
	char	**tab;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tab = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	if (!(tab = (char **)malloc(sizeof(char *) * count + 1)))
		return (NULL);
	return (tab);
}

t_tetri 	*ft_stocktetra(char **tab, int count)
{
	int i;
	t_tetri	*first_tetri;
	t_tetri	*tmp;

	i = 0;
	first_tetri = NULL;
	tmp = NULL;
	first_tetri = ft_create_tetri(ft_strsplit(tab[0], '\n'), 0);
	tmp = first_tetri;
	while (i < count)
	{
		tmp->next = ft_create_tetri(ft_strsplit(tab[i], '\n'), i);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
*/
static char **ft_tabcreate(char *str, char **tab, int bloc)
{
	int i;
	int j;
	char *s2;

	i = 0;
	s2 = ft_memalloc(sizeof(char) * 21);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (bloc + 1))))
		return (NULL);
	while (i < bloc)
	{
		j = 0;
		s2 = ft_strncpy(s2, str, 16);
		if(!(tab[i] = (char*)malloc(sizeof(char *) * 21)))
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

char  **ft_stocktetra(int fd,int count)
{
	char **tab;
	int i;
	int bloc;
	char *str;
	char *line;

	bloc = ((count + 1) / 5);
	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 21)))
		return (NULL);
	while(get_next_line(fd,&line) == 1)
	{
		if (line[0] != '\0')
		{
			str = ft_strjoin(str,line);
		}
		free(line);
	}
	if(!(tab = ft_tabcreate(str, tab, bloc)))
	{
		return (NULL);
	}
	return (tab);
}
