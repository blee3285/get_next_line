/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:50:09 by blee              #+#    #+#             */
/*   Updated: 2017/03/09 12:34:26 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sameobj(unsigned char *ptr1, unsigned char *ptr2, size_t len)
{
	if ((ptr2 > ptr1) && (ptr2 < (ptr1 + len)))
		return (1);
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*moveto;
	unsigned char	*movefrom;
	size_t			i;

	moveto = (unsigned char *)dst;
	movefrom = (unsigned char *)src;
	i = 0;
	if (sameobj(movefrom, moveto, len))
		while (len > 0)
		{
			moveto[len - 1] = movefrom[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			moveto[i] = movefrom[i];
			i++;
		}
	return (dst);
}
