/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:12:51 by amace-ty          #+#    #+#             */
/*   Updated: 2019/01/25 14:47:18 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_gnl		*ft_lstnewgnl(void const *content, const int fd)
{
	t_gnl			*new;

	if ((new = (t_gnl*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	if ((new->content = malloc(sizeof(content))) == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, (size_t)sizeof(content));
	new->content_size = (size_t)sizeof(content);
	new->content_fd = fd;
	new->content_i = 0;
	return (new);
}

static t_gnl		*ft_check_fd(t_gnl **old, const int fd)
{
	t_gnl			*new;
	t_gnl			*tmp;

	new = *old;
	while (new)
	{
		if (new->content_fd == fd)
			return (new);
		new = new->next;
	}
	new = ft_lstnewgnl("\0", fd);
	tmp = *old;
	new->next = tmp;
	*old = new;
	new = *old;
	return (new);
}

static size_t		ft_strmyccpy(char **s1, const char *s2, int c, size_t point)
{
	size_t			i;
	size_t			k;
	char			*new;

	i = 0;
	k = 0;
	while ((s2[point + i] != (char)c) && s2[point + i])
		i++;
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s2[point + k] && k < i)
	{
		new[k] = s2[point + k];
		k++;
	}
	new[k] = '\0';
	*s1 = new;
	if (s2[point + k] == (char)c)
		i++;
	return (point + i);
}

static int			ft_treatment(int nbread, t_gnl *new, char **line)
{
	size_t			i;

	if (nbread < BUFF_SIZE && ((new->content_i) == ft_strlen(new->content)))
		return (0);
	i = ft_strmyccpy(line, new->content, '\n', new->content_i);
	if (i < ft_strlen(new->content))
		new->content_i = i;
	else
	{
		ft_strclr(new->content);
		new->content_i = 0;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_gnl	*start;
	int				nbread;
	t_gnl			*new;
	char			*tmp;

	if (fd == 1 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	new = ft_check_fd(&start, fd);
	while ((nbread = (int)read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[nbread] = '\0';
		MALLOCCHECKER((tmp = ft_strjoin(new->content, buff)));
		free(new->content);
		new->content = tmp;
		if (ft_strchr(new->content + new->content_i, '\n'))
			break ;
	}
	return (ft_treatment(nbread, new, line));
}
