/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmovereloaded.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:27:20 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/06 18:56:37 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_analys(const char *s1, char *s2)
{
	if (s1 > s2)
		return (0);
	else
		return (s1 - s2);
}

void				*ft_memmove(void *dest, const void *src,
								size_t lenght)
{
	char			*str;
	const char		*hope;
	size_t			count;

	if (src == dest)
		return (dest);
	count = 0;
	str = dest;
	hope = src;
	if (ft_analys(hope, str))
	{
		while (lenght)
		{
			str[lenght - 1] = hope[lenght - 1];
			lenght--;
		}
	}
	else
		while (count < lenght)
		{
			str[count] = hope[count];
			count++;
		}
	return (dest);
}
