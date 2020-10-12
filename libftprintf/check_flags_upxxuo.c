/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_uoxX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:58:06 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:09:47 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*check_flag_sharp(char *sstr, t_print *new)
{
	char		*new_str;
	char		*str;
	char		*temp;

	str = ft_strdup(sstr);
	if (new->type == 'o' && new->flag_sharp && (new->accuracy !=
				(int)ft_strlen(str) || !(new->accuracy)))
	{
		temp = "0";
		STRJOIN;
	}
	else if (new->type == 'x' && new->flag_sharp && (!(new->flag_width) &&
		(str[1] != 'x')))
	{
		temp = "0x";
		STRJOIN;
	}
	else if (new->type == 'X' && new->flag_sharp)
	{
		temp = "0X";
		STRJOIN;
	}
	return (str);
}

char			*ft_uinteger_minus(char *temp, t_print *new)
{
	char		*new_str;
	char		*str;
	int			i;

	str = ft_strdup(temp);
	i = -1;
	new_str = ft_strnew((size_t)new->width);
	ft_memset(new_str, ' ', (size_t)new->width);
	while (++i < (int)ft_strlen(str))
		new_str[i] = str[i];
	free(str);
	return (new_str);
}

char			*check_flags_width_two(char *str, t_print *new)
{
	char		*t;
	char		*t2;
	char		*new_str;

	t2 = ft_strjoin("0x", str);
	t = ft_strnew((size_t)(new->width - ft_strlen(t2)));
	if (new->width - ft_strlen(t2) > 0)
		ft_memset(t, ' ', (size_t)(new->width - ft_strlen(t2)));
	new_str = (new->flag_minus ? ft_strjoin(t2, t) : ft_strjoin(t, t2));
	free(t);
	free(t2);
	return (new_str);
}

char			*check_flags_width_three(char *str, t_print *new)
{
	char		*new_str;
	int			i;

	i = -1;
	new_str = ft_strnew((size_t)new->width);
	ft_memset(new_str, '0', (size_t)new->width);
	while ((int)ft_strlen(str) - ++i >= 0 && str[ft_strlen(str) - i] != 'x' &&
			str[ft_strlen(str) - i] != 'X' && str[ft_strlen(str) - i] != '0')
		new_str[ft_strlen(new_str) - i] = str[ft_strlen(str) - i];
	if (new->type == 'x' && new->flag_sharp)
	{
		new_str[0] = '0';
		new_str[1] = 'x';
	}
	else if (new->type == 'X' && new->flag_sharp)
	{
		new_str[0] = '0';
		new_str[1] = 'X';
	}
	return (new_str);
}

char			*check_flags_width(char *temp4, t_print *new)
{
	char		*new_str;
	char		*t;
	char		*str;

	str = ft_strdup(temp4);
	if (new->flag_minus)
	{
		if (new->type == 'x' && new->flag_sharp)
			STR_T;
		new_str = ft_uinteger_minus(str, new);
	}
	else if (new->flag_null)
		new_str = check_flags_width_three(str, new);
	else
	{
		t = ft_strnew((size_t)(new->width - ft_strlen(str)));
		ft_memset(t, ' ', (size_t)(new->width - ft_strlen(str)));
		new_str = ft_strjoin(t, str);
		free(t);
	}
	if (new->flag_sharp && new->type != 'o' && !new->flag_null)
		STR_T2;
	ft_strdel(&str);
	return (new_str);
}
