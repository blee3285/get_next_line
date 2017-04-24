/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:49:17 by blee              #+#    #+#             */
/*   Updated: 2017/04/24 15:50:21 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		while ((ret = get_next_line(fd1, &line)) && i < 10)
		{
			ft_putnbr(ret);
			ft_putstr(": ");
			ft_putstr(line);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
