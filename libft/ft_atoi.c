/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:03:16 by blee              #+#    #+#             */
/*   Updated: 2017/03/05 15:06:32 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int idx;
	int neg;
	int num;

	idx = 0;
	neg = 1;
	num = 0;
	while ((str[idx] == ' ') || (str[idx] == '\t') || (str[idx] == '\n') ||
			(str[idx] == '\v') || (str[idx] == '\f') || (str[idx] == '\r'))
		idx++;
	if (str[idx] == '-')
		neg = -1;
	if ((str[idx] == '-') || (str[idx] == '+'))
		idx++;
	while ((str[idx] >= '0') && (str[idx] <= '9'))
	{
		num *= 10;
		num += (str[idx] - '0');
		idx++;
	}
	return (num * neg);
}
