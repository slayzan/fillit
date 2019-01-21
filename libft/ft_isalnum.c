/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:07:18 by humarque          #+#    #+#             */
/*   Updated: 2018/11/20 15:17:28 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int num;
	int alpha;

	num = ft_isdigit(c);
	alpha = ft_isalpha(c);
	if (num == 1 || alpha == 1)
		return (1);
	return (0);
}
