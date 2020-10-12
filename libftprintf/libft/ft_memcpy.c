/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:36:53 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/06 18:58:18 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t lenght)
{
	const char	*hope;
	char		*str;
	size_t		count;

	if (!src && !dest)
		return (dest);
	hope = src;
	str = dest;
	count = 0;
	while (count < lenght)
	{
		str[count] = hope[count];
		count++;
	}
	return (dest);
}
