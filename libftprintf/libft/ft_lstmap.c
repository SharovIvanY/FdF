/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:02:50 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/10 11:41:25 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*hoba;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	hoba = f(lst);
	if (hoba == NULL)
	{
		free(hoba);
		return (NULL);
	}
	new = hoba;
	while (lst->next)
	{
		lst = lst->next;
		hoba->next = f(lst);
		if (hoba->next == NULL)
		{
			free(hoba->next);
			return (NULL);
		}
		hoba = hoba->next;
	}
	return (new);
}
