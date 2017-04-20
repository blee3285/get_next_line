/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:18:20 by blee              #+#    #+#             */
/*   Updated: 2017/03/17 18:56:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(map = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	map->content = lst->content;
	map->content_size = lst->content_size;
	map = (*f)(lst);
	temp = map;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = (*f)(lst);
		temp = temp->next;
	}
	return (map);
}
