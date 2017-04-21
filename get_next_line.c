/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/20 22:14:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
		{
			*str = '\0';
			return (1);
		}
		str++;
	}
	return (0);
}

void	next_str(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	i++;
	if (str[i])
		ft_strcpy(str, &str[i]);
	else
		ft_bzero(str, BUFF_SIZE + 1);
}

int		check_buff(char *buff, char *line)
{
	if (*buff)
	{
		if (find_newline(buff))
		{
			ft_strcat(line, buff);
			next_str(buff);
			return (1);
		}
		ft_strcat(line, buff);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			reading;


	if (!*line)
		*line = ft_strnew(1);
	**line = 0;
	if (!buff)
		buff = ft_strnew(BUFF_SIZE + 1);
	if (check_buff(buff, *line))
		return (1);
	while ((reading = read(fd, buff, BUFF_SIZE)))
	{
		buff[reading] = '\0';
		if (find_newline(buff))
		{
			ft_strcat(*line, buff);
			next_str(buff);
			return (1);
		}
		else
		{
			ft_strcat(*line, buff);
			next_str(buff);
		}
	}
	if (**line)
		return (1);
	return (0);
}
