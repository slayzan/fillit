/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:46:31 by humarque          #+#    #+#             */
/*   Updated: 2018/11/28 18:13:16 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		result(char *str, int i)
{
	int resultat;

	resultat = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = 10 * resultat + (str[i] - '0');
		i++;
	}
	return (resultat);
}

int				ft_atoi(char *str)
{
	int		i;
	int		neg;
	int		resultat;

	i = 0;
	neg = 1;
	resultat = 0;
	while (str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'
			|| str[i] == ' ')
	{
		i++;
	}
	if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	resultat = result(str, i);
	return (resultat * neg);
}
