/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:48:31 by humarque          #+#    #+#             */
/*   Updated: 2018/11/28 18:32:46 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlencat(char const *s1, char const *s2)
{
	int i;
	int resultat;

	i = 0;
	resultat = 0;
	while (s1[i])
	{
		resultat++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		i++;
		resultat++;
	}
	return (resultat);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlencat(s1, s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			str[i] = s2[j];
			j++;
			i++;
		}
		str[i] = '\0';
		return ((char *)str);
	}
	return (NULL);
}
