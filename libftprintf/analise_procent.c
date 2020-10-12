/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analise_procent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:28:44 by jbashiri          #+#    #+#             */
/*   Updated: 2019/04/05 12:58:50 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_analise_procent(t_print *new)
{
	char	*str;
	char	*new_str;

	if (new->width > 0)
	{
		str = ft_strnew(new->width);
		ft_memset(str, ' ', new->width);
		str[new->width - 1] = '%';
		new_str = ft_check_char_flag_minus('%', str, new);
		ft_putstr(new_str);
		free(new_str);
		return (new->width);
	}
	ft_putstr("%");
	return (1);
}
