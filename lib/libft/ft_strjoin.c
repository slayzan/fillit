/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:27:35 by humarque          #+#    #+#             */
/*   Updated: 2019/04/16 15:29:33 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *newstring;
	int     i;
	int     j;
	int     k;
	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
		newstring[k++] = s1[i++];
	while (s2[j])
		newstring[k++] = s2[j++];
	newstring[k] = '\0';
	return (newstring);
}
