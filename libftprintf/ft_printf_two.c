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

int				ft_check_accuracy(char *format, va_list ap, t_print *new)
{
	if (*format == '\0')
		return (0);
	if (*format == '*')
	{
		ft_check_accuracy_two(new, ap);
		return (1);
	}
	else
	{
		if (*format >= '0' && *format <= '9')
		{
			new->accuracy = ft_atoi(format);
			new->flag_accuracy = 1;
			return (ft_power(new->accuracy, 10));
		}
		else
		{
			new->flag_accuracy = 1;
			return (0);
		}
	}
}

int				ft_check_size(char *format, t_print *new)
{
	int			i;

	if (*format == '\0')
		return (0);
	i = 0;
	while (*format == 'h' || *format == 'l' ||
			*format == 'L' || *format == 'j' || *format == 'z')
		INT_PLUS;
	if (i > 2)
		return (i);
	else
	{
		format -= i;
		i = 0;
		while ((*format == 'h' || *format == 'l' ||
				*format == 'L' || *format == 'j' || *format == 'z'))
		{
			new->size[i] = *format;
			INT_PLUS;
		}
	}
	return (i);
}

int				ft_check_type(char *format, t_print *new)
{
	if (*format == '\0')
		return (0);
	if (*format == 'd' || *format == 'i' || *format == 'o' ||
			*format == 'x' || *format == 'X' || *format == 'u' ||
			*format == 'f' || *format == 's' || *format == 'c' ||
			*format == '%' || *format == 'Z' || *format == 'p' ||
			*format == 'C' || *format == 'S' || *format == 'O' ||
			*format == 'D' || *format == 'U')
	{
		new->type = *format;
		return (1);
	}
	return (0);
}

int				ft_while_tchk(t_print *new, char *str, int flag)
{
	int			x;

	x = 0;
	if (str[x] == '.' && flag)
	{
		new->accuracy = 0;
		new->flag_accuracy = 1;
	}
	while (str[x] == '.')
		x++;
	return (x);
}

int				ft_check_star(char *format, va_list ap, t_print *new)
{
	if (*format == '*')
	{
		new->flag_width = 1;
		new->width = va_arg(ap, int);
		if (new->width < 0)
		{
			new->width *= -1;
			new->flag_minus = 1;
		}
		return (1);
	}
	return (0);
}
