/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:12:44 by humarque          #+#    #+#             */
/*   Updated: 2019/04/02 13:10:00 by mchamayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TETRI_H
#define TETRI_H

typedef	struct s_tetri
{
	char	**shape;
	int		x;
	int		y;
	char	letter;
	struct	s_tetri *next;
	struct	s_tetri *prev;

} 				t_tetri;

#endif
