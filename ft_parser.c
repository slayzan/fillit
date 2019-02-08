/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/02/07 15:45:33 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

static int		ft_checkline(char *line,int count)
{
	int i;

	i = 0;
	if(count > 130)
		return (0);
	while (line[i])
	{
		if(line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	if (line[0] != '\0' && i != 4)
	{
		printf("fd\n");
		return (0);
	}
	return (1);
}

int		ft_checknewline(char *line, int new, int count)
{
	if (count == 1 && line[0] == '\0')
		return (2);
	if (line[0] != '\0')
		new = 0;
	else
		new++;
	return (new);
}

int	ft_counthastag(char *line, int hash)
{
	int i;

	i = 0;
	if (line[0] == '\0' )
		hash = 0;
	while (line[i])
	{
		if (line[i] == '#')
		   hash++;
		i++;
	}
	return (hash);
}
int main(int argc, char **argv)
{
	int new;
	int hash;
	int count;
	int tetra;
	char *line;
	int fd;

	tetra = 0;
	count = 0;
	new = 0;
	hash = 0;
	argc = 0;
	if(!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) == 1)
	{
		count++;
		tetra++;;
		if (!(ft_checkline(line, count)))
			printf("0");
		if ((new = ft_checknewline(line, new, count)) == 2)
			printf(" new line = 0");
		if(((hash = ft_counthastag(line, hash)) > 4))
			printf("erreur hash");
	}
//	ft_stocktetra(fd);
	printf("1");
}
