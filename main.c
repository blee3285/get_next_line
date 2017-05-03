/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:49:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/03 14:19:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		i;
	int		ret;

	if (ac > 1)
	{
		fd1 = open(av[1], O_RDONLY);
		line = NULL;
		i = 0;
		while ((ret = get_next_line(fd1, &line)))
		{
			printf("%d: |%s|\n", ret, line);
			i++;
			free(line);
			if (ret == -1)
			{
				ft_putstr("error\n");
				return (0);
			}
		}
	}
	return (0);
}
