/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/04/08 14:39:29 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_checkline(char *line, int count)
{
	int i;

	i = 0;
	if (count > 130)
		return (0);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	if (line[0] != '\0' && i != 4)
	{
		return (0);
	}
	return (1);
}

int			ft_checknewline(char *line, int new, int count)
{
	if (count == 1 && line[0] == '\0')
		return (2);
	if (line[0] != '\0')
		new = 0;
	else
		new++;
	return (new);
}

int			ft_counthastag(char *line, int *hash)
{
	int i;
	int res;

	res = 4;
	i = 0;
	if (line[0] == '\0')
	{
		if ((*hash) != 4)
			return (0);
		*hash = 0;
	}
	else
	{
		while (line[i])
		{
			if (line[i] == '#')
				(*hash)++;
			i++;
		}
	}
	return (1);
}

int			ft_numb_line(char *line, int count)
{
	if ((line[0] == '\0' && (count % 5 != 0))
		|| ((count % 5 == 0) && line[0] != '\0'))
		return (0);
	return (1);
}

int			ft_parser(int fd)
{
	int		new;
	int		hash;
	int		count;
	int		tetra;
	char	*line;

	tetra = 0;
	count = 0;
	new = 0;
	hash = 0;
	while (get_next_line(fd, &line) == 1)
	{
		count++;
		tetra++;
		if (!(ft_checkline(line, count))
			|| ((new = ft_checknewline(line, new, count)) == 2)
			|| (!(ft_counthastag(line, &hash)))
			|| (!(ft_numb_line(line, count))))
			return (0);
		free(line);
	}
	if (count % 5 != 4)
		return (0);
	return (count);
}
