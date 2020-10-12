/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:09:20 by amace-ty          #+#    #+#             */
/*   Updated: 2019/04/03 19:00:40 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_analise_three(va_list ap, t_print *new, char c)
{
	if (c == 'Z')
		return (ft_analise_z(new));
	else if (c == 'u')
	{
		if (new->size[0] == 'h')
		{
			if (new->size[1] == 'h')
				return (ft_hh_uinteger(ap, new));
			else
				return (ft_h_uinteger(ap, new));
		}
		else if (new->size[0] == 'l')
		{
			if (new->size[1] == 'l')
				return (ft_ll_uinteger(ap, new));
			else
				return (ft_l_uinteger(ap, new));
		}
		else
			return (ft_uinteger(ap, new));
	}
	else if (c == 'c')
		return (ft_analise_simvol(ap, new));
	return (-100);
}

static int		ft_analise_four(va_list ap, t_print *new, char c, int res)
{
	if (c == 'o')
	{
		if (new->size[0] == 'h')
		{
			if (new->size[1] == 'h')
				return (ft_hh_octal(ap, new));
			else
				return (ft_h_octal(ap, new));
		}
		else if (new->size[0] == 'l')
		{
			if (new->size[1] == 'l')
				return (ft_ll_octal(ap, new));
			else
				return (ft_l_octal(ap, new));
		}
		else
			return (ft_octal(ap, new));
	}
	else if (c == 'p')
		return (ft_analise_pointer(ap, new));
	else if (c == 'n')
		return (ft_analise_n(ap, res));
	return (-100);
}

static int		ft_analise_five(va_list ap, t_print *new, char c)
{
	if (c == 'x')
	{
		if (new->size[0] == 'h')
		{
			if (new->size[1] == 'h')
				return (ft_hh_x(ap, new));
			else
				return (ft_h_x(ap, new));
		}
		else if (new->size[0] == 'l')
		{
			if (new->size[1] == 'l')
				return (ft_ll_x(ap, new));
			else
				return (ft_l_x(ap, new));
		}
		else
			return (ft_x(ap, new));
	}
	else if (c == '%')
		return (ft_analise_procent(new));
	else if (c == '\0')
		return (0);
	return (-100);
}

static int		ft_analise_six(va_list ap, t_print *new, char c)
{
	if (c == 'X')
	{
		if (new->size[0] == 'h')
		{
			if (new->size[1] == 'h')
				return (ft_hh_upx(ap, new));
			else
				return (ft_h_upx(ap, new));
		}
		else if (new->size[0] == 'l')
		{
			if (new->size[1] == 'l')
				return (ft_ll_upx(ap, new));
			else
				return (ft_l_upx(ap, new));
		}
		else
			return (ft_upx(ap, new));
	}
	else if (c == 's')
		return (ft_string(ap, new));
	return (-100);
}

int				ft_analise(va_list ap, int res, t_print *new)
{
	char		c;
	int			result;

	c = new->type;
	if ((result = ft_analise_two(ap, new, c)) >= 0)
		return (result);
	if ((result = ft_analise_three(ap, new, c)) >= 0)
		return (result);
	if ((result = ft_analise_four(ap, new, c, res)) >= 0)
		return (result);
	if ((result = ft_analise_five(ap, new, c)) >= 0)
		return (result);
	if ((result = ft_analise_six(ap, new, c)) >= 0)
		return (result);
	else if (c == 'f')
	{
		if (new->size[0] != 'L')
			return (ft_analise_float(ap, new));
		else
			return (ft_bl_analise_float(ap, new));
	}
	return (0);
}
