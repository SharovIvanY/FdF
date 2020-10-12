/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:20:22 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/05 17:42:36 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c,
								size_t lenght)
{
	unsigned char	*str;
	unsigned char	*hope;
	size_t			count;

	count = 0;
	str = (unsigned char*)dest;
	hope = (unsigned char*)src;
	while (count < lenght)
	{
		str[count] = hope[count];
		if (hope[count] == (unsigned char)c)
			return (str + count + 1);
		count++;
	}
	return (NULL);
}
