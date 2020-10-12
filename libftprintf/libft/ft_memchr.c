/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:52:30 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/26 02:11:52 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*hope;
	size_t			count;

	count = 0;
	hope = (unsigned char*)s;
	while (count < n)
	{
		if (hope[count] == (unsigned char)c)
			return (hope + count);
		count++;
	}
	return (NULL);
}
