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

int				ft_check_one(char *str)
{
	if (ft_strchr(str, '%'))
		return (1);
	return (0);
}

int				else_while_flags(char format, t_print *new)
{
	if (format == '+')
	{
		new->flag_plus = 1;
		return (1);
	}
	else if (format == '0')
	{
		new->flag_null = 1;
		return (1);
	}
	else if (format == ' ')
	{
		new->flag_space = 1;
		return (1);
	}
	else if (format == '#')
	{
		new->flag_sharp = 1;
		return (1);
	}
	return (0);
}

int				while_flags(char *format, t_print *new)
{
	int			res;

	if (*format == '\0')
		return (0);
	res = 0;
	while (*format == '-' || *format == '+' || *format == '0' ||
		*format == ' ' || *format == '#')
	{
		if (*format == '-')
		{
			new->flag_minus = 1;
			res++;
		}
		res += else_while_flags(*format, new);
		format++;
	}
	return (res);
}

int				ft_check_width(char *format, va_list ap, t_print *new)
{
	if (*format == '\0')
		return (0);
	if ((*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format == '*')
		{
			new->width = va_arg(ap, int);
			if (new->width < 0)
			{
				new->flag_minus = 1;
				new->width = new->width * -1;
			}
			new->flag_width = 1;
			return (1);
		}
		else
		{
			new->width = ft_atoi(format);
			new->flag_width = 1;
			return (ft_power(new->width, 10));
		}
	}
	return (0);
}

void			ft_check_accuracy_two(t_print *new, va_list ap)
{
	new->accuracy = va_arg(ap, int);
	if (new->accuracy < 0)
	{
		new->accuracy = 0;
		new->flag_accuracy = 0;
	}
	else
		new->flag_accuracy = 1;
}
