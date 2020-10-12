/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_upxxuo2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:18:41 by jbashiri          #+#    #+#             */
/*   Updated: 2019/10/12 13:11:33 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_uinteger_accuracy(char *temp, t_print *new)
{
	int			i;
	char		*new_str;
	char		*dlc_str;
	char		*str;

	str = ft_strdup(temp);
	i = -1;
	dlc_str = ft_strnew((size_t)new->accuracy);
	ft_memset(dlc_str, '0', (size_t)new->accuracy);
	new_str = check_flag_sharp(dlc_str, new);
	free(dlc_str);
	while ((int)ft_strlen(str) - ++i >= 0 && str[ft_strlen(str) - i] != 'x' &&
			str[ft_strlen(str) - i] != 'X')
		new_str[ft_strlen(new_str) - i] = str[ft_strlen(str) - i];
	free(str);
	return (new_str);
}

int				check_snull_o(t_print *new)
{
	char		*str;

	if (!(new->flag_width) && new->type == 'o' && new->flag_sharp)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (new->flag_width && new->type == 'o' && new->flag_sharp)
	{
		str = ft_strnew((size_t)new->width);
		ft_memset(str, ' ', (size_t)new->width);
		if (new->flag_minus)
			str[0] = '0';
		else
			str[new->width - 1] = '0';
		ft_putstr(str);
		free(str);
		return (new->width);
	}
	return (0);
}

int				ft_sobachiy_null(t_print *new)
{
	char		*str;
	int			num;

	if (!(new->flag_width) && !(new->flag_accuracy))
	{
		write(1, "0", 1);
		return (1);
	}
	else if (!(new->flag_width) && new->flag_accuracy && new->accuracy == 0)
		return (check_snull_o(new));
	else if (new->flag_width && new->flag_accuracy && new->accuracy == 0)
	{
		num = check_snull_o(new);
		if (num == 0)
		{
			str = ft_strnew((size_t)new->width);
			ft_memset(str, ' ', (size_t)new->width);
			ft_putstr(str);
			free(str);
			return (new->width);
		}
		return (num);
	}
	ELSE;
}

static int		ft_uinteger_print_2(char *new_str, t_print *new)
{
	char		*super;
	char		*dlc_str;
	int			num;

	if ((!(new->flag_accuracy) || new->accuracy <= (int)ft_strlen(new_str)) &&
			new->width >= (int)ft_strlen(new_str))
	{
		dlc_str = check_flags_width(new_str, new);
		ft_putstr(dlc_str);
		num = ft_strlen(dlc_str);
		free(dlc_str);
	}
	else
	{
		super = ft_uinteger_accuracy(new_str, new);
		dlc_str = ft_strdup(super);
		free(super);
		super = check_flags_width(dlc_str, new);
		ft_putstr(super);
		num = ft_strlen(super);
		free(super);
		free(dlc_str);
	}
	return (num);
}

int				ft_uinteger_print(char *temp, t_print *new)
{
	int			num;
	char		*new_str;
	char		*dlc_str;
	char		*str;

	str = ft_strdup(temp);
	new_str = check_flag_sharp(str, new);
	if ((new->width <= (int)ft_strlen(new_str) &&
			new->accuracy <= ((int)ft_strlen(new_str) - new->flag_otr_i)))
	{
		ft_putstr(new_str);
		num = ft_strlen(new_str);
	}
	else if ((!(new->flag_width) && new->accuracy > ((int)ft_strlen(new_str) -
	new->flag_otr_i)) || (new->width <= new->accuracy))
	{
		dlc_str = ft_uinteger_accuracy(new_str, new);
		NUM;
	}
	else
		num = ft_uinteger_print_2(new_str, new);
	free(new_str);
	free(str);
	return (num);
}
