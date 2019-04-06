/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printresult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:46:36 by humarque          #+#    #+#             */
/*   Updated: 2019/04/03 19:49:06 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
void	ft_printresult(char **tab, int len_array)
{
	int i;
	
	i = 0;
	while (i < len_array)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}	
}
