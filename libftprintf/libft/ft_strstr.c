/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:43:49 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 17:44:41 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
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
		while (s1[i])
		{
			j = 0;
			while (s2[j] == s1[i + j])
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
