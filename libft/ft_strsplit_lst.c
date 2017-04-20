/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:29:43 by blee              #+#    #+#             */
/*   Updated: 2017/03/20 20:12:00 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strsplit_lst(char *str, char c)
{
	t_list	*list;
	t_list	*temp;
	char	**split;
	int		i;

	if (!str || !c)
		return (NULL);
	i = 0;
	split = ft_strsplit(str, c);
	list = NULL;
	temp = list;
	while (split[i])
	{
		temp = ft_lstnew(split[i], (sizeof(char) * (ft_strlen(split[i]) + 1)));
		temp = temp->next;
		i++;
	}
	return (list);
}
