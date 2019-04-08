/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:16:43 by humarque          #+#    #+#             */
/*   Updated: 2018/11/28 18:35:08 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*d;

	d = (char *)s;
	i = 0;
	if (s)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (d[i])
		{
			str[i] = (*f)(i, d[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
