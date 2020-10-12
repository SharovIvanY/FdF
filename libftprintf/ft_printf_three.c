/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:09:03 by amace-ty          #+#    #+#             */
/*   Updated: 2019/03/11 18:28:17 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_three(char **format, t_print *new, va_list ap)
{
	*format += 1;
	*format += while_flags(*format, new);
	*format += ft_check_star(*format, ap, new);
	*format += while_flags(*format, new);
	*format += ft_check_width(*format, ap, new);
	*format += while_flags(*format, new);
	*format += ft_check_star(*format, ap, new);
	*format += while_flags(*format, new);
	if (*format[0] == '.')
	{
		*format += ft_while_tchk(new, *format, 0);
		*format += ft_check_accuracy(*format, ap, new);
		*format += ft_while_tchk(new, *format, 1);
	}
	*format += while_flags(*format, new);
	*format += ft_check_size(*format, new);
	*format += while_flags(*format, new);
}

int				ft_check_two(char *format, va_list ap)
{
	int			res1;
	int			res2;
	t_print		*new;

	res1 = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(new = ft_lstnew_ft_printf()))
				return (0);
			ft_check_three(&format, new, ap);
			if (ft_check_type(format, new))
			{
				res2 = res1;
				res1 += ft_analise(ap, res2, new);
				format++;
			}
			free(new->size);
			free(new);
		}
		INT_PLUS_TWO;
	}
	return (res1);
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			res;

	if (!(ft_check_one(format)))
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	va_start(ap, format);
	res = ft_check_two(format, ap);
	va_end(ap);
	return (res);
}
