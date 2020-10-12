/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:13:08 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/05 17:14:18 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *l;
	t_btree *r;
	t_btree *i;

	i = malloc(sizeof(t_btree));
	if (!i)
		return (0);
	i->item = item;
	l = NULL;
	r = NULL;
	i->left = l;
	i->right = r;
	return (i);
}
