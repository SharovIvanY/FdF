/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 04:57:22 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/10 11:40:12 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if (size + 1 == 0)
		return (NULL);
	i = 0;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i <= size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
