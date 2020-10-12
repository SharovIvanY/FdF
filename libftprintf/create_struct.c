/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:04:39 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 14:13:18 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*ft_lstnew_ft_printf(void)
{
	t_print	*new;

	if (!(new = (t_print*)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->size = ft_strnew(2)))
		return (NULL);
	new->type = '\0';
	new->width = 0;
	new->flag_width = 0;
	new->accuracy = 0;
	new->flag_accuracy = 0;
	new->flag_minus = 0;
	new->flag_plus = 0;
	new->flag_null = 0;
	new->flag_space = 0;
	new->flag_sharp = 0;
	new->flag_otr_i = 0;
	new->sobaka = 0;
	return (new);
}
