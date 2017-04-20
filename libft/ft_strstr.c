/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:26:26 by blee              #+#    #+#             */
/*   Updated: 2017/03/22 14:48:08 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	if (!*little)
		return ((char*)big);
	while (*big)
	{
		i = 0;
		while (big[i] == little[i])
		{
			i++;
			if (!little[i])
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
