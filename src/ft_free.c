/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:59:42 by humarque          #+#    #+#             */
/*   Updated: 2019/04/09 18:42:22 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_free_tab_str(t_tetri *str)
{
	int i;

	i = 0;
	while (i < 4)
		ft_memdel((void **)&str->shape[i++]);
	ft_memdel((void **)&str->shape);
}

void			ft_freelist(t_tetri **tetra, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_free_tab_str(tetra[i]);
		ft_memdel((void**)&tetra[i]->min);
		ft_memdel((void **)&tetra[i]->max);
		ft_memdel((void **)&tetra[i++]);
	}
	ft_memdel((void **)&tetra);
}
