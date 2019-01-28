/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/01/28 15:01:39 by humarque         ###   ########.fr       */
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

t_node	*ft_read(int fd)
{
	int ret;
	t_node	*lst;
	static char temp[BUFF_SIZE + 1];

	temp = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, temp, BUFF_SIZE) == 21))
	{
		hfhfksdlhfkldshlfjklas
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
	ft_read(fd);
}
