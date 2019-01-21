/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:32:47 by humarque          #+#    #+#             */
/*   Updated: 2018/11/15 15:34:25 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int neg;

	neg = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == (-2147483648))
		{
			ft_putchar_fd('2', fd);
			ft_putchar_fd('1', fd);
			return (ft_putnbr_fd(47483648, fd));
		}
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd(nb % 10 + '0', fd);
}
