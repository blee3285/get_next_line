/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/22 19:09:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int		bigger_buff(char **str, int	size)
{
	char	*temp;

	temp = ft_strnew(size);
	if (!temp)
		return (1);
	temp = ft_strcpy(temp, *str);
	free(*str);
	*str = temp;
	return (0);
}

int		read_file(const int fd, char **str)
{
	int		size;
	int		ret;
	char	*buff;

	size = 1024;
	buff = ft_strnew(BUFF_SIZE + 1);
	*str = ft_strnew(size);
	if (!buff || !*str)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((ft_strlen(*str) + ret) > size)
		{
			while ((ft_strlen(*str) + ret) > size)
				size *= 2;
			if (bigger_buff(str, size))
				return (1);
		}
		ft_strcat(*str, buff);
	}
	return (0);
}

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
		if (!*str)
			return (1);
	}
	return (0);
}

void	next_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i++;
	if (str[i])
		ft_strcpy(str, &str[i]);
	else
		ft_bzero(str, 1024);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*hold[1024];

	if (fd < 0 || !line || BUFF_SIZE == 0 || fd >= 1024)
		return (-1);
	if (!hold[fd])
		if (read_file(fd, &hold[fd]))
			return (-1);
	if (find_newline(hold[fd]))
	{
		*line = ft_strdup(hold[fd]);
		next_str(hold[fd]);
		return (1);
	}
	ft_putstr(hold[fd]);
	return (0);
}
