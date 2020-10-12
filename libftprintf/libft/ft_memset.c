/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:39:50 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/10 11:41:04 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t lenght)
{
	size_t			count;
	unsigned char	*str;

	count = 0;
	str = s;
	while (count < lenght)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
