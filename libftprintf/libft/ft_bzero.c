/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:21:23 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 17:57:41 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t lenght)
{
	size_t			count;
	unsigned char	*str;

	str = s;
	count = 0;
	while (count < lenght)
	{
		str[count] = '\0';
		count++;
	}
}
