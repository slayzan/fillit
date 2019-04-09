/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:13:35 by humarque          #+#    #+#             */
/*   Updated: 2019/04/09 17:58:52 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *d;

	if (!(d = (void *)malloc(size)))
	{
		free(d);
		return (NULL);
	}
	ft_bzero(d, size);
	return (d);
}
