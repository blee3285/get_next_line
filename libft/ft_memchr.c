/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:17:22 by blee              #+#    #+#             */
/*   Updated: 2017/03/08 18:48:18 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char thing;
	unsigned char *str;

	thing = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == thing)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
