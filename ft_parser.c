/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/01/24 19:26:24 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

int		ft_checkline(char *line)
{
	int i;

	i = 0;
	while (line[i] == '.' || line[i] == '#')
	{
		if (line[i] != '.' || line[i] != '#')
			return (0);
		if (i > 4)
			return (0);
	}
}


t_node	*ft_stock(const int fd)
{	
	char *line;
	t_node *lst;
	
	while (get_next_line(fd, &line) == 1)
	{
		while (ret = read(fd, line, 16))
		{
			ft_checkline(line);
		}	
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
