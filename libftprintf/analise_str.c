/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:40:38 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/05 15:40:45 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_string(va_list ap, t_print *new)
{
	char	*str;
	char	*new_str;
	int		num;

	str = va_arg(ap, char*);
	if (!str)
	{
		if (new->flag_null && new->flag_width)
		{
			new_str = ft_strnew(new->width);
			ft_memset(new_str, '0', new->width);
			ft_putstr(new_str);
			num = ft_strlen(new_str);
			free(new_str);
			return (num);
		}
		ft_putstr("(null)");
		return (6);
	}
	return (ft_print_string(str, new));
}
