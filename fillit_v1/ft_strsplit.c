/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamayo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:10:32 by mchamayo          #+#    #+#             */
/*   Updated: 2019/04/03 13:25:16 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	ft_countwords(char const *s, char c)
{
	int words;
	int i;

	words = 0;
	i = 0;
	if (s[0] == 0)
		return (0);
	if (s[i] != c)
		words++;
	i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_countletters(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i + 1);
}

char		**ft_strsplitlol(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb = ft_countwords(s, c);
	if (!(tab = malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (i < nb)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(tab[i] = malloc(sizeof(char) * ft_countletters(s, c))))
			return (NULL);
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
