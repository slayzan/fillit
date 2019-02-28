/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:20:56 by humarque          #+#    #+#             */
/*   Updated: 2019/02/28 18:32:07 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_malloc_array(int bloc)
{
	int 	len_array;
	char	**solve;
	int		i;

	i = 0;
	len_array = sqrt(bloc * 4) + 1;
	if (!(solve = (char *)malloc(sizeof(char *) * len_array)))
	{
		free(solve);
		return (0);
	}
	if (!(solve = (char **)malloc(sizeof(char **) * len_array)))
	{
		free(solve);
		return (0);
	}
	printf("sqrt = %d\n", len_array);
	return (solve);
	
}

int ft_tetracking(char ***tab, int bloc)
{
	tab = 0;
	ft_malloc_array(bloc);
	return (0);
}
