/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:24:47 by humarque          #+#    #+#             */
/*   Updated: 2018/11/29 14:47:25 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_findstart(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == ','
				|| s[i] == '\n' || s[i] == '\t') && (s[i]))
		i++;
	return (i);
}

static int			ft_findend(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == ','
				|| s[i] == '\n' || s[i] == '\t') && (i != 0))
		i--;
	return (i);
}

static char			*ft_strbuild(char const *s, int start, int end)
{
	int		i;
	char	*s1;

	i = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	while (start <= end)
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}

char				*ft_strtrim(char const *s)
{
	char		*str;
	int			start;
	int			end;
	int			i;
	int			len;

	if (s)
	{
		start = ft_findstart(s);
		end = ft_findend(s);
		len = ft_strlen(s);
		i = 0;
		if (start == len && end == 0)
			start = end + 1;
		i = len;
		if (!(str = (char *)malloc(sizeof(char) * ((end - start) + 2))))
			return (NULL);
		str = ft_strbuild(s, start, end);
		return (str);
	}
	return (NULL);
}
