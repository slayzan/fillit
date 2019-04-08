/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:53:02 by humarque          #+#    #+#             */
/*   Updated: 2018/11/30 21:06:32 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_prime(int nb)
{
	int i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > 2147483647)
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int				ft_find_next_prime(int nb)
{
	if (ft_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
