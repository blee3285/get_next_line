/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:06:02 by blee              #+#    #+#             */
/*   Updated: 2017/03/20 18:36:13 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpyto;
	unsigned char	*cpyfrom;

	i = 0;
	cpyto = (unsigned char *)dst;
	cpyfrom = (unsigned char *)src;
	while (i < n)
	{
		cpyto[i] = cpyfrom[i];
		if (cpyfrom[i] == (unsigned char)c)
		{
			i++;
			return (&cpyto[i]);
		}
		i++;
	}
	return (NULL);
}
