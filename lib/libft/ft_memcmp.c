/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:30:17 by humarque          #+#    #+#             */
/*   Updated: 2018/11/12 17:15:01 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*sone;
	unsigned char		*stwo;
	size_t				i;

	i = 0;
	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	while (i < n)
	{
		if (sone[i] != stwo[i])
			return (sone[i] - stwo[i]);
		i++;
	}
	return (0);
}
