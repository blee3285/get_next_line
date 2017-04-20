/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:49:18 by blee              #+#    #+#             */
/*   Updated: 2017/03/14 17:27:56 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(&str[ft_strlen(s1)], s2);
	return (str);
}
