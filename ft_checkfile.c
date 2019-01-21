/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:36 by humarque          #+#    #+#             */
/*   Updated: 2019/01/21 21:44:49 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

int	ft_checkline(char *str)
{
	int res;
	int i;

	while (str[i])
	{
		if (i > 5)
			return (-1);
		if(str[i] != '.' || str[i] != '#')
			return (-1);
		i++;
	}
	return (1);
}


int		ft_checkfile(t_struct *lst)
{
	int ret;
	int result;
	char buf[5];

	while (ret = read(lst->fd,buf, 6))
	{
		buf[ret] = '\0';
		lst->str = ft_strjoin(lst->str, (char const *)buf;
	}
	result = ft_checkline(lst->str);
	
}

int ft_findline(t_struct *lst)
{
	int res;
	int ret;
	char buf[1];
	
	res = 0;

	while(ret = read(lst->fd, buf, 1))
	{
		buf[ret] = '\0';
		lst->str = ft_strjoin(lst->str, (char const *)buf);
		if(!(ft_strchr(buf, '\n')))
			break;
	}
	
}
