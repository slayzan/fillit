/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:25:09 by humarque          #+#    #+#             */
/*   Updated: 2018/11/30 16:34:42 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *save;
	t_list *res;
	t_list *rsd;

	if (lst && f)
	{
		save = f(lst);
		res = ft_lstnew(save->content, save->content_size);
		rsd = res;
		lst = lst->next;
		while (lst)
		{
			save = f(lst);
			res->next = ft_lstnew(save->content, save->content_size);
			res = res->next;
			lst = lst->next;
		}
		return (rsd);
	}
	return (NULL);
}
