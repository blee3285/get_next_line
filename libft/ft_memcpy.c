/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:33:41 by blee              #+#    #+#             */
/*   Updated: 2017/03/09 12:36:56 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*copyto;
	unsigned char	*copyfrom;

	i = 0;
	copyto = (unsigned char *)dst;
	copyfrom = (unsigned char *)src;
	while (i < n)
	{
		copyto[i] = copyfrom[i];
		i++;
	}
	return (dst);
}
