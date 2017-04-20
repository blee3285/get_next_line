/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:01:51 by blee              #+#    #+#             */
/*   Updated: 2017/03/20 19:17:24 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sort_int(int *tab, size_t size)
{
	size_t	i;
	int		loop;

	i = 0;
	loop = 1;
	while (loop)
	{
		loop = 0;
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				loop = 1;
			}
			i++;
		}
	}
	return (tab);
}
