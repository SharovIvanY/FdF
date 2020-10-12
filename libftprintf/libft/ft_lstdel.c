/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:22:09 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/06 19:18:35 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*hoba;
	t_list	*obnul;

	if (!alst || !del)
		return ;
	hoba = *alst;
	while (hoba)
	{
		obnul = hoba->next;
		del(hoba->content, hoba->content_size);
		free(hoba);
		hoba = obnul;
	}
	*alst = NULL;
}
