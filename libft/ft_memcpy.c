/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:16:14 by humarque          #+#    #+#             */
/*   Updated: 2018/11/16 17:39:35 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;
	size_t			i;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dest);
	while (n >= 1)
	{
		*dst = *sc;
		dst++;
		sc++;
		n--;
	}
	return (dest);
}
