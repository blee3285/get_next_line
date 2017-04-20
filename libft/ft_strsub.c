/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:06:49 by blee              #+#    #+#             */
/*   Updated: 2017/03/14 17:26:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (i < len)
	{
		if (!s[start])
			return (NULL);
		sub[i] = s[start];
		i++;
		start++;
	}
	return (sub);
}
