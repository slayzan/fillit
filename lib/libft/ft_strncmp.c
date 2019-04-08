/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:26:37 by humarque          #+#    #+#             */
/*   Updated: 2018/11/30 17:27:29 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i])
			&& (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
