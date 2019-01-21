/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:01:49 by humarque          #+#    #+#             */
/*   Updated: 2018/11/28 16:48:47 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countsize(int n)
{
	int size;
	int save;

	save = n;
	size = 0;
	while (save > 9)
	{
		size++;
		save = save / 10;
	}
	return (size + 1);
}

static int		ft_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char			*value;
	size_t			i;
	int				size;
	int				neg;
	unsigned int	nb;

	neg = ft_negative(n);
	if (neg == 1)
		nb = n * -1;
	else
		nb = n;
	size = ft_countsize(nb);
	if (!(value = malloc(sizeof(char) * ((size + neg) + 1))))
		return (NULL);
	i = 0;
	while (nb > 9)
	{
		value[i++] = (nb % 10 + '0');
		nb = nb / 10;
	}
	value[i++] = nb + '0';
	if (neg == 1)
		value[i++] = '-';
	value[i] = '\0';
	return (ft_strrev(value));
}
