/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:00:55 by amace-ty          #+#    #+#             */
/*   Updated: 2019/01/25 14:58:50 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1

# define MALLOCCHECKER(x) if (!x) return (-1);

typedef struct		s_gnl
{
	char			*content;
	size_t			content_size;
	int				content_fd;
	size_t			content_i;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(const int fd, char **line);

#endif
