/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:19:35 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/26 02:12:19 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			count;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	count = 0;
	while (count < n)
	{
		if (a[count] != b[count])
			return (a[count] - b[count]);
		count++;
	}
	return (0);
}
