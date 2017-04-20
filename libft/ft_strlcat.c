/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:21:31 by blee              #+#    #+#             */
/*   Updated: 2017/03/15 17:34:40 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_size(char *dst, size_t size)
{
	int i;

	i = 0;
	while ((size > 0) && dst[i])
	{
		i++;
		size--;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t di;
	size_t si;
	size_t dlen;

	di = strlen_size(dst, size);
	si = 0;
	size -= di;
	dlen = di;
	if (size == 0)
		return (dlen + ft_strlen(src));
	while (src[si])
	{
		if (size > 1)
		{
			dst[di] = src[si];
			di++;
			size--;
		}
		si++;
	}
	dst[di] = '\0';
	return (dlen + si);
}
