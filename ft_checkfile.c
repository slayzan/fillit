/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/01/23 17:01:22 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"


t_node	*ft_stock(const int fd)
{	
	char *line;
	t_node *lst;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (get_next_line(fd, &line))
	{
		while(line[i] == '.' || line[i] == '#')
		{
			lst->tab[j][k] = line[i];
			k++;
			i++;
		}
		i = 0;

	}
}

int main(int argc, char **argv)
{
	char *line;
	int fd;

	if(!(fd = open(argv[1], O_RDONLY)))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	ft_stock(fd); 
}
