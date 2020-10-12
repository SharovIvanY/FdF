/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:21:34 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 18:23:17 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t lenght)
{
	char	*hoba;

	hoba = dest;
	while (*src && lenght)
	{
		*dest = *src;
		dest++;
		src++;
		lenght--;
	}
	while (lenght)
	{
		*dest = '\0';
		dest++;
		lenght--;
	}
	return (hoba);
}
