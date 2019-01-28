/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/01/28 13:10:58 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

static t_node *ft_puttotab(char *line, t_node lst)
{
	int i;
	static int j;
	static int k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i])
		lst->tab[j][k++] = line[i++];
	j++;
	return (lst);
}

static int		ft_checkline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if(line[i] != '.' || line[i] != '#')
			return (0);
		if(i > 4)
			return (0);
		i++;
	}
	return (1);
}

t_node *ft_count(char *line, int count)
{
	static t_node *lst;
	int res; 
	if(count < 105)
		printf("trop de tetraminos");
	else
	{	
		if(!(ft_checkline(line)))
			printf("erreur");

	}	
}

int main(int argc, char **argv)
{
	int count;
	char *line;
	int fd;

	count = 0;
	if(!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) == 1)
	{
		count++;
		ft_stock(line, count);
	}
}
