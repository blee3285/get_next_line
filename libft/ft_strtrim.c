/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:45:01 by blee              #+#    #+#             */
/*   Updated: 2017/03/14 17:27:40 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipfront(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	return (i);
}

static int	skipback(char const *s)
{
	int i;

	i = ft_strlen(s);
	while ((s[i - 1] == ' ') || (s[i - 1] == '\t') || (s[i - 1] == '\n'))
		i--;
	if (i == 0)
		return (ft_strlen(s));
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	if (!s)
		return (NULL);
	start = skipfront(s);
	end = skipback(s);
	i = 0;
	if (!(trim = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start < end)
	{
		trim[i] = s[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
