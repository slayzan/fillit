/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:20:56 by humarque          #+#    #+#             */
/*   Updated: 2019/02/28 14:05:05 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_malloc_array(int bloc)
{
	int len_array;
	
	len_array = sqrt(bloc * 4) + 1;
	printf("sqrt = %d\n", len_array);
	return (len_array);
}

int ft_tetracking(char ***tab, int bloc)
{
	tab = 0;
	ft_malloc_array(bloc);
	return (0);
}
