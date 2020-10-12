/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 04:26:06 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/29 18:31:14 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*hoba;

	hoba = malloc(sizeof(char) * size);
	if (!hoba)
		return (NULL);
	ft_bzero(hoba, size);
	return (hoba);
}
