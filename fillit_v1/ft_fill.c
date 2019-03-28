/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:43:19 by humarque          #+#    #+#             */
/*   Updated: 2019/03/28 14:08:49 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//verifie si le tetramino et plus grand que le carre

int		ft_fillboard(char ***tetrab, char **tab, int bloc, int len_array)
{
	int x;
	int y;
	int read;
	int save;

	x = 0;
	y = 0;
	save = 0;
	read = 0;
	while(read != 4);
	{
		while (tetrab[bloc][x][y])
		{
			if (tetrab[bloc][x][y] == '#')
			{
				read++;
				len++;
			}
			y++;
		}
		save = (save > len) ? len : save;
		y = 0;
		len = 0;
		x++;
	}
}
