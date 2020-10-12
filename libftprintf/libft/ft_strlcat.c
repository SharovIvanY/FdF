/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:36:26 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/06 18:54:33 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t lenght)
{
	size_t	lenght_dest;
	size_t	lenght_src;
	size_t	i;

	lenght_dest = ft_strlen(dest);
	lenght_src = ft_strlen(src);
	i = 0;
	if (lenght <= lenght_dest)
		return (lenght_src + lenght);
	while (i < lenght - lenght_dest - 1 && i < lenght_src)
	{
		dest[lenght_dest + i] = src[i];
		i++;
	}
	dest[lenght_dest + i] = '\0';
	return (lenght_dest + lenght_src);
}
