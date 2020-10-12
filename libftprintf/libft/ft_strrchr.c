/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:34:07 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 16:59:05 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *res;

	res = NULL;
	while (*str)
	{
		if (*str == (char)c)
			res = (char*)str;
		str++;
	}
	if (*str == (unsigned char)c)
		res = (char*)str;
	return (res);
}
