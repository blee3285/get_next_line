/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:15:29 by blee              #+#    #+#             */
/*   Updated: 2017/03/22 15:32:02 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *b, const char *l, size_t n)
{
	size_t	i;
	size_t	temp;
	size_t	src;

	if (!*l)
		return ((char*)b);
	i = 0;
	while (b[i] && (i < n))
	{
		temp = i;
		src = 0;
		while ((b[temp] == l[src]) && (temp < n))
		{
			temp++;
			src++;
			if (!l[src])
				return ((char*)(b + i));
		}
		i++;
	}
	return (NULL);
}
