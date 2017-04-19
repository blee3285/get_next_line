/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:56:48 by blee              #+#    #+#             */
/*   Updated: 2017/04/18 17:46:49 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);
#endif
