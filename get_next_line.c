/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/19 19:23:31 by blee             ###   ########.fr       */
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
	static char	*buff;
	int		reading;
	
	ft_bzero(*line, ft_strlen(*line));
	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	while ((reading = read(fd, buff, BUFF_SIZE)))
	{
		buff[reading] = '\0';
		if (find_newline(buff))
		{
			ft_strcat(*line, buff);
			return (1);
		}
		else
			ft_strcat(*line, buff);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*line;
	int	fd1;
	//int	fd2;

	fd1 = open(av[1], O_RDONLY);
	//fd2 = open(av[2], O_RDONLY);
	line = (char*)malloc(sizeof(char) * 500);
	while (get_next_line(fd1, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
