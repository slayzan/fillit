/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:51:19 by humarque          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/19 18:52:42 by humarque         ###   ########.fr       */
=======
/*   Updated: 2019/02/19 18:39:27 by mchamayo         ###   ########.fr       */
>>>>>>> 909457b0f8afb8d38ea14fe15a82b3ad3b6ee0a6
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printtab(char ***tab)
{
	int num;
	int x;
	int y;

	num = 0;
	x = 0;
<<<<<<< HEAD
	y = 0;
	while (tab[num][x] != 0)
=======

	while (tab[num][x])
>>>>>>> 909457b0f8afb8d38ea14fe15a82b3ad3b6ee0a6
	{
		while (tab[num][x][y] != '\0')
		{
			printf("%s", tab[num][x][y++]);
		}
		x++;
	}
}

