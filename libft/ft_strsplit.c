/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:02:50 by blee              #+#    #+#             */
/*   Updated: 2017/03/14 17:25:17 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	notc_strlen(char const *str, char c)
{
	int i;

	i = 0;
	while ((str[i] != c) && str[i])
		i++;
	return (i);
}

static int	split_num(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c) && ((str[i + 1] == c) || (str[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

static char	*makeword(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = ((char *)malloc(sizeof(char) * (notc_strlen(str, c) + 1)));
	while ((str[i] != c) && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		arr;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	arr = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (split_num(s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i - 1] == c) || (i == 0)))
		{
			split[arr] = makeword(&s[i], c);
			arr++;
		}
		i++;
	}
	split[arr] = NULL;
	return (split);
}
