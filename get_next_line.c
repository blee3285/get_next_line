/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/18 18:49:08 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			*str = '\0';
			return (1);
		}
		str++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	*buff;
	int		reading;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	while (reading = read(fd, buff, BUFF_SIZE))
	{
		buff[reading] = '\0';
		if (find_newline)
		{
			ft_strcat(*line, buff);
			return (1);
		}
		else
			ft_strcat(*line, buff);
	}
	return (0);
}
