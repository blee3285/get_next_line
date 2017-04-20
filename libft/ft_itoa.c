/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:10:39 by blee              #+#    #+#             */
/*   Updated: 2017/03/20 19:24:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*num_too_big(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 12);
	ft_strcpy(str, "-2147483648");
	return (str);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (num_too_big());
	neg = -n;
	len = ft_numlen(n);
	if (n < 0)
		n = -n;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[len] = '0';
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[len] = '-';
	return (str);
}
