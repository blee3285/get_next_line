/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/05/07 18:29:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_buffer(char **hold, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strjoin(*hold, str);
	free(*hold);
	*hold = temp;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		cut_newline(char **hold, char **line)
{
	int		i;
	char	*temp;

	temp = *hold;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			if (!(*line = ft_strnew(i + 1)))
				return (-1);
			ft_strncpy(*line, *hold, i);
			ft_strcpy(*hold, &temp[i + 1]);
			return (1);
		}
		i++;
	}
	if (!(*line = ft_strdup(*hold)))
		return (-1);
	ft_strclr(*hold);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*hold[4864];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd >= 4864 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!hold[fd])
		hold[fd] = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (add_buffer(&hold[fd], buff))
			return (cut_newline(&hold[fd], line));
	}
	if (*hold[fd])
		return (cut_newline(&hold[fd], line));
	return (0);
}
