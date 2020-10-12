/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:10:29 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 17:44:35 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t lenght)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*s1 && !*s2)
		return ((char*)s1);
	if (*s1)
	{
		if (!*s2)
			return ((char*)s1);
		while (s1[i] && i < lenght)
		{
			j = 0;
			while (s2[j] == s1[i + j] && (i + j) < lenght)
			{
				if (!s2[j + 1])
					return ((char*)(s1 + i));
				j++;
			}
			i++;
		}
	}
	return (0);
}
