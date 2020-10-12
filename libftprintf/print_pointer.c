/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:18:01 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:15:31 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_flag_null_pointer(char *str, size_t len)
{
	char			*new_str;
	int				i;

	i = 0;
	new_str = ft_strnew(len);
	ft_memset(new_str, '0', len);
	new_str[1] = 'x';
	while ((int)ft_strlen(str) >= i + 2)
	{
		new_str[ft_strlen(new_str) - i] = str[ft_strlen(str) - i];
		i++;
	}
	free(str);
	return (new_str);
}

static char			*ft_hobacha(char *str, int width)
{
	char			*new_str;
	int				i;

	i = 0;
	new_str = ft_strnew((size_t)width);
	ft_memset(new_str, ' ', (size_t)width);
	while ((int)ft_strlen(str) > i)
	{
		new_str[ft_strlen(new_str) - 1 - i] = str[ft_strlen(str) - 1 - i];
		i++;
	}
	free(str);
	return (new_str);
}

static char			*ft_check_flags_pointer(char *str, t_print *new)
{
	char			*new_str;
	int				i;

	i = 0;
	if (new->flag_minus)
	{
		new_str = ft_strnew((size_t)new->width);
		ft_memset(new_str, ' ', (size_t)new->width);
		while (i < (int)ft_strlen(str))
		{
			new_str[i] = str[i];
			i++;
		}
		free(str);
		return (new_str);
	}
	else if (new->flag_null)
		return (ft_flag_null_pointer(str, (size_t)new->width));
	else
		return (ft_hobacha(str, new->width));
}

static int			ft_print_pointer_2(char *str, t_print *new)
{
	char			*new_str;
	int				num;
	char			*secret_str;

	if (((!(new->flag_width) || new->width <= (int)ft_strlen(str)) &&
			new->flag_accuracy && new->accuracy > (int)ft_strlen(str)) ||
			new->accuracy >= new->width)
	{
		new_str = ft_flag_null_pointer(str, (size_t)new->accuracy + 2);
		num = ft_strlen(new_str);
		ft_putstr(new_str);
		free(new_str);
	}
	else
	{
		new_str = ft_flag_null_pointer(str, (size_t)new->accuracy);
		secret_str = ft_check_flags_pointer(new_str, new);
		ft_putstr(secret_str);
		num = ft_strlen(secret_str);
		free(secret_str);
	}
	return (num);
}

int					ft_print_pointer(char *str, t_print *new)
{
	char			*new_str;
	int				num;

	if ((!(new->flag_accuracy) && !(new->flag_width)) ||
			(new->width <= (int)ft_strlen(str) &&
					new->accuracy <= (int)ft_strlen(str)))
	{
		num = ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	else if ((!(new->flag_accuracy) || new->accuracy <= (int)ft_strlen(str)) &&
				new->flag_width && new->width > (int)ft_strlen(str))
	{
		new_str = ft_check_flags_pointer(str, new);
		num = ft_strlen(new_str);
		ft_putstr(new_str);
		free(new_str);
	}
	else
		num = ft_print_pointer_2(str, new);
	return (num);
}
