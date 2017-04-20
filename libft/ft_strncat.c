/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:27:08 by blee              #+#    #+#             */
/*   Updated: 2017/03/09 12:44:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t di;
	size_t si;

	di = 0;
	si = 0;
	while (dest[di])
		di++;
	while (src[si] && (si < n))
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	dest[di] = '\0';
	return (dest);
}
