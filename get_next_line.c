/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/29 17:12:55 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_fd(t_list **hold, size_t fd)
{
	t_list	*temp;

	if (!hold)
		*hold = ft_lstnew(ft_strnew(1), fd);
	temp = *hold;
	while (temp)
	{
		if (temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	ft_lstadd(hold, ft_lstnew(ft_strnew(1), fd));
	return (*hold);
}

int		add_buffer(t_list **hold, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strjoin((*hold)->content, str);
	free((*hold)->content);
	(*hold)->content = temp;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		cut_newline(char *str, char **line)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*line = ft_strnew(i + 1);
			ft_strncat(*line, str, i);
			ft_strcpy(str, &str[i + 1]);
			return (1);
		}
		i++;
	}
	*line = ft_strdup(str);
	ft_strclr(str);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*hold;
	t_list			*temp;
	char			*buff;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	temp = find_fd(&hold, fd);
	buff = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ret == -1)
			return (-1);
		if (add_buffer(&temp, buff))
		{
			free(buff);
			return (cut_newline(temp->content, line));
		}
	}
	free(buff);
	if (*(char *)(temp->content))
		return (cut_newline(temp->content, line));
	ft_lstdelnode(&hold, &temp);
	return (0);
}
