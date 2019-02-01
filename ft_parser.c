/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/02/01 17:51:08 by humarque         ###   ########.fr       */
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
		if(i > 3)
			return (0);
		i++;
	}
	return (1);
}

t_verif	*ft_checknewline(char *line, t_verif lst)
{
	if(line[0] == '\0')
	{
		
	}

}

int main(int argc, char **argv)
{
	t_verif *liste;
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
		if (!(ft_checkline(line, count)))
			printf("0");
		if (!(ft_checknewline(line, liste)))
			printf("0");
	

	}
	printf("1");
}
