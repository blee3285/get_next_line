/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:24:09 by blee              #+#    #+#             */
/*   Updated: 2017/03/17 19:13:38 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !del)
		return ;
	temp = *alst;
	while (temp)
	{
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = temp->next;
	}
	*alst = NULL;
}
