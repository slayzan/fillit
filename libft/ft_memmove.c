/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:05:51 by humarque          #+#    #+#             */
/*   Updated: 2018/11/30 15:51:52 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return ((unsigned char *)dest);
}
