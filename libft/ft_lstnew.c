/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:00:58 by blee              #+#    #+#             */
/*   Updated: 2017/03/20 22:51:07 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;
	void	*newcontent;

	if (!(newcontent = malloc(content_size + 1)))
		return (NULL);
	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newcontent = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(newcontent, content, content_size);
	newlist->content = newcontent;
	newlist->content_size = content_size;
	newlist->next = NULL;
	return (newlist);
}
