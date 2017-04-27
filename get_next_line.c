/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:43:37 by blee              #+#    #+#             */
/*   Updated: 2017/04/27 15:12:01 by blee             ###   ########.fr       */
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
	char *temp;

	temp = ft_strjoin((*hold)->content, str);
	if (!temp)
		return (1);
	free((*hold)->content);
	(*hold)->content = temp;
	return (0);
}

char	*cut_newline(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			temp = ft_strnew(i + 1);
			ft_strncpy(temp, str, i);
			temp[i] = '\0';
			ft_strcpy(str, &str[i + 1]);
			return (temp);
		}
		i++;
	}
	temp = ft_strdup(str);
	ft_strdel(&str);
	return (temp);
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
		add_buffer(&temp, buff);
	}
	free(buff);
	if (*(char *)(temp->content))
	{
		*line = cut_newline(temp->content);
		return (1);
	}
	return (0);
}
